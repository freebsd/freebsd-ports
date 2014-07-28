--- freebsd/estruct.h.orig	Wed Mar 25 14:21:05 1998
+++ freebsd/estruct.h	Wed Mar 25 14:25:34 1998
@@ -0,0 +1,1254 @@
+/*	ESTRUCT:	Structure and preprocesser defined for
+			MicroEMACS 4.00
+
+			(C)Copyright 1995 by Daniel Lawrence
+			written by Daniel Lawrence
+			based on code by Dave G. Conroy,
+				Steve Wilhite and George Jones
+*/
+
+#ifdef	LATTICE
+#undef	LATTICE 	 /* don't use their definitions...use ours	 */
+#endif
+#ifdef	MSDOS
+#undef	MSDOS
+#endif
+#ifdef	WINNT
+#undef	WINNT
+#endif
+#ifdef	AMIGA
+#undef	AMIGA
+#endif
+#ifdef	EGA
+#undef	EGA
+#endif
+#ifdef	CTRLZ
+#undef	CTRLZ
+#endif
+
+/*	Program Identification.....
+
+	PROGNAME should always be MicroEMACS for a distribution
+	unmodified version. People using MicroEMACS as a shell
+	for other products should change this to reflect their
+	product. Macros can query this via the $progname variable
+*/
+
+#define PROGNAME	"MicroEMACS"
+#define VERSION 	"4.00"
+
+/*	Machine/OS definitions			*/
+/*	[Set one of these!!]			*/
+
+#define AMIGA	0			/* AmigaDOS			*/
+#define AOSVS	0			/* Data General AOS/VS		*/
+#define AUX     0                       /* Apple UNIX for Macintosh     */
+#define AIX     0                       /* IBM UNIX for various machines*/
+#define AVIION	0			/* Data General AViiON		*/
+#define BSD	0			/* UNIX BSD 4.2 and ULTRIX	*/
+#define FINDER	0			/* Macintosh OS 		*/
+#define	FREEBSD	1			/* FREEBSD 386 version 2 or +	*/
+#define HPUX8	0			/* HPUX HP 9000 ver 8 or less	*/
+#define HPUX9	0			/* HPUX HP 9000 ver 9           */
+#define MPE	0			/* HP MPE/XL			*/
+#define MSDOS	0			/* MS-DOS			*/
+#define WINNT	0			/* MS-Win NT			*/
+#define OS2	0			/* Microsoft or IBM OS/2	*/
+#define SMOS	0			/* Supermax UNIX System V	*/
+#define SUN	0			/* SUN v4.0			*/
+#define TOS	0			/* ST520, TOS			*/
+#define USG	0			/* UNIX system V		*/
+#define VMS	0			/* VAX/VMS			*/
+#define WMCS	0			/* Wicat's MCS			*/
+#define XENIX	0			/* IBM-PC SCO XENIX		*/
+
+/*	Compiler definitions			*/
+/*	[Set one of these!!]			*/
+#define ALCYON	0	/* ALCYON Atari ST compiler */ 
+#define AZTEC	0	/* Aztec C 4.00e ONLY for the amiga now... */
+#define DGC	0	/* Data General AOS/VS C... */
+#define GCC	1	/* the GNU C compiler */
+#define IC	0	/* Rational Systems Instant C */
+#define LATTICE 0	/* Lattice 2.14 through 3.0 compilers */
+#define MSC	0	/* MicroSoft C compile version 3 thru 7 */
+#define MWC	0	/* Mark Williams C */
+#define TURBO	0	/* Turbo C and Borland C++ under MSDOS */
+#define UNIX	0	/* a standard UNIX compiler (cc) */
+#define ZTC	0	/* Zortech C/C++ 1.02 thru 2.10 under MSDOS */
+
+/*	Machine stack growth direction. 		    */
+/*  [Set this to 1 if your machine stack grows UP!!!]	    */
+/*	data general mv/eclipse series stack grows up.	    */
+/*	dec vax series stack grows down... got it???	    */
+
+#define STACK_GROWS_UP	0
+
+/*	Debugging options	*/
+#define RAMSIZE		0	/* dynamic RAM memory usage tracking */
+#define RAMSHOW		0	/* auto dynamic RAM reporting */
+#define RAMTRCK		0	/* send debug info to MALLOC.DAT */
+#define DEBUG_SEARCH	0	/* pop some search info on patterns */
+
+/*   Special keyboard/network definitions	     */
+
+#define ATKBD	0		/* AT-style keyboard with F11, F12 & grey keys */
+#define WANGPC	0		/* WangPC - mostly escape sequences	*/
+#define VT100	1		/* Handle VT100 style keypad - NOT VMS. */
+#define KEYPAD	0		/* VMS - turn on and off application	*/
+				/* keypad automatically */
+#define XONDATA 0		/* VMS - set to force /NOTTSYNC/NOHOSTSY */
+#define RMSIO	0		/* VMS - skip the rotten C runtime and	*/
+				/* use RMS directly			*/
+#define OPTMEM	0		/* VMS 5.0 and up - use a less standard */
+				/* but more efficient memory allocator	*/
+
+/*	Terminal Output definitions		*/
+/*	[Set one of these!!]			*/
+
+#define ANSI	0			/* ANSI escape sequences	*/
+#define DASHER	0			/* DG Dasher 2xx/4xx crts	*/
+#define DG10	0			/* Data General system/10	*/
+#define FMR	0			/* Fujitsu FMR series driver	*/
+#define HP110	0			/* HP110 screen driver		*/
+#define HP150	0			/* HP150 screen driver		*/
+#define I55	0			/* IBM PS55 DOS J4.0/V		*/
+#define IBMPC	0			/* IBM-PC CGA/MONO/EGA/VGA drvr */
+#define MAC	0			/* Macintosh			*/
+#define NEC	0			/* NEC-9801VM driver		*/
+#define OS2NPM	0			/* OS/2 non-Presentation Mgr.	*/
+#define SMG	0			/* SMG library on VMS		*/
+#define ST52	0			/* Atari 520/1040ST screen	*/
+#define TERMCAP 1			/* Use TERMCAP			*/
+#define TIPC	0			/* TI Profesional PC driver	*/
+#define VT52	0			/* VT52 terminal (Zenith).	*/
+#define NTCON	0			/* Windows NT console		*/
+#define	XVT	0			/* XVT windowing system		*/
+#define Z309	0			/* Zenith 100 PC family driver	*/
+
+/*	Windowing system style (pick one)				*/
+
+#define WINDOW_TEXT	1		/* [default] Text mode		*/
+#define WINDOW_MSWIN	0		/* MicroSoft Windows		*/
+#define WINDOW_MSWIN32	0		/* MicroSoft Windows 32 bit API */
+#define WINDOW_X	0		/* X/Unix			*/
+
+/*	Language text options	(pick one)				*/
+
+#define ENGLISH 1		/* [default] */
+#define FRENCH	0
+#define SPANISH 0
+#define GERMAN	0
+#define DUTCH	0
+#define PLATIN	0		/* Pig Latin */
+#define JAPAN	0
+#define LATIN	0		/* real Latin */
+
+/*	Configuration options	*/
+
+#define TYPEAH	1	/* type ahead causes update to be skipped	*/
+#define LOGFLG	0	/* send all executed commands to EMACS.LOG	*/
+#define VISMAC	0	/* update display during keyboard macros	*/
+#define CTRLZ	0	/* add a ^Z at end of files under MSDOS only	*/
+#define CLEAN	0	/* de-alloc memory on exit			*/
+#define CALLED	0	/* is emacs a called subroutine? or stand alone */
+
+#define REVSTA	1	/* Status line appears in reverse video 	*/
+#define COLOR	1	/* color commands and windows			*/
+
+#define FILOCK	0	/* file locking under unix BSD 4.2		*/
+#define ISRCH	1	/* Incremental searches like ITS EMACS		*/
+#define FLABEL	0	/* function key label code [HP150]		*/
+#define CRYPT	1	/* file encryption enabled?			*/
+#define MAGIC	1	/* include regular expression matching? 	*/
+#define MOUSE	1	/* Include routines for mouse actions		*/
+#define NOISY	1	/* Use a fancy BELL if it exists		*/
+#define CTAGS	1	/* include vi-like tagging?			*/
+#define SPEECH	0	/* spoken EMACS, for the sight impared [not ready] */
+#define VARARG	1	/* use varargs.h for mlwrite()			*/
+
+#if	XVT
+#undef	COLOR
+#define	COLOR	1	/* overide this to be TRUE for XVT always	*/
+#endif
+
+/*	Character set options		*/
+/*	[Set one of these!!]		*/
+#define ASCII	1	/* always using ASCII char sequences for now	*/
+#define EBCDIC	0	/* later IBM mainfraim versions will use EBCDIC */
+
+/* handle constant and voids properly */
+
+#if	VMS
+#define CONST	readonly
+#define VOID	void
+#define NOSHARE noshare
+#else
+#if	AOSVS
+#define CONST $shared $align(1)     /* fake a  const */
+#define VOID
+#define NOSHARE $low32k $align(1)   /* attempt to optimize read/write vars. */
+#else
+
+#if	__STDC__ || MSC || TURBO || GCC || (AMIGA && LATTICE)
+#define CONST	const
+#define VOID	void
+#define NOSHARE
+#else
+#define CONST
+#if	IC
+#define	VOID	void
+#else
+#define VOID
+#endif
+#define NOSHARE
+#endif
+
+#endif
+#endif
+
+/*	System dependant library redefinitions, structures and includes */
+
+/*	multibyte character support?	*/
+
+#if	NEC || FMR || I55
+#define DBCS	1	/* double byte character sets enabled */
+#define INSDEL	1	/* use insert/delete line display optimizations */
+
+/* define DBCS prefix bytes */
+#define is2char(ch) (((ch&0xff) >= 0x81 && (ch&0xff) <= 0x9f) || ((ch&0xff) >=0xe0 && (ch&0xff) <= 0xfc))
+
+#else
+#define DBCS	0
+#define INSDEL	0
+#endif
+
+/*	Can we catch the SIGWINCH (the window size change signal)? */
+
+#if AIX || HPUX9 || FREEBSD
+#define HANDLE_WINCH	1
+#else
+#define HANDLE_WINCH	0
+#endif
+
+/*	Prototypes in use?	*/
+
+#if	MSC || TURBO || IC || VMS || GCC || ZTC
+#define PROTO	1
+#else
+#define PROTO	0
+#endif
+
+/*	the following define allows me to initialize unions...
+	otherwise we make them structures (like the keybinding table)  */
+
+#if	__STDC__ || MSC || TURBO || IC || ZTC
+#define ETYPE	union
+#else
+#define ETYPE	struct
+#endif
+
+/* Instant C can't do stat()s. Arrrg. No file locking for you */
+#if	IC && MSDOS
+#undef FILOCK
+#define FILOCK	0
+#endif
+
+/* Mark Williams/Atari has no standard or varargs or directory functions */
+#if	TOS & MWC
+#undef VARARG
+#define	VARARG	0
+#undef	FILOCK
+#define	FILOCK	0
+#endif
+
+/* MS-Windows */
+
+#if     WINNT || WINDOW_MSWIN || WINDOW_MSWIN32
+#if     WINDOW_MSWIN32
+#undef  WINDOW_MSWIN
+#define WINDOW_MSWIN    1
+#endif
+#if     WINDOW_MSWIN && WINNT
+#undef  WINDOW_MSWIN32
+#define WINDOW_MSWIN32  1
+#endif
+#undef  VOID    /* windows.h will wind up defining this */
+#include <windows.h>    /* --------- Huge include file here !!! ---------*/
+#if     NTCON
+#include <wincon.h>
+#include <stdio.h>
+#include <dos.h>
+#endif
+
+#undef NEAR
+#define NEAR
+#define DNEAR
+#if     MSC || IC
+#undef CDECL
+#define CDECL   __cdecl
+#define DUMMYSZ 1    /* dummy size for unsized extern arrays to avoid
+                        silly DGROUP fixup */
+#else
+#if	TURBO
+#define DUMMYSZ     /* nothing */
+#else
+#define CDECL   _cdecl  /* ZTC */
+#define DUMMYSZ     /* nothing */
+#endif
+#endif
+
+#if	WINNT
+#define	EXPORT	/* Windows NT doesn't like this */
+#endif
+
+#if     WINDOW_MSWIN
+#undef  TYPEAH
+#define TYPEAH  0   /* typeahead is handled at the term driver level */
+#undef  CALLED
+#define CALLED  1   /* under MS Windows, "main" resides in the sys driver */
+#if     MSC
+#define EXPORT  __export
+#else
+#define EXPORT  _export	/* Fine for TURBO and ZTC */
+#endif
+#endif
+#else
+
+/* neither Windows NT nor MS-Windows */
+
+#define DUMMYSZ     /* nothing */
+
+#if MSDOS & (TURBO | MSC | TIPC)
+#define	NEAR
+#define	DNEAR
+#define	PASCAL pascal
+#define	CDECL cdecl
+#else
+#if MSDOS & ZTC
+#define	NEAR
+#define	DNEAR
+#define	PASCAL _pascal
+#define	CDECL _cdecl
+#else
+#define NEAR
+#define	DNEAR
+#define	PASCAL
+#define	CDECL
+#endif
+#endif
+
+#endif
+
+#if	TURBO
+#include      <dos.h>
+#include      <mem.h>
+#undef peek
+#undef poke
+#define       peek(a,b,c,d)   movedata(a,b,FP_SEG(c),FP_OFF(c),d)
+#define       poke(a,b,c,d)   movedata(FP_SEG(c),FP_OFF(c),a,b,d)
+#endif
+
+#if	IC
+#include      <dos.h>
+#undef peek
+#undef poke
+#define       peek(a,b,c,d)   movedata(a,b,FP_SEG(c),FP_OFF(c),d)
+#define       poke(a,b,c,d)   movedata(FP_SEG(c),FP_OFF(c),a,b,d)
+#endif
+
+#if	LATTICE & MSDOS
+/* you may have to remove this one definition with LATTICE version
+   3.2 and above						  */
+#define unsigned
+#endif
+
+#if	IC
+#define inp	inportb
+#define outp	outportb
+#define intdos(a, b)	int86(33, a, b)
+#endif
+
+#if	AZTEC
+#undef	putc
+#undef	getc
+#if	MSDOS
+#define getc	a1getc
+#define int86	sysint
+#define intdos(a, b)	sysint(33, a, b)
+#define inp	inportb
+#define outp	outportb
+#else
+#define getc	agetc
+#endif
+#define putc	aputc
+
+struct XREG {
+	unsigned ax,bx,cx,dx,si,di,ds,es;
+};
+
+struct HREG {
+	char al,ah,bl,bh,cl,ch,dl,dh,d1,d2,e1,e2;
+};
+
+union REGS {
+	struct XREG x;
+	struct HREG h;
+};
+
+struct SREGS {
+	unsigned cs, ss, ds, es;
+};
+#endif
+
+#if	MSDOS & MWC
+#include	<dos.h>
+#define int86(a, b, c)	intcall(b, c, a)
+#define intdos(a, b)	intcall(a, b, DOSINT)
+#define inp(a)		in(a)
+#define outp(a, b)	out(a, b)
+#define movmem(a, b, c) memcpy(b, a, c)
+
+struct XREG {
+	unsigned int ax,bx,cx,dx,si,di,ds,es,flags;
+};
+
+struct HREG {
+	char al,ah,bl,bh,cl,ch,dl,dh;
+	unsigned int ds,es,flags;
+};
+
+union REGS {
+	struct XREG x;
+	struct HREG h;
+};
+#endif
+
+#if	MSDOS & MSC
+#include	<dos.h>
+#include	<memory.h>
+#define peek(a,b,c,d)	movedata(a,b,FP_SEG(c),FP_OFF(c),d)
+#define poke(a,b,c,d)	movedata(FP_SEG(c),FP_OFF(c),a,b,d)
+#define movmem(a, b, c) 	memcpy(b, a, c)
+#define _strrev(a)	strrev(a)
+#endif
+
+#if	MSDOS & LATTICE
+#undef	CPM
+#undef	LATTICE
+#include	<dos.h>
+#undef	CPM
+#endif
+
+/* System V doesn't name this the same as others */
+#if	USG | AIX | AUX | SUN | (OS2 & MSC)
+#define movmem(a, b, c) 	memcpy(b, a, c)
+#endif
+
+/* this keeps VMS happy */
+#if	VMS
+#define getname xgetname
+#define unlink(a)	delete(a)
+#endif
+
+/* some options for AOS/VS */
+#if	AOSVS
+#define ORMDNI	1
+#endif
+
+/*	define some ability flags */
+
+#if	(IBMPC | Z309 | FMR | TIPC) & !(WINDOW_MSWIN | WINDOW_MSWIN32)
+#define MEMMAP	1
+#else
+#define MEMMAP	0
+#endif
+
+#if	MSDOS | WINNT | OS2 | USG | AIX | AUX | SMOS | HPUX8 | HPUX9 | BSD | FREEBSD | (TOS & MWC) | WMCS | SUN | MPE
+#define ENVFUNC 1
+#else
+#define ENVFUNC 0
+#endif
+
+#if	AUX
+#define RETCHAR	'\n'
+#else
+#define RETCHAR '\r'
+#endif
+
+#if	MPE
+#define DIRSEPSTR	"."
+#define DIRSEPCHAR	'.'
+#else
+#if	TOS || MSDOS || WINNT || OS2
+#define DIRSEPSTR	"\\"
+#define DIRSEPCHAR	'\\'
+#define DRIVESEPCHAR	':'
+#else
+#define DIRSEPSTR	"/"
+#define DIRSEPCHAR	'/'
+#define DRIVESEPCHAR	'\0'
+#endif
+#endif
+
+#if	VARARG
+#if	(GCC == 0) && (USG || AIX || AUX || BSD || FREEBSD || SUN || XENIX || HPUX8 || HPUX9 || AVIION || MPE)
+#define VARG	1
+#define SARG	0
+#include	<varargs.h>
+#else
+#define VARG	0
+#define SARG	1
+#include	<stdarg.h>
+#endif
+#endif
+
+#if ZTC
+#include     <dos.h>
+#define      movmem(a, b, c) memcpy(b, a, c)
+#endif
+
+/*	Emacs global flag bit definitions (for gflags)	*/
+
+#define GFREAD	1	/* read first file in at startup */
+#define GFSDRAW 2	/* suppress a screen redraw */
+#define	GFEXIT	4	/* exit from emacs pending */
+
+/*	internal constants	*/
+
+#define NBINDS	300			/* max # of bound keys		*/
+#if	AOSVS | VMS | WINNT | SUN | BSD | FREEBSD | USG | ZENIX | HPUX8 | HPUX9 | OS2
+#define NFILEN	256
+#else
+#define NFILEN	80			/* # of bytes, file name	*/
+#endif
+#define NBUFN	128			/* # of bytes, buffer name	*/
+#define NLINE	256			/* # of bytes, input line	*/
+#define NSTRING 128			/* # of bytes, string buffers	*/
+#define NKBDM	4096			/* # of strokes, keyboard macro */
+#define NPAT	128			/* # of bytes, pattern		*/
+#define HUGE	1000			/* Huge number			*/
+#define NLOCKS	256			/* max # of file locks active	*/
+#define NCOLORS 16			/* number of supported colors	*/
+#define KBLOCK	250			/* sizeof kill buffer chunks	*/
+#define NRING	16			/* # of buffers in kill ring	*/
+#define NBLOCK	16			/* line block chunk size	*/
+#define NVSIZE	16			/* max #chars in a var name	*/
+#define NMARKS	16			/* number of marks		*/
+#define	MAXSYM	32			/* max # chars in symbol to expand */
+#define MINFLEN 3			/* min # chars to match &func	*/
+
+#define CTRL	0x0100		/* Control flag, or'ed in		*/
+#define META	0x0200		/* Meta flag, or'ed in			*/
+#define CTLX	0x0400		/* ^X flag, or'ed in			*/
+#define SPEC	0x0800		/* special key (function keys)		*/
+#define MOUS	0x1000		/* alternative input device (mouse)	*/
+#define SHFT	0x2000		/* shifted (for function keys)		*/
+#define ALTD	0x4000		/* ALT key...				*/
+#define MENU	MOUS+SPEC	/* menu selection (WINDOW_MSWIN)	*/
+
+#define BINDNUL 0		/* not bound to anything		*/
+#define BINDFNC 1		/* key bound to a function		*/
+#define BINDBUF 2		/* key bound to a buffer		*/
+
+#ifdef	FALSE
+#undef	FALSE
+#endif
+#ifdef	TRUE
+#undef	TRUE
+#endif
+
+#define FALSE	0			/* False, no, bad, etc. 	*/
+#define TRUE	1			/* True, yes, good, etc.	*/
+#define ABORT	2			/* Death, ^G, abort, etc.	*/
+#define FAILD	3			/* not-quite fatal false return */
+
+#define STOP	0			/* keyboard macro not in use	*/
+#define PLAY	1			/*		  playing	*/
+#define RECORD	2			/*		  recording	*/
+
+/*	Completion types 	*/
+
+#define CMP_BUFFER	0
+#define CMP_COMMAND	1
+#define CMP_FILENAME	2
+
+/*	Directive definitions	*/
+
+#define DIF		0
+#define DELSE		1
+#define DENDIF		2
+#define DGOTO		3
+#define DRETURN 	4
+#define DENDM		5
+#define DWHILE		6
+#define DENDWHILE	7
+#define DBREAK		8
+#define DFORCE		9
+
+#define NUMDIRS 	10
+
+/*
+ * PTBEG, PTEND, FORWARD, and REVERSE are all toggle-able values for
+ * routines that need directions.
+ */
+#define PTBEG	0	/* Leave the point at the beginning on search	*/
+#define PTEND	1	/* Leave the point at the end on search 	*/
+#define FORWARD 0	/* do things in a forward direction		*/
+#define REVERSE 1	/* do things in a backwards direction		*/
+
+#define FIOSUC	0			/* File I/O, success.		*/
+#define FIOFNF	1			/* File I/O, file not found.	*/
+#define FIOEOF	2			/* File I/O, end of file.	*/
+#define FIOERR	3			/* File I/O, error.		*/
+#define FIOMEM	4			/* File I/O, out of memory	*/
+#define FIOFUN	5			/* File I/O, eod of file/bad line*/
+#define FIODEL	6			/* Can't delete/rename file	*/
+
+#if     WINDOW_MSWIN
+/* values for the fbusy flag */
+#define FREADING 1                      /* file read in progress */
+#define FWRITING 2                      /* file write in progress */
+/* if no file activity, the value FALSE is used */
+#endif
+
+#define CFCPCN	0x0001			/* Last command was C-P, C-N	*/
+#define CFKILL	0x0002			/* Last command was a kill	*/
+#define CFSRCH	0x0004			/* last command was a search	*/
+#define CFYANK	0x0008			/* last command was a yank	*/
+
+#define SRNORM	0			/* end past, begin front	*/
+#define SRBEGIN 1			/* always at front		*/
+#define SREND	2			/* always one past end		*/
+
+#define BELL	0x07			/* a bell character		*/
+#define TAB	0x09			/* a tab character		*/
+
+#if	USG | AIX | AUX | SMOS | HPUX8 | HPUX9 | BSD | FREEBSD | SUN | XENIX | AVIION
+#define PATHCHR ':'
+#else
+#if	WMCS || MPE
+#define PATHCHR ','
+#else
+#define PATHCHR ';'
+#endif
+#endif
+
+#define INTWIDTH	sizeof(int) * 3
+#define LONGWIDTH	sizeof(long) * 3
+
+/*	Macro argument token types					*/
+
+#define TKNUL	0			/* end-of-string		*/
+#define TKARG	1			/* interactive argument 	*/
+#define TKBUF	2			/* buffer argument		*/
+#define TKVAR	3			/* user variables		*/
+#define TKENV	4			/* environment variables	*/
+#define TKFUN	5			/* function.... 		*/
+#define TKDIR	6			/* directive			*/
+#define TKLBL	7			/* line label			*/
+#define TKLIT	8			/* numeric literal		*/
+#define TKSTR	9			/* quoted string literal	*/
+#define TKCMD	10			/* command name 		*/
+
+/*	Internal defined functions					*/
+
+#define nextab(a)	(a - (a % tabsize)) + tabsize
+
+/* DIFCASE represents the integer difference between upper
+   and lower case letters.  It is an xor-able value, which is
+   fortunate, since the relative positions of upper to lower
+   case letters is the opposite of ascii in ebcdic.
+*/
+
+#if	ASCII
+#define DIFCASE 	0x20
+#else
+#define DIFCASE 	0x40
+#endif
+
+/*	Dynamic RAM tracking and reporting redefinitions	*/
+
+#if	RAMSIZE
+#define malloc	allocate
+#define free	release
+#else
+#if	VMS & OPTMEM
+#define malloc	VAXC$MALLOC_OPT
+#define free	VAXC$FREE_OPT
+#define calloc	VAXC$CALLOC_OPT
+#define realloc	VAXC$REALLOC_OPT
+#define cfree	VAXC$CFREE_OPT
+#endif
+#endif
+
+/* under MS Windows, we use dialog boxes to prompt the user for filenames */
+#if     WINDOW_MSWIN
+#define FILENAMEREPLY(p,b,nb)   filenamedlg(p,b,nb,TRUE)
+#else
+#define FILENAMEREPLY(p,b,nb)   mlreply(p,b,nb)
+#endif
+
+/* formal parameters to procedures are stored as a linked list
+   of argument names using the following simple structure:
+*/
+
+typedef struct PARG {
+	struct PARG *next;	/* ptr to next linked argument */
+	char name[NVSIZE+1];	/* name of the argument */
+} PARG;
+
+/* UNDO definitions and types */
+
+typedef int OPTYPE;	/* type of operation being recorded/played back */
+
+#define	OP_CMND		1	/* beginning of command */
+#define	OP_DELC		2	/* delete a single character */
+#define	OP_INSC		3	/* insert a single character */
+#define OP_DSTR		4	/* delete a string of characters */
+#define	OP_ISTR		5	/* insert a string of characters */
+#define	OP_REPC		6	/* replace a character */
+#define	OP_CPOS		7	/* set the cursor position */
+
+/* object to be undone! */
+
+typedef union OBJECT {
+	char obj_char;		/* a character */
+	char obj_string[1];	/* many characters */
+	char *obj_sptr;		/* a ptr to a character */
+} OBJECT;
+
+typedef struct UNDO_OBJ {
+	struct UNDO_OBJ *next;	/* ptr to next undo object */
+	OPTYPE type;		/* type of operation */
+	long line_num;		/* line offset from buffer beginning */
+	int offset;		/* offset into that line */
+	long count;		/* repetitions? */
+	OBJECT undo_obj;	/* object to be undone */
+} UNDO_OBJ;
+
+/*
+ * There is a window structure allocated for every active display window. The
+ * windows are kept in a big list, in top to bottom screen order, with the
+ * listhead at "wheadp". Each window contains its own values of dot and mark.
+ * The flag field contains some bits that are set by commands to guide
+ * redisplay. Although this is a bit of a compromise in terms of decoupling,
+ * the full blown redisplay is just too expensive to run for every input
+ * character.
+ */
+typedef struct	EWINDOW {
+	struct	EWINDOW *w_wndp; 	/* Next window			*/
+	struct	BUFFER *w_bufp; 	/* Buffer displayed in window	*/
+	struct	LINE *w_linep;		/* Top line in the window	*/
+	struct	LINE *w_dotp;		/* Line containing "."		*/
+	short	w_doto; 		/* Byte offset for "."		*/
+	struct	LINE *w_markp[NMARKS];	/* Line containing "mark"	*/
+	short	w_marko[NMARKS];	/* Byte offset for "mark"	*/
+	char	w_toprow;		/* Origin 0 top row of window	*/
+	char	w_ntrows;		/* # of rows of text in window	*/
+	char	w_force;		/* If NZ, forcing row.		*/
+	char	w_flag; 		/* Flags.			*/
+#if	COLOR
+	char	w_fcolor;		/* current forground color	*/
+	char	w_bcolor;		/* current background color	*/
+#endif
+	int	w_fcol; 		/* first column displayed	*/
+}	EWINDOW;
+
+#define WFFORCE 0x01			/* Window needs forced reframe	*/
+#define WFMOVE	0x02			/* Movement from line to line	*/
+#define WFEDIT	0x04			/* Editing within a line	*/
+#define WFHARD	0x08			/* Better to a full display	*/
+#define WFMODE	0x10			/* Update mode line.		*/
+#define WFCOLR	0x20			/* Needs a color change 	*/
+
+/* This structure holds the information about each line appearing on the
+ * video display. The redisplay module uses an array of virtual display
+ * lines. On systems that do not have direct access to display memory,
+ * there is also an array of physical display lines used to minimize
+ * video updating. In most cases, these two arrays are unique. If
+ * WINDOW_MSWIN is 1, there is a pair of such arrays in each SCREEN
+ * structure.
+ */
+
+typedef struct	VIDEO {
+	int	v_flag; 		/* Flags */
+#if	COLOR
+	int	v_fcolor;		/* current forground color */
+	int	v_bcolor;		/* current background color */
+	int	v_rfcolor;		/* requested forground color */
+	int	v_rbcolor;		/* requested background color */
+#endif
+	int	v_left;			/* left edge of reverse video */
+	int	v_right;		/* right right of reverse video */
+#if	INSDEL && MEMMAP == 0
+	int	v_rline;		/* requested screen line # */
+#endif
+	char	v_text[1];		/* Screen data. */
+}	VIDEO;
+
+#define VFNEW	0x0001			/* contents not meaningful yet	*/
+#define VFCHG	0x0002			/* Changed flag 		*/
+#define VFEXT	0x0004			/* extended (beyond column 80)	*/
+#define VFCOL	0x0008			/* color change requested	*/
+
+/*
+ *	This structure holds the information about each separate "screen"
+ * within the current editing session.  On a character based system, these
+ * screens overlay each other, and can individually be brought to front.
+ * On a windowing system like MicroSoft Windows 3.0, OS/2, the Macintosh,
+ * Intuition, Sunview or X-windows, each screen is represented in an OS
+ * window.  The terminolgy is wrong in emacs.....
+ *
+ *	EMACS		The outside World
+ *	screen		window
+ *	window		pane
+ */
+
+typedef struct SCREEN {
+	struct SCREEN *s_next_screen;	/* link to next screen in list */
+	EWINDOW *s_first_window; 	/* head of linked list of windows */
+	EWINDOW *s_cur_window;		/* current window in this screen */
+	char *s_screen_name;		/* name of the current window */
+	short s_roworg; 		/* row origin of stored screen */
+	short s_colorg; 		/* column origin of stored screen */
+	short s_nrow;			/* row width of stored screen */
+	short s_ncol;			/* column origin of stored screen */
+#if WINDOW_MSWIN
+	VIDEO **s_virtual;		/* virtual screen contents */
+	VIDEO **s_physical;		/* physical screen contents */
+	HWND s_drvhandle;		/* handle for the "term" driver */
+#endif
+} SCREEN;
+
+/*
+ * Text is kept in buffers. A buffer header, described below, exists for every
+ * buffer in the system. The buffers are kept in a big list, so that commands
+ * that search for a buffer by name can find the buffer header. There is a
+ * safe store for the dot and mark in the header, but this is only valid if
+ * the buffer is not being displayed (that is, if "b_nwnd" is 0). The text for
+ * the buffer is kept in a circularly linked list of lines, with a pointer to
+ * the header line in "b_linep".  Buffers may be "Inactive" which means the
+ * files associated with them have not been read in yet.  These get read in
+ * at "use buffer" time.
+ * Some buffers are really procedures and have a little extra information
+ * stored with them.
+ */
+typedef struct	BUFFER {
+	struct	BUFFER *b_bufp; 	/* Link to next BUFFER		*/
+	struct	LINE *b_dotp;		/* Link to "." LINE structure	*/
+	short	b_doto; 		/* Offset of "." in above LINE	*/
+	struct	LINE *b_markp[NMARKS];	/* The same as the above two,	*/
+	short	b_marko[NMARKS];	/* but for the "mark"		*/
+	int	b_fcol; 		/* first col to display 	*/
+	struct	LINE *b_linep;		/* Link to the header LINE	*/
+	struct	LINE *b_topline;	/* Link to narrowed top text	*/
+	struct	LINE *b_botline;	/* Link to narrowed bottom text */
+	char	b_active;		/* window activated flag	*/
+	char	b_nwnd; 		/* Count of windows on buffer	*/
+	char	b_exec; 		/* how many active executions	*/
+	char	b_flag; 		/* Flags			*/
+	int	b_mode; 		/* editor mode of this buffer	*/
+	char	b_fname[NFILEN];	/* File name			*/
+	char	b_bname[NBUFN]; 	/* Buffer name			*/
+#if	CRYPT
+	char   b_key[NPAT];		/* current encrypted key        */
+#endif
+	int b_numargs;			/* number of arguments to procedure */
+	PARG *b_args;			/* ptr to the first argument	*/
+	UNDO_OBJ *undo_head;		/* head of undo stack for buffer */
+	long undo_count;		/* # of undo operations stacked */
+	long last_access;		/* time of last access		*/
+}	BUFFER;
+
+#define BFINVS	0x01			/* Internal invisable buffer	*/
+#define BFCHG	0x02			/* Changed since last write	*/
+#define BFTRUNC 0x04			/* buffer was truncated when read */
+#define BFNAROW 0x08			/* buffer has been narrowed	*/
+
+#define	NOTPROC	-1			/* buffer is not a procedure */
+
+/*	mode flags	*/
+#define NUMMODES	11	       /* # of defined modes	       */
+
+#define MDWRAP	0x0001			/* word wrap			*/
+#define MDCMOD	0x0002			/* C indentation and fence match*/
+#define MDSPELL 0x0004			/* spell error parsing		*/
+#define MDEXACT 0x0008			/* Exact matching for searches	*/
+#define MDVIEW	0x0010			/* read-only buffer		*/
+#define MDOVER	0x0020			/* overwrite mode		*/
+#define MDMAGIC 0x0040			/* regular expresions in search */
+#define MDCRYPT 0x0080			/* encrytion mode active	*/
+#define MDASAVE 0x0100			/* auto-save mode		*/
+#define MDREPL	0x0200			/* replace mode 		*/
+#define MDABBR	0x0400			/* abbreviation expansion mode	*/
+
+/*
+ * The starting position of a region, and the size of the region in
+ * characters, is kept in a region structure.  Used by the region commands.
+ */
+typedef struct	{
+	struct	LINE *r_linep;		/* Origin LINE address. 	*/
+	short	r_offset;		/* Origin LINE offset.		*/
+	long	r_size; 		/* Length in characters.	*/
+}	REGION;
+
+/*
+ * All text is kept in circularly linked lists of "LINE" structures. These
+ * begin at the header line (which is the blank line beyond the end of the
+ * buffer). This line is pointed to by the "BUFFER". Each line contains a the
+ * number of bytes in the line (the "used" size), the size of the text array,
+ * and the text. The end of line is not stored as a byte; it's implied.
+ */
+typedef struct	LINE {
+	struct	LINE *l_fp;		/* Link to the next line	*/
+	struct	LINE *l_bp;		/* Link to the previous line	*/
+	short	l_size; 		/* Allocated size		*/
+	short	l_used; 		/* Used size			*/
+	char	l_text[1];		/* A bunch of characters.	*/
+}	LINE;
+
+#define lforw(lp)	((lp)->l_fp)
+#define lback(lp)	((lp)->l_bp)
+#if UNIX && (SUN || HPUX8 || HPUX9 || BSD || FREEBSD)
+#define lgetc(lp, n)	((unsigned char)(lp)->l_text[(n)])
+#else
+#define lgetc(lp, n)	((lp)->l_text[(n)])
+#endif
+#define lputc(lp, n, c) ((lp)->l_text[(n)]=(c))
+#define lused(lp)	((lp)->l_used)
+#define lsize(lp)	((lp)->l_size)
+#define ltext(lp)	((lp)->l_text)
+
+/*	This structure is used to hold a user variables name and its
+	current value. These are used for both the global and the
+	local symbol tables.
+*/
+
+typedef struct UVAR {
+	char u_name[NVSIZE + 1];	       /* name of user variable */
+	char *u_value;				/* value (string) */
+} UVAR;
+
+#define	VT_NONE		0	/* don't declare it if not found */
+#define	VT_LOCAL	1	/* local to the current procedure */
+#define	VT_GLOBAL	2	/* global to all procedures */
+
+/*	A UTABLE is a user variable table.... containing some header
+	information and an array of user variable names and definitions.
+	They are held together in a linked list, the last member of
+	the list being the global user variable table.
+*/
+
+typedef struct UTABLE {
+	struct UTABLE *next;	/* ptr to next user variable table */
+	int size;		/* max number of variables in table */
+	BUFFER *bufp;		/* ptr to buffer holding procedure
+				   assosiated with this symbol table. */
+	UVAR uv[1];		/* list of variable names/definitions
+				   in this variable table */
+} UTABLE;
+
+/*
+ * The editor communicates with the display using a high level interface. A
+ * "TERM" structure holds useful variables, and indirect pointers to routines
+ * that do useful operations. The low level get and put routines are here too.
+ * This lets a terminal, in addition to having non standard commands, have
+ * funny get and put character code too. The calls might get changed to
+ * "termp->t_field" style in the future, to make it possible to run more than
+ * one terminal type.
+ */
+#if	PROTO
+typedef struct	{
+	short	t_mrow; 		/* max number of rows allowable */
+	short	t_nrow; 		/* current number of rows used	*/
+	short	t_mcol; 		/* max Number of columns.	*/
+	short	t_ncol; 		/* current Number of columns.	*/
+	short	t_roworg;		/* origin row (normally zero)	*/
+	short	t_colorg;		/* origin column (normally zero)*/
+	short	t_margin;		/* min margin for extended lines*/
+	short	t_scrsiz;		/* size of scroll region "	*/
+	int	t_pause;		/* # times thru update to pause */
+	int (PASCAL NEAR *t_open)(void);    /* Open terminal at the start.*/
+	int (PASCAL NEAR *t_close)(void);   /* Close terminal at end.	*/
+	int (PASCAL NEAR *t_kopen)(void);   /* Open keyboard		*/
+	int (PASCAL NEAR *t_kclose)(void);  /* Close keyboard		*/
+	int (PASCAL NEAR *t_getchar)(void); /* Get character from keyboard. */
+	int (PASCAL NEAR *t_putchar)(int);  /* Put character to display.*/
+	int (PASCAL NEAR *t_flush)(void);   /* Flush output buffers.	*/
+	int (PASCAL NEAR *t_move)(int, int);/* Move the cursor, origin 0.*/
+	int (PASCAL NEAR *t_eeol)(void);    /* Erase to end of line.	*/
+	int (PASCAL NEAR *t_eeop)(void);    /* Erase to end of page.	*/
+	int (PASCAL NEAR *t_clrdesk)(void); /* Clear the page totally	*/
+	int (PASCAL NEAR *t_beep)(void);    /* Beep.			*/
+	int (PASCAL NEAR *t_rev)(int);      /* set reverse video state	*/
+	int (PASCAL NEAR *t_rez)(char *);   /* change screen resolution	*/
+#if	COLOR
+	int (PASCAL NEAR *t_setfor)(int);   /* set forground color	*/
+	int (PASCAL NEAR *t_setback)(int);  /* set background color 	*/
+#endif
+#if	INSDEL
+	int (PASCAL NEAR *t_insline)(int); /* insert a screen line 	*/
+	int (PASCAL NEAR *t_delline)(int); /* delete a screen line 	*/
+#endif
+#if     WINDOW_MSWIN
+        int (PASCAL NEAR *t_sleep)(int);   /* go to sleep for a while	*/
+        int (PASCAL NEAR *t_newscr)(SCREEN *);  /* create new screen display */
+        int (PASCAL NEAR *t_delscr)(SCREEN *);  /* destroy screen display */
+        int (PASCAL NEAR *t_selscr)(SCREEN *);  /* select screen display */
+        int (PASCAL NEAR *t_sizscr)(SCREEN *);  /* resize screen display */
+        int (PASCAL NEAR *t_topscr)(SCREEN *);  /* bring screen to top	*/
+#endif
+}	TERM;
+#else	/* TERM structure, no prototyping.*/
+
+typedef struct	{
+	short	t_mrow; 		/* max number of rows allowable */
+	short	t_nrow; 		/* current number of rows used	*/
+	short	t_mcol; 		/* max Number of columns.	*/
+	short	t_ncol; 		/* current Number of columns.	*/
+	short	t_roworg;		/* origin row (normally zero)	*/
+	short	t_colorg;		/* origin column (normally zero)*/
+	short	t_margin;		/* min margin for extended lines*/
+	short	t_scrsiz;		/* size of scroll region "	*/
+	int	t_pause;		/* # times thru update to pause */
+	int (PASCAL NEAR *t_open)();	/* Open terminal at the start.	*/
+	int (PASCAL NEAR *t_close)();	/* Close terminal at end.	*/
+	int (PASCAL NEAR *t_kopen)();	/* Open keyboard		*/
+	int (PASCAL NEAR *t_kclose)();	/* close keyboard		*/
+	int (PASCAL NEAR *t_getchar)(); /* Get character from keyboard. */
+	int (PASCAL NEAR *t_putchar)(); /* Put character to display.	*/
+	int (PASCAL NEAR *t_flush)();	/* Flush output buffers.	*/
+	int (PASCAL NEAR *t_move)();	/* Move the cursor, origin 0.	*/
+	int (PASCAL NEAR *t_eeol)();	/* Erase to end of line.	*/
+	int (PASCAL NEAR *t_eeop)();	/* Erase to end of page.	*/
+	int (PASCAL NEAR *t_clrdesk)(); /* Clear the page totally	*/
+	int (PASCAL NEAR *t_beep)();	/* Beep.			*/
+	int (PASCAL NEAR *t_rev)();	/* set reverse video state	*/
+	int (PASCAL NEAR *t_rez)();	/* change screen resolution	*/
+#if	COLOR
+	int (PASCAL NEAR *t_setfor)();	/* set forground color		*/
+	int (PASCAL NEAR *t_setback)(); /* set background color 	*/
+#endif
+#if	INSDEL
+	int (PASCAL NEAR *t_insline)(); /* insert a screen line 	*/
+	int (PASCAL NEAR *t_delline)(); /* delete a screen line 	*/
+#endif
+#if     WINDOW_MSWIN
+        int (PASCAL NEAR *t_sleep)();   /* go to sleep for a while	*/
+        int (PASCAL NEAR *t_newscr)();  /* create new screen display	*/
+        int (PASCAL NEAR *t_delscr)();  /* destroy screen display	*/
+        int (PASCAL NEAR *t_selscr)();  /* select screen display	*/
+        int (PASCAL NEAR *t_sizscr)();  /* resize screen display	*/
+        int (PASCAL NEAR *t_topscr)();  /* bring screen to top		*/
+#endif
+}	TERM;
+#endif
+
+
+/*	TEMPORARY macros for terminal I/O  (to be placed in a machine
+					    dependant place later) */
+
+#define TTopen		(*term.t_open)
+#define TTclose 	(*term.t_close)
+#define TTkopen 	(*term.t_kopen)
+#define TTkclose	(*term.t_kclose)
+#define TTgetc		(*term.t_getchar)
+#define TTputc		(*term.t_putchar)
+#define TTflush 	(*term.t_flush)
+#define TTmove		(*term.t_move)
+#define TTeeol		(*term.t_eeol)
+#define TTeeop		(*term.t_eeop)
+#define TTclrdesk	(*term.t_clrdesk)
+#define TTbeep		(*term.t_beep)
+#define TTrev		(*term.t_rev)
+#define TTrez		(*term.t_rez)
+#if	COLOR
+#define TTforg		(*term.t_setfor)
+#define TTbacg		(*term.t_setback)
+#endif
+
+/*	Structure for the table of current key bindings 	*/
+
+ETYPE EPOINTER {
+	int (PASCAL NEAR *fp)();	/* C routine to invoke */
+	BUFFER *buf;			/* buffer to execute */
+};
+
+typedef struct	{
+	short k_code;		/* Key code			*/
+	short k_type;		/* binding type (C function or EMACS buffer) */
+	ETYPE EPOINTER k_ptr;	/* ptr to thing to execute */
+}	KEYTAB;
+
+/*	structure for the name binding table		*/
+
+typedef struct {
+	char *n_name;			/* name of function key */
+	int (PASCAL NEAR *n_func)();	/* function name is bound to */
+}	NBIND;
+
+/*	The editor holds deleted text chunks in the KILL buffer. The
+	kill buffer is logically a stream of ascii characters, however
+	due to its unpredicatable size, it gets implemented as a linked
+	list of chunks. (The d_ prefix is for "deleted" text, as k_
+	was taken up by the keycode structure)
+*/
+
+typedef struct KILL {
+	struct KILL *d_next;   /* link to next chunk, NULL if last */
+	char d_chunk[KBLOCK];	/* deleted text */
+} KILL;
+
+/*	When emacs's command interpetor needs to get a variable's name,
+	rather than it's value, it is passed back as a VDESC variable
+	description structure. The v_num field is a index into the
+	appropriate variable table.
+*/
+
+typedef struct VDESC {
+	int v_type;	/* type of variable */
+	int v_num;	/* ordinal pointer to variable in list */
+	UTABLE *v_ut;	/* ptr to appropriate user table if user var */
+} VDESC;
+
+/*	The !WHILE directive in the execution language needs to
+	stack references to pending whiles. These are stored linked
+	to each currently open procedure via a linked list of
+	the following structure
+*/
+
+typedef struct WHBLOCK {
+	LINE *w_begin;		/* ptr to !while statement */
+	LINE *w_end;		/* ptr to the !endwhile statement*/
+	int w_type;		/* block type */
+	struct WHBLOCK *w_next; /* next while */
+} WHBLOCK;
+
+#define BTWHILE 	1
+#define BTBREAK 	2
+
+/*	Abbreviations are short symbols that expand to longer strings
+	when typed into a buffer with no intervening whitespace or commands.
+	This structure grows dynamically as needed.
+*/
+
+typedef struct ABBREV {
+	struct ABBREV *ab_next;		/* pointer to the next abbreviation */
+	char ab_sym[MAXSYM + 1];	/* name to expand */
+	char ab_exp[1];			/* string to expand to */
+} ABBREV;
+
+/* Search definitions... */
+
+/* HICHAR - 1 is the largest character we will deal with.
+ * BMAPSIZE represents the number of bytes in the bitmap.
+ */
+#define HICHAR		256
+#define BMAPSIZE	HICHAR >> 3
+
+/*
+ * Jump table structures.
+ */
+typedef struct {
+	int	jump;
+	int	patlen;
+	int	delta[HICHAR];
+	char	patrn[NPAT];
+} DELTA;
+
+#if	MAGIC
+/*
+ * Defines for the metacharacters in the regular expression
+ * search routines.  MCNIL and GROUP are used in both search
+ * and replace metachar-arrays.
+ */
+#define MCNIL		0	/* Like the '\0' for strings.*/
+#define JMPTABLE	1
+#define LITSTRING	2	/* Literal string.*/
+#define LITCHAR 	3	/* Literal character.*/
+#define ANY		4	/* Any character but the <NL>.*/
+#define CCL		5
+#define NCCL		6
+#define BOL		7
+#define EOL		8
+#define BOWRD		9
+#define EOWRD		10
+#define GRPBEG		11	/* Signal start of group.*/
+#define GRPEND		12	/* Signal end of group.*/
+#define GROUP		13	/* String of group match.*/
+#define DITTO		14	/* Replacement with match string.*/
+
+#define CLOSURE 	0x0100	/* An or-able value for a closure modifier.*/
+#define CLOSURE_1	0x0200	/* An or-able value for a closure modifier.*/
+#define ZEROONE 	0x0400	/* An or-able value for a closure modifier.*/
+
+#define ALLCLOS 	(CLOSURE | CLOSURE_1 | ZEROONE)
+#define MASKCLO 	(~ALLCLOS)
+
+#define MC_ANY		'.'	/* 'Any' character (except newline).*/
+#define MC_CCL		'['	/* Character class.*/
+#define MC_NCCL 	'^'	/* Negate character class.*/
+#define MC_RCCL 	'-'	/* Range in character class.*/
+#define MC_ECCL 	']'	/* End of character class.*/
+#define MC_BOL		'^'	/* Beginning of line.*/
+#define MC_EOL		'$'	/* End of line.*/
+#define MC_CLOSURE	'*'	/* Closure - zero to many characters match.*/
+#define MC_CLOSURE_1	'+'	/* Closure - one to many characters match.*/
+#define MC_ZEROONE	'?'	/* Closure - zero to one characters match.*/
+#define MC_DITTO	'&'	/* Use matched string in replacement.*/
+#define MC_GRPBEG	'('	/* Start of group (begun with a backslash).*/
+#define MC_GRPEND	')'	/* End of group (begun with a backslash).*/
+#define MC_BOWRD	'<'	/* Beginning of word (begun with a backslash).*/
+#define MC_EOWRD	'>'	/* End of word (begun with a backslash).*/
+#define MC_ESC		'\\'	/* Escape - suppress meta-meaning.*/
+
+#define MAXGROUPS	10		/* 1 + maximum # of r. e. groups. */
+#define BIT(n)		(1 << (n))	/* An integer with one bit set.*/
+
+/* Typedefs that define the bitmap type for searching (EBITMAP),
+ * the meta-character structure for MAGIC mode searching (MC),
+ * and the meta-character structure for MAGIC mode replacment (RMC).
+ */
+typedef char	*EBITMAP;
+
+typedef struct {
+	short int	mc_type;
+	union {
+		int	lchar;
+		int	group_no;
+		char	*lstring;
+		DELTA	*jmptable;
+		EBITMAP	cclmap;
+	} u;
+} MC;
+
+typedef struct {
+	short int	mc_type;
+	union {
+		int	group_no;
+		char	*rstr;
+	} u;
+} RMC;
+#endif
+
+/*
+	This is the message which should be added to any "About MicroEMACS"
+	boxes on any of the machines with window managers.
+
+
+	------------------------------------------
+	|					 |
+	|	 MicroEMACS v4.xx		 |
+	|		for the ............	 |
+	|					 |
+	|    Text Editor and Corrector		 |
+	|					 |
+	|    written by Daniel M. Lawrence	 |
+	|    [based on code by Dave Conroy]	 |
+	|					 |
+	|    Send inquiries and donations to:	 |
+	|    617 New York St			 |
+	|    Lafayette, IN 47901		 |
+	|					 |
+	------------------------------------------
+*/
