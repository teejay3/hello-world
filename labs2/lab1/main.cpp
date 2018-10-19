#include "myRect.h"
#include "myString.h"
#include <iostream>
#include <cstdarg>
#include <cstddef>

MyString Concatenate(const char* st1, ...)
{
	size_t count = 0;

	va_list p;
	va_start(p, st1);
	const char* tmp = st1;
	while (*tmp != '!')
	{
		while (*tmp != '\0')
		{
			count++;
			tmp++;
		}
		tmp = va_arg(p, const char*);
	} 
	std::cout << "\nargument count = " << count << '\n';
	
	char* result = new char[count + 1];
	char* r = result;

	va_start(p, st1);
	tmp = st1;
	while (*tmp != '!')
	{
		while (*tmp != '\0')
		{
			*r = *tmp;
			tmp++;
			r++;
		}
		tmp = va_arg(p, const char*);
	}
	//r++;
	*r = '\0';
	MyString res(result);
	delete[] result;
	return res;
}

Rect BoundingRect(Rect r1, Rect r2)
{
	Coord tr1 = r1.GetAll();
	Coord tr2 = r2.GetAll();
	Rect res(tr1.x1, tr1.y1, tr2.x2, tr2.y2);
	return res;
}

Rect BoundingRect2(const Rect& r1, const Rect& r2)
{
	Coord tr1 = r1.GetAll();
	Coord tr2 = r2.GetAll();
	int t, b, l, r;
	if (tr1.x1 < tr2.x1) l = tr1.x1; else l = tr2.x1;
	if (tr2.x2 < tr2.x2) r = tr2.x2; else r = tr1.x1;
	if (tr1.y1 < tr2.y1) b = tr1.y1; else b = tr2.y1;
	if (tr1.y2 < tr2.y2) t = tr2.y2; else t = tr1.y2;
	return Rect (l, r, t, b);
}

class Bochka
{
private:
	double volume;
	char* type;
	double concentration;
public:
	double Con() { return concentration; }
	Bochka(double vol, double conc, char* typ) :volume(vol), type(typ), concentration(conc) {};
//	~Bochka() {}
	void Pereliv(Bochka& from)
	{
		this->concentration = (this->concentration * this->volume + 1 * from.concentration) / (1 + this->volume);
		this->volume += 1;
		from.volume -= 1;
	}
};

#define	stop __asm nop

int main()
{
using namespace std;

	//������� 1.���������� ������. �������� ���������� ������.
	//����� ������� ������. 
	//�������� �������� Class View - (����� �� ������� ����� ������� �
	//������ - ������� Rect � MyString)
	//�������� �������� �� ����������� ����� �� ���� ������ ������ - ���
	//���������� ������������ ������� � ������� ����� ������.

	//����� ����������� ���������� ��� �������� ���������� ������? �� ���������
/*	{
*		Rect rect{};	--�� ��������� ��� ����������
*		MyString str{};	--�� ��������� ��� ����������
*		stop
*	}
*/
	//1a. �������� � ���������� ����������� � ����������� ���
	//������������� ���������� ������. �������� ��������� ������ Rect
	//� ������� ������������ � �����������. ���� ���������� ������
	//������ � ���������� ���������, ��������� - ���� ��� ��
	//�������? ��������� ���������� ������.
	//�������� ������� � ������ ������ �� �����, ����������:
	//� ����� ������ ���������� ����� ������������(������?)?
/*	
*	{
*	Rect rect2( 5, 5, 1, 1 );
*		stop
*	}
*/
	//1�. ��� ��������������� ������� ����������� ������������ ��� ����������
	//������������� ������������� ���������� ������, ��������, �����
/*
*{
*	MyString str2;
*	const char* ptr = str2.print();
*	std::cout << *ptr << std::endl;
*	char c;
*	std::cin >> c;
*}
*/
	//1�. ���������, ��� ������� ��������� � ������, ����� ������������ �����
	//���������� ��������� �������:

	//Rect rrr(4,3,2,1);
	
//stop
//1�. ��������, ���������� � �������� ����� ������ InflateRect(), 
//������� ����������� ������� �������������� �� �������� ����������
//(��������� ������� �� ������ - ������ ������� �� ���� ��������).
//���������: �������� � ���������� ������ ����� �� ������ "�������",
//�� � � ������� Wizard-a Class View. ��� �����: �������� ��������
//ClassView ���� �������, �������� �������� ����� Rect � �������
//������ ������ ���� - � ����������� ����������� ���� ��������
//Add/Add Member Function... � ������� ����������� ���������� ������
//"����� ��������" Wizard-� ��� �������� � ���������� �����.
/*
*	{
*	Rect rect{};
*	rect.InflateRect(5, 2);
*	stop
*}
*/

//������� 2.���������� ������������� � ������� ������.
//����������� �����������.

//2�.�������� � ���������� ����������� ����������� � ������ Rect.
//�������� ������� �� �����, ����������, �����
//����������� ���������� ��� �������� r1,r2,r3 � r4?
//���� ����� ���������� ��������� ��������?
/*
		Rect r1;
		Rect r2(1,2,3,4);
		Rect r3 = r1;
		Rect r4(r2);
		stop


//2�. �������� � ���������� � ������ Rect ����� InflateRect(),
  //������� ��������� ��� ���������, �� ��������� ������ 1, � 
  //���������� ������� �������������� �� �������� ����������.
  //��� ����� �������� ���������� ������� InflateRect()?

		r1.InflateRect(1,1);
		r2.InflateRect(2,2);
	//����� �� ������� InflateRect() ���������� � ������ �� ���� �������?
		r3.InflateRect(2,2,2,2);
		r3.InflateRect(3,3);
		r3.InflateRect(5);	//��� �-� � 2-�� �����������, � ������� ���� �������� = 5, � ������ �� ���������
		r3.InflateRect();	//� ������� ��� ��������� �� ���������
	stop
*/

//������� 3.������������� �������. ������������. 
/*
*{
*	Rect r;
*	//���������������� ��������� ������. ��������� ������
*	//�����������
*
//	int tmp = r.m_left;	������� ������� � ��������� ����� ������
*
*
*
*	//������� � ����� Rect ����� void SetAll(...),
*	//������� ����������� ���������� ������ ������������
*	//��������. �������� ��������� �����, ��������� ������������.
*		{
*			r.SetAll(1, 2, 3, 4);
*		}
*
*	//������� � ����� Rect ������ ����� GetAll(...),
*	//������� "�������" �������� private-���������� ������.
*	//�������� ��������� �����, ��������� ������������.
*		r.GetAll();
*	stop
*	}
*/

//������� 4.�������� ���������� ������ � �������� ���������
//�������. ����������� ������� ������ �� ��������. ��������
//�������� � ������������ ����������� ��� �������� ��������
//�� �����, ����������: � ����� ������ ���������� ���������
//� ������������ �����������. 
//�������� ���������� ������� 
// Rect BoundingRect(Rect, Rect);
//������� ��������� ��� ������� ������ Rect �� �������� �
//���������� ������ ������ Rect, ������� �������� ���������������,
//� ������� ������� �������� ��������������. ��� ����������
//�������� ���������� � ����������� ������� ������?

	//���������*: ������ ���� �� ������ ��� ����, ��� �������������
	//����� ��������� "�����������������", �� ���� m_left>m_right ���/�
	//m_top>m_bottom
/*
	{

		Rect r1(1,2,3,4), r2(5,6,7,8),r3; // ��� 4-� �������� ������������ � ���� ������
	r3= BoundingRect(r1, r2);	//������������ �����������
	stop

	//������� 4�. �������� �������� �� ������.
	//�������� ���������� ������� BoundingRect2, ������� ��������� �� ��
	//������, �������� ��������� �� ������
	//���������� �� ������������ ��� �������� ����������?

		r3 = BoundingRect2(r1, r2);
	stop
	}
*/

	//������� 5. ��������� �� �����. �������� � ����������
	//����� ���������� ������. ��������� �������� � 
	//������������ (�������������) � �����������. ����������: ����� ���
	//������� �� �������� ���������� �����������, � ����� - ����������?
/*
	{
		Rect r1;
		Rect*	pR = new Rect(1,2,1,2);	
		{
			Rect r2(r1);
			Rect arRect[2];
			for(int i=0; i<3; i++)
			{
				static Rect r3 (i,i,i,i) ;
				Rect r4(*pR);
				Rect r5(i,i,i,i);
			}
		}
		delete pR;	
		stop
	}
*/
 
	//������� 6.����������� + ���������� = ��������������
	// ���������. ����� MyString
	// ����������� ������������ (�������������) � ����������� ����������
	//���������� ������������� � ����������� �������
	//C ������� ��������� ���������� ����� ����������
	//������ � ������������ ������ ��� ������-����� ������
/*
	{
		MyString	str("It's my string!");
		std::cout << str.len() << std::endl;

		//�������� ����� GetString(), ������� ��������� ������ � ���������� ������.
		//� ������� cout � ������ GetString() ������������ ������ ������� str
		//���������: ���������, ��� ������� ��������� ����������� ����� GetString().
		std::cout << str.print() << std::endl;
		str.GetString();
		//...
	}

	stop
*/

	//6a. ���������������� ��������� ��������. ��������� - �����
	//������������ ��� �������. ���������� ��������� ��������� (���?)
/*		{
			MyString str1("The first string!");
			MyString str2 = str1;
			str2.GetString();
			MyString str3("3335555555555555555555555555555");
			str2 = str3;
			str2.GetString();
		}
		stop
*/
	//6�. ���������� ����� SetNewString, ������� ����� �������� ������
	// �� �����
/*
{
	MyString str("old string");
	str.SetNewString("new string11111");
	str.GetString();
}
*/

	//6�. �������� ���������� �������, ������� ����� ��������� �����
	//���������� ���������� �� ������, � ���������� ������ MyString,
	//� ������� ������ ����� ������������� ����������

	MyString s1("hello ");
	MyString s2("world");
	MyString str = Concatenate(s1.print(), s2.print(), "!"); //�� ��������!!!
	str.PrintString();


	//������� 7.������ �������� ������.
/*
{
	//�������� � ������������������ ������ ar �� ��������
	// ���� MyString. ��������:
	//��� ������ �����������? N=3
	const std::size_t N = 5;
	MyString arstr[N] = { MyString("str1"),MyString("str2"),MyString("str3") };

	//�������� - ������ �����-������ ������

	for (std::size_t i = 0; i < N; i++)
		arstr[i].GetString();
	char c;
	std::cin >> c;

	//��������� ������ �������, �� ������� ������ ���������������:
	//N=5???



	//�������� � ������������������ ������ ��������	���� Rect.
	
	const std::size_t M = 2;
	Rect arrect[M] = { {},{} };

	}
	stop
*/

	//������� 8.������ ���������� �� ������� ������.
/*
	{
	//�������� � ������������������ ������ arPtr �� ���� 
	//���������� �� ������� ���� MyString.
	std::size_t M = 3;
	MyString* arPtr[5] = { new MyString("sdfsdf"),new MyString(), new MyString() };// new MyString*[M];
	/*for (std::size_t i = 0; i < M; i++)
		arPtr[i] = new MyString{ "new string "};*/
/*
	//������ �����-������ ������
	for (std::size_t i = 0; i < M; i++)
	{
		if (arPtr[i] != nullptr)
		{
			arPtr[i]->PrintString();
			delete arPtr[i];
		}
	}
  
	}
	stop

*/
	//������� 9.  ������ � ������� ������� ��������� ������:
	//���� ��� ����� ���������� ������. � ����� ����� � ��������� ������
	//������� ���������� ����� (96%), � ������ � ����.
	//������� �������� 1� ���������� ���������� ���������� �� ����� �����
	//� ������ ��������� ��������: �� ������ ��������
	//���������� �� ������ ����� -> ������ �� ������
	//���������� �� ������ ����� -> ������ � ������.
	//��������� ���������� ����� ��������, �� ������� ������������ ������ �
	//������ ����� ������ ������ 50%.
/*
	Bochka spirt(100, 96, "spirt");
	Bochka water(100, 0, "water");
	std::size_t count = 0;
	while(spirt.Con() > 50)
		{
			spirt.Pereliv(water); //��� spirt.Pereliv(water, �����_������);
			std::cout << spirt.Con() << std::endl;
			water.Pereliv(spirt); // ����������
			count++;
		}
	std::cout << "iterations " << count << std::endl;
*/
//159 �������� - ���������� �����
//X = 100NP / M � 100P
//��� N � ����������� �������� ������;
//M � ������� ���������(���������� ��������);
//P � �����������(����� ������������ �������� � ����������� ��������� �� 100);
//� � ���������� �� ����, ������� ������� �������� � ������������ ��������.

	char c;
	std::cin >> c;
return 0;
}//end_main

