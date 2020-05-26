#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "getopt.h"

using namespace std;

int main(int argc, char* argv[]) {

	const int num = 5;
	const char* args = ":hs:a::v:i";
	const struct option args_long[] = {
		{"help", no_argument, 0, 'h'},
		{"size", required_argument, 0, 's'},
		{"all", optional_argument, 0, 'a'},
		{"version", required_argument, 0, 'v'},
		{"info", no_argument, 0, 'i'},
		{ 0, 0, 0, 0 }
	};

	int index;
	
	bool htrue = false;
	bool strue = false;
	bool atrue = false;
	bool vtrue = false;
	bool itrue = false;
	int c;

	
	while ((c = getopt_long(argc, argv, args, args_long, &index)) != -1)
	{
		switch (c) {
		    
		//help - no argument
		case 'h': {
			if (htrue == false)
			{
				printf("calling help\n");
				htrue = true;
			}
			break;
		};
		
		//info - no argument
		case 'i': {
			if (itrue == false)
			{
				printf("calling info\n");
				itrue = true;
			}
			break;
		};
		
		//size - required argument
		case 's': {
			if (strue == false)
			{
				if ((optarg[0] < '0') || (optarg[0] > '9'))
				{
					printf("required argument for --size\n");
					break;
				}
				else
				{
					printf("calling size = %s\n", optarg);
					strue = true;
				}
			}
			break;
		};

        //version - required argument
		case 'v': {
			if (vtrue == false)
			{
				if ((optarg[0] < '0') || (optarg[0] > '9'))
				{
					printf("required argument for --version\n");
					break;
				}
				else
				{
					printf("calling version = %s\n", optarg);
					vtrue = true;
				}
			}
			break;
		};

        //all - optional argument
		case 'a': {
			if (atrue == false)
			{
				if (optarg == NULL)
				{
					printf("calling all\n");
					atrue = true;
				}
				else
				{
					printf("calling all = %s\n", optarg);
					atrue = true;
				}
			}
			break;
		};

		case '?': {
			printf("option not known %c\n", optopt);
			break;
		}

		case ':': {
			printf("required argument %c\n", optopt);
			break;
		}
		};
	};
	return 0;
};
