#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

struct student
{
	char str[BUFSIZ];
	
};
//char *strcpy(char *destination, const char*source);
void recInFile(struct student *str, int i);
void read(struct student *str, int i);
void readFile(struct student *str, int i);
void read(struct student *str, int i)
{
	for (int j = 0; j < i; j++)
	{
		printf("Ââåäiòü ðÿäîê \n");
		scanf("%s", &str[j].str);
		puts("");
	}
}
void recInFile(struct student *str, int i)
{

	FILE *fp;
	if ((fp = fopen("struct.txt", "wb")) == NULL)
	{
		puts("ERROR!");
		exit(1);
	}

	for (int j = 0; j < i; j++)
	{
		fwrite(str++, sizeof(str), 1, fp);
	}
	fclose(fp);
	system("cls");
}

void readFile(struct student *str, int i)
{

	FILE *fp;
	if ((fp = fopen("struct.txt", "rb")) == NULL)
	{
		puts("ERROR!");
		exit(1);
	}


	for (int j = 0; j < i; j++){
		fread(str + j, sizeof(*str), 1, fp);

	}
	/*fclose(fp);*/
	for (int n = 0; n < i; n++){
		printf(" %s\n", str[n].str);
	}
	while (!feof(fp))

		fclose(fp);
	}



int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ukr");
	struct student * str;
	str = (struct student *)malloc(sizeof(struct student));
	read(str, 1); // ôóíêö³ÿ ³í³ö³àë³çàö³¿ ìàñèâó
	min_max(str, 1);
	recInFile(str, 1);
	readFile(str, 1);
	getchar();
	return 0;
}