# include <stdio.h>
# include <unistd.h>
# define U(x) x
# define NLSTATE yyprevious=YYNEWLINE
# define BEGIN yybgin = yysvec + 1 +
# define INITIAL 0
# define YYLERR yysvec
# define YYSTATE (yyestate-yysvec-1)
# define YYOPTIM 1
# define YYLMAX BUFSIZ
# define output(c) putc(c,yyout)
# define input() (((yytchar=yysptr>yysbuf?U(*--yysptr):getc(yyin))==10?(yylineno++,yytchar):yytchar)==EOF?0:yytchar)
# define unput(c) {yytchar= (c);if(yytchar=='\n')yylineno--;*yysptr++=yytchar;}
# define yymore() (yymorfg=1)
# define ECHO fprintf(yyout, "%s",yytext)
# define REJECT { nstr = yyreject(); goto yyfussy;}
int yyleng; extern char yytext[];
int yymorfg;
extern char *yysptr, yysbuf[];
int yytchar;
FILE *yyin = STDIN_FILENO, *yyout = STDOUT_FILENO;
extern int yylineno;
struct yysvf { 
	struct yywork *yystoff;
	struct yysvf *yyother;
	int *yystops;};
struct yysvf *yyestate;
extern struct yysvf yysvec[], *yybgin;

#pragma ident   "@(#)lex.l 1.2     93/01/13"

#undef ECHO
#undef input
#include "ftptool.h"

#undef input
extern char *lex_string;
# define input() (((yytchar=yysptr>yysbuf?U(*--yysptr):*lex_string++)==10?(yylineno++,yytchar):yytchar)==0?0:yytchar)
# define YYNEWLINE 10
yylex(){
int nstr; extern int yyprevious;
while((nstr = yylook()) >= 0)
yyfussy: switch(nstr){
case 0:
if(yywrap()) return(0); break;
case 1:
{return(' ');}
break;
case 2:
	{return(PERMS);}
break;
case 3:
	{return(LINKS);}
break;
case 4:
	{return(USER);}
break;
case 5:
	{return(GROUP);}
break;
case 6:
	{return(SIZE);}
break;
case 7:
	{return(MONTH);}
break;
case 8:
		{return(DAY);}
break;
case 9:
	{return(TIME);}
break;
case 10:
	{return(NAME);}
break;
case 11:
	{return(SKIP);}
break;
case 12:
	{return(NONUNIX);}
break;
case 13:
	{return(LOWERNAME);}
break;
case 14:
		{return(yytext[0]);}
break;
case -1:
break;
default:
fprintf(yyout,"bad switch yylook %d",nstr);
} return(0); }
/* end of yylex */

yywrap()
{
	return 1;
}
int yyvstop[] = {
0,

14,
0,

1,
14,
0,

1,
0,

14,
0,

14,
0,

14,
0,

14,
0,

14,
0,

14,
0,

14,
0,

14,
0,

14,
0,

14,
0,

8,
0,

10,
0,

6,
0,

11,
0,

9,
0,

4,
0,

5,
0,

3,
0,

7,
0,

2,
0,

13,
0,

12,
0,
0};
# define YYTYPE char
struct yywork { YYTYPE verify, advance; } yycrank[] = {
0,0,	0,0,	1,3,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	1,4,	1,5,	
4,5,	4,5,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	4,5,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	1,6,	0,0,	51,57,	
0,0,	0,0,	7,17,	16,28,	
0,0,	1,7,	12,23,	27,39,	
1,8,	33,44,	9,19,	11,21,	
14,26,	1,9,	1,10,	1,11,	
2,6,	1,12,	6,16,	8,18,	
1,13,	1,14,	1,15,	10,20,	
2,7,	11,22,	13,24,	2,8,	
13,25,	15,27,	17,29,	18,30,	
2,9,	2,10,	2,11,	19,31,	
2,12,	20,32,	21,33,	2,13,	
2,14,	2,15,	22,34,	23,35,	
24,36,	25,37,	26,38,	28,40,	
30,41,	31,42,	32,43,	34,45,	
35,46,	36,47,	37,48,	38,49,	
39,50,	40,51,	41,52,	42,53,	
43,54,	45,55,	46,56,	55,58,	
58,59,	0,0,	0,0,	0,0,	
0,0};
struct yysvf yysvec[] = {
0,	0,	0,
yycrank+-1,	0,		0,	
yycrank+-20,	yysvec+1,	0,	
yycrank+0,	0,		yyvstop+1,
yycrank+3,	0,		yyvstop+3,
yycrank+0,	yysvec+4,	yyvstop+6,
yycrank+4,	0,		yyvstop+8,
yycrank+1,	0,		yyvstop+10,
yycrank+1,	0,		yyvstop+12,
yycrank+1,	0,		yyvstop+14,
yycrank+8,	0,		yyvstop+16,
yycrank+10,	0,		yyvstop+18,
yycrank+1,	0,		yyvstop+20,
yycrank+17,	0,		yyvstop+22,
yycrank+3,	0,		yyvstop+24,
yycrank+10,	0,		yyvstop+26,
yycrank+2,	0,		0,	
yycrank+5,	0,		0,	
yycrank+16,	0,		0,	
yycrank+21,	0,		0,	
yycrank+23,	0,		0,	
yycrank+25,	0,		0,	
yycrank+28,	0,		0,	
yycrank+25,	0,		0,	
yycrank+18,	0,		0,	
yycrank+36,	0,		0,	
yycrank+33,	0,		0,	
yycrank+2,	0,		0,	
yycrank+34,	0,		0,	
yycrank+0,	0,		yyvstop+28,
yycrank+27,	0,		0,	
yycrank+38,	0,		0,	
yycrank+30,	0,		0,	
yycrank+4,	0,		0,	
yycrank+30,	0,		0,	
yycrank+39,	0,		0,	
yycrank+48,	0,		0,	
yycrank+38,	0,		0,	
yycrank+50,	0,		0,	
yycrank+38,	0,		0,	
yycrank+52,	0,		0,	
yycrank+42,	0,		0,	
yycrank+40,	0,		0,	
yycrank+52,	0,		0,	
yycrank+0,	0,		yyvstop+30,
yycrank+47,	0,		0,	
yycrank+43,	0,		0,	
yycrank+0,	0,		yyvstop+32,
yycrank+0,	0,		yyvstop+34,
yycrank+0,	0,		yyvstop+36,
yycrank+0,	0,		yyvstop+38,
yycrank+1,	0,		0,	
yycrank+0,	0,		yyvstop+40,
yycrank+0,	0,		yyvstop+42,
yycrank+0,	0,		yyvstop+44,
yycrank+54,	0,		0,	
yycrank+0,	0,		yyvstop+46,
yycrank+0,	0,		yyvstop+48,
yycrank+40,	0,		0,	
yycrank+0,	0,		yyvstop+50,
0,	0,	0};
struct yywork *yytop = yycrank+128;
struct yysvf *yybgin = yysvec+1;
char yymatch[] = {
00  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,011 ,012 ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
011 ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
0};
char yyextra[] = {
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0};
#ifndef lint
static	char ncform_sccsid[] = "@(#)ncform 1.6 88/02/08 SMI"; /* from S5R2 1.2 */
#endif

int yylineno =1;
# define YYU(x) x
# define NLSTATE yyprevious=YYNEWLINE
char yytext[YYLMAX];
struct yysvf *yylstate [YYLMAX], **yylsp, **yyolsp;
char yysbuf[YYLMAX];
char *yysptr = yysbuf;
int *yyfnd;
extern struct yysvf *yyestate;
int yyprevious = YYNEWLINE;
yylook(){
	register struct yysvf *yystate, **lsp;
	register struct yywork *yyt;
	struct yysvf *yyz;
	int yych, yyfirst;
	struct yywork *yyr;
# ifdef LEXDEBUG
	int debug;
# endif
	char *yylastch;
	/* start off machines */
# ifdef LEXDEBUG
	debug = 0;
# endif
	yyfirst=1;
	if (!yymorfg)
		yylastch = yytext;
	else {
		yymorfg=0;
		yylastch = yytext+yyleng;
		}
	for(;;){
		lsp = yylstate;
		yyestate = yystate = yybgin;
		if (yyprevious==YYNEWLINE) yystate++;
		for (;;){
# ifdef LEXDEBUG
			if(debug)fprintf(yyout,"state %d\n",yystate-yysvec-1);
# endif
			yyt = yystate->yystoff;
			if(yyt == yycrank && !yyfirst){  /* may not be any transitions */
				yyz = yystate->yyother;
				if(yyz == 0)break;
				if(yyz->yystoff == yycrank)break;
				}
			*yylastch++ = yych = input();
			yyfirst=0;
		tryagain:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"char ");
				allprint(yych);
				putchar('\n');
				}
# endif
			yyr = yyt;
			if ( (int)yyt > (int)yycrank){
				yyt = yyr + yych;
				if (yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
# ifdef YYOPTIM
			else if((int)yyt < (int)yycrank) {		/* r < yycrank */
				yyt = yyr = yycrank+(yycrank-yyt);
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"compressed state\n");
# endif
				yyt = yyt + yych;
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				yyt = yyr + YYU(yymatch[yych]);
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"try fall back character ");
					allprint(YYU(yymatch[yych]));
					putchar('\n');
					}
# endif
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transition */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
			if ((yystate = yystate->yyother) && (yyt= yystate->yystoff) != yycrank){
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"fall back to state %d\n",yystate-yysvec-1);
# endif
				goto tryagain;
				}
# endif
			else
				{unput(*--yylastch);break;}
		contin:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"state %d char ",yystate-yysvec-1);
				allprint(yych);
				putchar('\n');
				}
# endif
			;
			}
# ifdef LEXDEBUG
		if(debug){
			fprintf(yyout,"stopped at %d with ",*(lsp-1)-yysvec-1);
			allprint(yych);
			putchar('\n');
			}
# endif
		while (lsp-- > yylstate){
			*yylastch-- = 0;
			if (*lsp != 0 && (yyfnd= (*lsp)->yystops) && *yyfnd > 0){
				yyolsp = lsp;
				if(yyextra[*yyfnd]){		/* must backup */
					while(yyback((*lsp)->yystops,-*yyfnd) != 1 && lsp > yylstate){
						lsp--;
						unput(*yylastch--);
						}
					}
				yyprevious = YYU(*yylastch);
				yylsp = lsp;
				yyleng = yylastch-yytext+1;
				yytext[yyleng] = 0;
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"\nmatch ");
					sprint(yytext);
					fprintf(yyout," action %d\n",*yyfnd);
					}
# endif
				return(*yyfnd++);
				}
			unput(*yylastch);
			}
		if (yytext[0] == 0  /* && feof(yyin) */)
			{
			yysptr=yysbuf;
			return(0);
			}
		yyprevious = yytext[0] = input();
		if (yyprevious>0)
			output(yyprevious);
		yylastch=yytext;
# ifdef LEXDEBUG
		if(debug)putchar('\n');
# endif
		}
	}
yyback(p, m)
	int *p;
{
if (p==0) return(0);
while (*p)
	{
	if (*p++ == m)
		return(1);
	}
return(0);
}
	/* the following are only used in the lex library */
yyinput(){
	return(input());
	}
yyoutput(c)
  int c; {
	output(c);
	}
yyunput(c)
   int c; {
	unput(c);
	}
