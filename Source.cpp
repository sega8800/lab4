
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100

using namespace std;

class book 

{
protected:
	char name[40];
	char author[40];
public:
	book(char *, char *);
	book() {

	};
	~book() {};
	void see();
	void setName(char *s1); 
	void setAuthor(char *s2);
};


class section : public book
{
	char sect[40];
public:
	section(char *, char *, char *);
	section() {};
	~section() {};
	void see();
};


book::book(char *s1, char *s2)


{

	strcpy_s(name, s1);
	strcpy_s(author, s2);
}

void book::see()

{
	setlocale(LC_ALL, "rus");
	cout << "�������� : " << name << "\n�����: " << author;
}

section::section(char *s1, char *s2, char *s3) : book(s1, s2) 
{
	strcpy_s(sect, s3);
	
}


void section::see()
{
	setlocale(LC_ALL, "rus");
	cout << "�������� �����: " << name << endl; 
	
		cout << "����� �����: " << author << endl; 
		cout<<"�����: "<<sect<<endl; 
}

int main()
{
	setlocale(LC_ALL, "rus");
	int choice, num = 0, j;
	char name[10];
	char author[10];
	char sect[10];
	section s[N];
	while (choice = 3) {

		cout << "\n������� 1 ��� ���������� �����" << endl;  
		cout<<"������� 2 ��� �� ������� �����"<<endl;
		cout << "������� 3 ��� �� �����" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "������� �������� ����� " << endl;
			cin >> name;
			cout << "������� ������ ����� " << endl;
			cin >> author;
			cout << "������� �����" << endl;
			cin >> sect;
			section s1(name, author, sect); 
			s[num]=s1;
			num++;
		}

		else if (choice == 2) {
			cout << "������� �����, ������� ������ ������� (������	��� " << num << " )" << endl;
			cin >> j;
			if (j >= num)
				cout << "������������ ��������" << endl;
			else
			{
				num--;
				for (int i = j; i < num; i++) { 
					s[i]=s[i+1];
				}

			}

		}
		if (choice == 3)
			break;
		else if (choice != 1 && choice != 2 && choice != 3) 
			cout << "������������ ��������" << endl;
		for (int i = 0; i < num; i++) {
			s[i].see(); 
		}

	}
}