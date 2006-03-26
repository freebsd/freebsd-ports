%{
/*-
 * Copyright (c) 2005, 2006 intron <intron@intron.ac>.  All rights reserved.
 * Copyright (c) 2005, 2006 The FreeBSD Simplified Chinese Project.
 * All rights reserved.
 *
 * This code is derived from software contributed to The FreeBSD Simplified
 * Chinese Project by intron.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	CNPROJ: doc/zh_CN.GB2312/share/mk/cjktexsty.lex,v 1.1.1000.40 2006/02/19 20:32:32 intron Exp
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <err.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <iconv.h>

char texencoding[128]="",*cjkencoding=NULL,cjkfont[128]="";
iconv_t iconvhandle;
int ccmap_enable=0;

void
errexit(void)
{

	errx(1, "Error: line %d", yylineno);
}

void
transcode(char *ch)
{
	char *pchar,*pout,input[16],output[128];
	const char *pin;
	int c;
	size_t lin,lout;
	size_t outlen;

	pchar=strstr(ch,"{");
	if(pchar==NULL)
	    errexit();
	if(sscanf(pchar+1,"%d",&c)!=1)
	    errexit();

	/* UCS-4 big endian, including not only Basic Multilingual Plane */
	input[0]=(c&0xff000000)>>24;
	input[1]=(c&0xff0000)>>16;
	input[2]=(c&0xff00)>>8;
	input[3]=(c&0xff);
	pin=input;
	lin=4;

	pout=output;
	lout=sizeof(output);

	iconv(iconvhandle,&pin,&lin,&pout,&lout);

	if(lin!=0) {
	    switch(c) {
	    case 8212: strcpy(output,"\\ensuremath{-}"); break;
	    case 8226: strcpy(output,"\\ensuremath{\\bullet}"); break;
	    case 8482: strcpy(output,"\\ensuremath{^{\\mathrm{TM}}}"); break;
	    case 10122: strcpy(output,"{\\large\\ding{202}}"); break;
	    case 10123: strcpy(output,"{\\large\\ding{203}}"); break;
	    case 10124: strcpy(output,"{\\large\\ding{204}}"); break;
	    case 10125: strcpy(output,"{\\large\\ding{205}}"); break;
	    case 10126: strcpy(output,"{\\large\\ding{206}}"); break;
	    case 10127: strcpy(output,"{\\large\\ding{207}}"); break;
	    case 10128: strcpy(output,"{\\large\\ding{208}}"); break;
	    case 10129: strcpy(output,"{\\large\\ding{209}}"); break;
	    case 10130: strcpy(output,"{\\large\\ding{210}}"); break;
	    case 10131: strcpy(output,"{\\large\\ding{211}}"); break;
	    case 10132: strcpy(output,"\\ensuremath{\\rightarrow}"); break;
	    case 65533: strcpy(output,"{\\large\\ding{96}}"); break;
	    default:
		warnx("Unable to find a substitute for UNICODE character &#%d;", c);
		strcpy(output,"??");
		break;
	    }
	} else {
		outlen=sizeof(output)-lout;
		output[outlen]=0;

		if(outlen==2 && strcspn(output,"\\$&%#@{}^_~\x80")!=outlen)
		{ /* TeX special character */
			sprintf(output,"\\CJKchar{%u}{%u}",
				(unsigned int)(unsigned char)output[0],
				(unsigned int)(unsigned char)output[1]
				);
		}
	}

	printf("%s",output);
}

%}

%option yylineno
%option noyywrap

fotbegin	\\FOT\{[^}]*\}
fotend		\\endFOT\{[^}]*\}
cjk		\\Character\{[0-9]{1,5}\}

%%

{fotbegin}	{
			/*
			 * A confusing but practical structure:
			 *
			 * \usepackage{CJK}
			 *     \begin{CJK*}{GB}{song}
			 *         \FOT{3}
			 *
			 *             ...
			 *
			 *     \end{CJK*}
			 *         \endFOT{}
			 *
			 * The macro call \begin{CJK*} must be put before
			 * \FOT, or generated PDF will include many "@".
			 */
			printf("\\usepackage{textcomp}\n");
			printf("\\usepackage{pifont}\n");
			printf("\\usepackage{wasysym}\n");
			printf("\\usepackage{CJK}\n");
			if(ccmap_enable) printf("\\usepackage{ccmap}\n");
			printf("\\hypersetup{CJKbookmarks=true,hypertex,pdfauthor={FreeBSD Documentation Project}}\n");
			printf("\\begin{CJK*}{%s}{%s}\n%s\n",cjkencoding,cjkfont,yytext);
		}
{fotend}	{
			/*
			 * \FOT does NOT include \begin{document},
			 * while \endFOT includes \end{document} explicitly.
			 * Thus, \endFOT should NOT be put between
			 * \begin{CJK*} and \end{CJK*},
			 * whether there is a \FOT between them or not.
			 */
			printf("\n\\end{CJK*}%s\n",yytext);
		}
{cjk}		{ transcode(yytext); }

[\xA0]		{ printf("{\\nobreakspace}"); }
[\xA1]		{ printf("{\\textexclamdown}"); }
[\xA2]		{ printf("{\\textcent}"); }
[\xA3]		{ printf("{\\pounds}"); }
[\xA4]		{ printf("{\\textcurrency}"); }
[\xA5]		{ printf("{\\textyen}"); }
[\xA6]		{ printf("{\\textbrokenbar}"); }
[\xA7]		{ printf("{\\S}"); }
[\xA8]		{ printf("{\\\"{}}"); }
[\xA9]		{ printf("{\\copyright}"); }
[\xAA]		{ printf("{\\textordfeminine}"); }
[\xAB]		{ printf("\\ensuremath{_{^{\\ll}}}"); }
[\xAC]		{ printf("\\ensuremath{\\lnot}"); }
[\xAD]		{ printf("{-}"); }
[\xAE]		{ printf("{\\textregistered}"); }
[\xAF]		{ printf("\\ensuremath{^{-}}"); }
[\xB0]		{ printf("{\\textdegree}"); }
[\xB1]		{ printf("\\ensuremath{\\pm}"); }
[\xB2]		{ printf("\\ensuremath{^{2}}"); }
[\xB3]		{ printf("\\ensuremath{^{3}}"); }
[\xB4]		{ printf("\\ensuremath{'}"); }
[\xB5]		{ printf("\\ensuremath{\\mu}"); }
[\xB6]		{ printf("{\\P}"); }
[\xB7]		{ printf("{\\ifmmode\\cdot\\else\\textperiodcentered\\fi}"); }
[\xB8]		{ printf("\\c{}"); }
[\xB9]		{ printf("\\ensuremath{^{1}}"); }
[\xBA]		{ printf("{\\textordmasculine}"); }
[\xBB]		{ printf("\\ensuremath{_{^{\\gg}}}"); }
[\xBC]		{ printf("{\\textonequarter}"); }
[\xBD]		{ printf("{\\textonehalf}"); }
[\xBE]		{ printf("{\\textthreequarters}"); }
[\xBF]		{ printf("{\\textquestiondown}"); }
[\xC0]		{ printf("\\ensuremath{\\grave{\\mathrm{A}}}"); }
[\xC1]		{ printf("\\ensuremath{\\acute{\\mathrm{A}}}"); }
[\xC2]		{ printf("{\\^A}"); }
[\xC3]		{ printf("{\\~A}"); }
[\xC4]		{ printf("{\\\"A}"); }
[\xC5]		{ printf("{\\AA}"); }
[\xC6]		{ printf("{\\AE}"); }
[\xC7]		{ printf("{\\c C}"); }
[\xC8]		{ printf("\\ensuremath{\\grave{\\mathrm{E}}}"); }
[\xC9]		{ printf("\\ensuremath{\\acute{\\mathrm{E}}}"); }
[\xCA]		{ printf("{\\^E}"); }
[\xCB]		{ printf("{\\\"E}"); }
[\xCC]		{ printf("\\ensuremath{\\grave{\\mathrm{I}}}"); }
[\xCD]		{ printf("\\ensuremath{\\acute{\\mathrm{I}}}"); }
[\xCE]		{ printf("{\\^I}"); }
[\xCF]		{ printf("{\\\"I}"); }
[\xD0]		{ printf("{\\DH}"); }
[\xD1]		{ printf("{\\~N}"); }
[\xD2]		{ printf("\\ensuremath{\\grave{\\mathrm{O}}}"); }
[\xD3]		{ printf("\\ensuremath{\\acute{\\mathrm{O}}}"); }
[\xD4]		{ printf("{\\^O}"); }
[\xD5]		{ printf("{\\~O}"); }
[\xD6]		{ printf("{\\\"O}"); }
[\xD7]		{ printf("\\ensuremath{\\times}"); }
[\xD8]		{ printf("{\\O}"); }
[\xD9]		{ printf("\\ensuremath{\\grave{\\mathrm{U}}}"); }
[\xDA]		{ printf("\\ensuremath{\\acute{\\mathrm{U}}}"); }
[\xDB]		{ printf("{\\^U}"); }
[\xDC]		{ printf("{\\\"U}"); }
[\xDD]		{ printf("\\ensuremath{\\acute{\\mathrm{Y}}}"); }
[\xDE]		{ printf("{\\Thorn}"); }
[\xDF]		{ printf("{\\ss}"); }
[\xE0]		{ printf("\\ensuremath{\\grave{\\mathrm{a}}}"); }
[\xE1]		{ printf("\\ensuremath{\\acute{\\mathrm{a}}}"); }
[\xE2]		{ printf("{\\^a}"); }
[\xE3]		{ printf("{\\~a}"); }
[\xE4]		{ printf("{\\\"a}"); }
[\xE5]		{ printf("{\\aa}"); }
[\xE6]		{ printf("{\\ae}"); }
[\xE7]		{ printf("{\\c c}"); }
[\xE8]		{ printf("\\ensuremath{\\grave{\\mathrm{e}}}"); }
[\xE9]		{ printf("\\ensuremath{\\acute{\\mathrm{e}}}"); }
[\xEA]		{ printf("{\\^e}"); }
[\xEB]		{ printf("{\\\"e}"); }
[\xEC]		{ printf("\\ensuremath{\\grave{\\mathrm{\\i}}}"); }
[\xED]		{ printf("\\ensuremath{\\acute{\\mathrm{\\i}}}"); }
[\xEE]		{ printf("{\\^\\i}"); }
[\xEF]		{ printf("{\\\"\\i}"); }
[\xF0]		{ printf("{\\dh}"); }
[\xF1]		{ printf("{\\~n}"); }
[\xF2]		{ printf("\\ensuremath{\\grave{\\mathrm{o}}}"); }
[\xF3]		{ printf("\\ensuremath{\\acute{\\mathrm{o}}}"); }
[\xF4]		{ printf("{\\^o}"); }
[\xF5]		{ printf("{\\~o}"); }
[\xF6]		{ printf("{\\\"o}"); }
[\xF7]		{ printf("\\ensuremath{\\div}"); }
[\xF8]		{ printf("{\\o}"); }
[\xF9]		{ printf("\\ensuremath{\\grave{\\mathrm{u}}}"); }
[\xFA]		{ printf("\\ensuremath{\\acute{\\mathrm{u}}}"); }
[\xFB]		{ printf("{\\^u}"); }
[\xFC]		{ printf("{\\\"u}"); }
[\xFD]		{ printf("\\ensuremath{\\acute{\\mathrm{y}}}"); }
[\xFE]		{ printf("{\\thorn}"); }
[\xFF]		{ printf("{\\\"y}"); }

[\xa0-\xff]	{
		  warnx("Unable to find a substitute for ISO8859-1 character \\x%X",
			(unsigned int)(*((unsigned char *)yytext)));
		  printf("?");
		}

%%

void printusage()
{
	fprintf(stderr,	"Usage: cjktexsty [ -c ] -e encoding -f fontname\n"
			"      Convert TeX source including \\Character{xxxxx} generated by\n"
			"      Jade/OpenJade into what CJK-LaTeX can process.\n"
			"     \n"
			"NOTE: Jade/OpenJade supports EUC-JP natively. Thus, this tool SHOULD NOT be\n"
			"      used in this case. This tool treats all bytes larger than 0xa0 as\n"
			"      ISO 8859-1 characters, and converts \\Character{xxxxx} into encoding\n"
			"      that CJK-LaTeX can process.\n"
			"      \n"
			"Options:\n"
			"     -c\n"
			"          Use ccmap.sty for PDFTeX to generate text-copyable CJK PDF.\n"
			"          The package ccmap.sty is written by Wenchang Sun and Linbo Zhang.\n"
			"          See also ftp://ftp.cc.ac.cn/pub/cct/ for details.\n"
			"     -e encoding\n"
			"          Specify TeX source encoding for CJK-LaTeX.\n"
			"     -f fontname\n"
			"          Specify font name in CJK macro call, such as\n"
			"          \\begin{CJK*}{encoding}{font}.\n"
			"      \n"
			"CJK-LaTeX supported combinations by default:\n"
			"     <TeX source encoding>  <CJK encoding name>  <CJK font name>\n"
			"     ------------------------------------------------------------\n"
			"            GB2312                   GB                 song\n"
			"            GBK                      GBK                song\n"
			"            BIG5                     Bg5                bsmi\n"
			"            EUCJP                    JIS                min\n"
			"            EUCKR                    KS                     \n"
			"            UTF-8                    UTF8               song\n"
		);
}

int
main(int argc, char *argv[])
{
	int ch;
	char *p;

	while ((ch = getopt(argc, argv, "ce:f:")) != -1)
	{
		switch (ch)
		{
		case 'c':
			ccmap_enable=1;
			break;
		case 'e':
			if(strcasecmp(optarg,"GB2312")==0) cjkencoding="GB";
			else if(strcasecmp(optarg,"GBK")==0) cjkencoding="GBK";
			else if(strcasecmp(optarg,"GB18030")==0) cjkencoding="GBK"; /* Not supported by CJK yet */
			else if(strcasecmp(optarg,"BIG5")==0) cjkencoding="Bg5";
			else if(strcasecmp(optarg,"EUCJP")==0) cjkencoding="JIS";
			else if(strcasecmp(optarg,"EUCKR")==0) cjkencoding="KS";
			else if(strcasecmp(optarg,"UTF-8")==0) cjkencoding="UTF8";
			else cjkencoding=NULL;
			if(cjkencoding!=NULL) {
				strlcpy(texencoding,optarg,sizeof(texencoding));
				for(p=texencoding;*p!=0;p++)
				    *p=toupper((int)((unsigned char)*p));
			}
			break;
		case 'f':
			strlcpy(cjkfont,optarg,sizeof(cjkfont));
			break;
		default:
			printusage();
			return 1;
			break;
		}
	}

	if(cjkencoding==NULL)
	{
		printusage();
		return 1;
	}

	iconvhandle=iconv_open(texencoding,"UCS-4BE");
	yylex();
	iconv_close(iconvhandle);
	return 0;
}
