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
 * From CNPROJ: doc/zh_CN.GB2312/share/mk/fixrtf.lex,v 1.1.1000.20 2006/02/19 10:21:40 intron Exp
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <err.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <sys/param.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <png.h>

/*
 * This program is used to fix RTF:
 * 1. Embed PNGs into RTF.
 * 2. Embed FreeBSD-specific information into RTF, such as organization name,
 *    building time. But unfortunately, so far only Microsoft Word can read
 *    them. In contrast, Microsoft Word Viewer and OpenOffice even cannot read
 *    this kind of information from RTF created by Microsoft Word and
 *    OpenOffice. (Option: -i)
 * 3. Do some locale-specific fixing. (Option: -e <encoding>)
 *
 * See also Rich Text Format (RTF) Specification:
 * 1. Version 1.8 (Microsoft Word 2003)
 *    http://www.microsoft.com/downloads/details.aspx?familyid=ac57de32-17f0-4b46-9e4e-467ef9bc5540&displaylang=en
 * 2. Version 1.7 (Microsoft Word 2002)
 *    http://support.microsoft.com/kb/q86999/
 * 3. Version 1.6 (Microsoft Word 2000)
 *    http://msdn.microsoft.com/library/en-us/dnrtfspec/html/rtfspec.asp
 */


int embedpng_enable=0;

/* See also http://msdn.microsoft.com/library/en-us/intl/unicode_81rn.asp */
#define	ENCODING_UNKNOWN	0
#define	ENCODING_GB2312		936
#define	ENCODING_GB18030	54936
#define	ENCODING_BIG5		950

int encoding=ENCODING_UNKNOWN;


int fetchinfo_enable=0; /* FALSE */


#define MY_BUFFER_SIZE		3072
#define MY_BUFFER_LIMIT		2048

/* MY_BUFFER_LIMIT is smaller MY_BUFFER_SIZE, reserving some redundance. */

/*
 * "mybuffer" is used to cache RTF stream 
 * while fetching book/article information.
 */
size_t mybufferlength=0;
char mybuffer[MY_BUFFER_SIZE];


#define	INFO_TITLE	0
#define	INFO_AUTHOR	1

/* To store fetched book/article information */
struct
{
	size_t length;
	char text[MY_BUFFER_SIZE];
} *pinfobuf=NULL,infobuf[]=
{
	{0,""},
	{0,""}
};

/*
 * See also the section "Pictures" in RTF specification.
 */
void
embedpng(char *field)
{
	char *p1,*p2,fn[PATH_MAX];
	unsigned char buf[256];
	FILE *fp;
	int l,i,nret;
	png_structp png_ptr;
	png_infop info_ptr,end_info;
	png_uint_32 width,height;

	p1=strcasestr(field,"INCLUDEPICTURE");
	p1=strchr(p1+14,'"'); /* String after "INCLUDEPICTURE" */
	p2=strchr(p1+1,'"');
	l=p2-(p1+1); /* Substantial length of file name */
	if(l>sizeof(fn)-1)
	{
		warnx("*** Buffer Overflow Attack Detected !!! ***");
		exit(1);
	}
	memcpy(fn,p1+1,l);
	fn[l]=0;

	if(l<4) /* It should be longer than ".png". */
	{
		warnx("File name '%s' is too short!",fn);
		goto embedpng_exit_1;
	}

	if(strcasecmp(fn+(l-4),".png")!=0)
	{
		warnx("File name '%s' has not a suffix '.png'. Keep untouched.",fn);
		goto embedpng_exit_1;
	}

	if((fp=fopen(fn,"rb"))==NULL)
	{
		warnx("Failed to open '%s'!",fn);
		goto embedpng_exit_1;
	}

	fread(buf,1,8,fp);
	if (png_sig_cmp(buf,0,8))
	{
		warnx("The file '%s' is NOT in PNG format!",fn);
		goto embedpng_exit_2;
	}
	png_ptr=png_create_read_struct(PNG_LIBPNG_VER_STRING,NULL,NULL,NULL);
	if (!png_ptr)
	{
		warnx("Unable to create PNG read struct(*png_ptr)!");
		goto embedpng_exit_2;
	}
	info_ptr=png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		warnx("Unable to create PNG info struct(*info_ptr)!");
		png_destroy_read_struct(&png_ptr,(png_infopp)NULL,(png_infopp)NULL);
		goto embedpng_exit_2;
	}
	end_info=png_create_info_struct(png_ptr);
	if(!end_info)
	{
		warnx("Unable to create PNG info struct(*end_info)!");
        	png_destroy_read_struct(&png_ptr,&info_ptr,(png_infopp)NULL);
		goto embedpng_exit_2;
	}
	if (setjmp(png_jmpbuf(png_ptr)))
	{
		warnx("LibPNG crashed!");
		png_destroy_read_struct(&png_ptr,&info_ptr,&end_info);
		goto embedpng_exit_2;
	}
	rewind(fp);
	png_init_io(png_ptr,fp);
	png_read_info(png_ptr,info_ptr);
	width=png_get_image_width(png_ptr,info_ptr);
	height=png_get_image_height(png_ptr,info_ptr);

	if(width>1024 || height>768) warnx("Picture is too large!");

	/*
	 * According to Microsoft's RTF specification, \picwN and \pichN is
	 * mandatory for \pict group. Actually, in both Microsoft Word Viewer
	 * and OpenOffice, these two control words take no effect for PNG.
	 */
	printf("{\\pict\\pngblip\\picscalex100\\picscaley100\\picw%u\\pich%u",
		(unsigned int)width,(unsigned int)height);

	rewind(fp);
	while((nret=fread(buf,1,64,fp))>0)
	{
		printf("\n");
		for(i=0;i<nret;i++)
			printf("%02x",(unsigned int)((unsigned char)buf[i]));
	}

	printf("}");

	warnx("'%s' (%ux%u) embedded.",fn,(unsigned int)width,(unsigned int)height);

	png_destroy_read_struct(&png_ptr,&info_ptr,&end_info);
	fclose(fp);
	goto embedpng_exit_0;

embedpng_exit_2:;
	fclose(fp);
embedpng_exit_1:;
	printf("%s",field); /* Keep link in RTF untouched */
embedpng_exit_0:;
	return;
}

/*
 * See also the section "Font Table" in RTF specification.
 */
void
modifycharset(char *fcharset)
{
	char *s;

	switch(encoding)
	{
	case ENCODING_GB2312:
	case ENCODING_GB18030: /* GB18030 is not supported in RTF so far */
		s="\\fcharset134";
		break;
	case ENCODING_BIG5:
		s="\\fcharset136";
		break;
	default:
		s="\\fcharset1"; /* "Default" */
		break;
	}

	printf("%s",s);

	warnx("Charset control word modified: %s -> %s",fcharset,s);

	return;
}

/*
 * (init|addto|flush)mybuffer maintain buffer to cache RTF stream
 * while fetching book/article information.
 */
void initmybuffer()
{
	int i;

	mybufferlength=0;
	for(i=0;i<sizeof(infobuf)/sizeof(infobuf[0]);i++)
	{
		infobuf[i].length=0;
		infobuf[i].text[0]=0;
	}
}

int addtomybuffer(char *text, size_t leng)
{
	if(mybufferlength+leng>MY_BUFFER_LIMIT) return -1;
	/* warnx("_%s_",yytext); */
	memcpy(mybuffer+mybufferlength,text,leng);
	mybufferlength+=leng; /* No terminator '\0' */
	return 0;
}

void flushmybuffer()
{
	fwrite(mybuffer,1,mybufferlength,yyout);
	mybufferlength=0;
}

#define	ADDTOBUF { \
	if(addtomybuffer(yytext,yyleng)) \
	{ \
		haltfetch(); \
		ECHO; \
		BEGIN(0); \
		warnx("Had been fetching book/article information until buffer was full!"); \
		YY_BREAK; \
	} \
   }


/* Collect book/article information RTF sequence */
void collectinfo(char *text, size_t leng)
{
	assert(pinfobuf!=NULL);
	if(pinfobuf->length+leng>=MY_BUFFER_LIMIT) /* Consider terminator '\0' */
	{
		warnx("*** Too long text for title or author !!! ***");
		warnx("*** Buffer Overflow Attack To Be Considered !!! ***");
		return; /* Information item buffer is full. */
	}
	memcpy(pinfobuf->text+pinfobuf->length,text,leng);
	pinfobuf->length+=leng;
	pinfobuf->text[pinfobuf->length]=0;
}

/* Identify a RTF control word */
int identifyctrlword(char *text, size_t leng, char *key)
{
	if(text[leng-1]==' ')
	{ /* Tailed by a space as delimiter */
		if(strlen(key)!=leng-1) return 0;
		return !strncmp(text,key,leng-1);
	}

	return !strcmp(text,key);
}

/*
 * Output fetch book/article information.
 * See also the section "Information Group" in RTF specification.
 */
void outputinfo()
{
	time_t t;
	char buf[128];

	printf("{\\info\\uc0");

	printf("{\\title %s}{\\author %s}",
		infobuf[INFO_TITLE].text,infobuf[INFO_AUTHOR].text);

	time(&t);
	strftime(buf,sizeof(buf),"\\yr%Y\\mo%m\\dy%d\\hr%H\\min%M\\sec%S",localtime(&t));
	printf("{\\creatim%s}",buf);

	printf("}");
}

void haltfetch()
{
	warnx("Title: %s",infobuf[INFO_TITLE].text);
	warnx("Author: %s",infobuf[INFO_AUTHOR].text);
	outputinfo();
	flushmybuffer();
}

%}

%option noyywrap

%s	fetchinfo

pnglink		\{\\field[^{}]*\{[^{}]*INCLUDEPICTURE[^{}]*\".+\"[^{}]*\}\{[^{}]*\}[^{}]*\}
sjischarset	\\fcharset128
stylesheet	\{\\stylesheet[ ]?
titlebegin	\\pard.{1,25}\\fs49[ ]?
authorbegin	\\pard.{1,25}\\fs34[ ]?
rtfhexvalue	\\\'[0-9A-Fa-f]{2}
rtfctrlword	\\[a-z]+([-]?[0-9]+)?[ ]?
rtfctrlsymbol	\\[^a-z]

%%

{pnglink}  { /*
	      * Substitute RTF \pict group for RTF field group.
	      * An example generated by Jade/OpenJade:
	      * {\field\flddirty{\*\fldinst INCLUDEPICTURE "sockets/layers.png" }{\fldrslt }}
	      */
		if(embedpng_enable) embedpng(yytext);
		else { ECHO; }
	   }

{sjischarset}  {
	      /*
	       * Jade/OpenJade mis-mark Chinese as Shift-JIS encoded Japanese.
	       * This may cause RTF viewer to display Chinese with Japanese font.
	       */
		if(encoding!=ENCODING_UNKNOWN) modifycharset(yytext);
		else { ECHO; }
	   }

{stylesheet}  { /* Insert book/article information just before style sheet. */
		if(fetchinfo_enable)
		{ /* Begin fetching book/article information. */
			initmybuffer();
			BEGIN(fetchinfo);
			fetchinfo_enable=0; /* FALSE, one-off */
			ADDTOBUF;
		}
		else
		{
			ECHO;
		}
	   }

<fetchinfo>{titlebegin}  { /* Beginning of title, hacked by font size. */
		ADDTOBUF;
		pinfobuf=&(infobuf[INFO_TITLE]);
		if(pinfobuf->length>0) collectinfo(", ",2); /* Duplicated */
	   }

<fetchinfo>{authorbegin}  { /* Beginning of author, hacked by font size. */
		ADDTOBUF;
		pinfobuf=&(infobuf[INFO_AUTHOR]);
		if(pinfobuf->length>0) collectinfo(", ",2); /* Duplicated */
	   }

<fetchinfo>{rtfhexvalue}  { /* A hexadecimal value, ignore. */
		ADDTOBUF;
	   }

<fetchinfo>\\~  { /* Nonbreaking space, a control symbol, collect */
		ADDTOBUF;
		if(pinfobuf!=NULL) collectinfo(" ",1);
	   }

<fetchinfo>\\[-_]  { /* Optional/nonbreaking hyphen, a control symbol, collect */
		ADDTOBUF;
		if(pinfobuf!=NULL) collectinfo("-",1);
	   }

<fetchinfo>{rtfctrlsymbol}  { /* Other control symbols, ignore */
		ADDTOBUF;
	   }

<fetchinfo>{rtfctrlword}  { /* Control word */
		ADDTOBUF;

		if(identifyctrlword(yytext,yyleng,"\\keepn"))
		{ /* End of title or author, actually a hack */
			pinfobuf=NULL;
		}
		else if(yytext[0]=='\\' && yytext[1]=='u' &&
			((yytext[2]>='0' && yytext[2]<='9') || yytext[2]=='-') )
		{ /* Unicode Character, collect */
			if(pinfobuf!=NULL)
			{
				collectinfo(yytext,yyleng);
				if(yytext[yyleng-1]!=' ') collectinfo(" ",1);
			}
		}
		else if(identifyctrlword(yytext,yyleng,"\\page"))
		{ /* Accomplished !!!  */
			haltfetch();
			BEGIN(0);
		}
	   }

<fetchinfo>[\n{}]  {  /* Ignore */
		ADDTOBUF;
	   }

<fetchinfo>.  { /* Collect */
		ADDTOBUF;
		if(pinfobuf!=NULL) collectinfo(yytext,yyleng);
	   }

%%

void printusage()
{
	fprintf(stderr,	"Usage: fixrtf [-e encoding] [-i] [-p] < inputfile > outputfile\n"
			"     Fix RTF file generated by Jade/OpenJade.\n"
			"Options:\n"
			"       -e encoding\n"
			"             Specify encoding to do specific fixing. (GB2312|BIG5)\n"
			"       -i\n"
			"             Fill RTF file information, such as title and author,\n"
			"             hacked from RTF file generated by Jade/OpenJade.\n"
			"       -p\n"
			"             Embed linked PNG images into RTF file.\n"
		);
}

int
main(int argc, char *argv[])
{
	int ch;

	if(argc<=1)
	{
		warnx("You should indicate at least one kind of fixing.");
		printusage();
		return 1;
	}

	while ((ch = getopt(argc, argv, "e:ip")) != -1)
	{
		switch (ch)
		{
		case 'e':
			if(strcasecmp(optarg,"GB2312")==0 ||
				strcasecmp(optarg,"GBK")==0)
			{
				encoding=ENCODING_GB2312;
			}
			else if(strcasecmp(optarg,"GB18030")==0)
			{
				encoding=ENCODING_GB18030;
			}
			else if(strcasecmp(optarg,"BIG5")==0)
			{
				encoding=ENCODING_BIG5;
			}
			break;
		case 'i':
			fetchinfo_enable=1; /* One-off */
			break;
		case 'p':
			embedpng_enable=1;
			break;
		default:
			printusage();
			return 1;
			break;
		}
	}

	yylex();

	return 0;
}
