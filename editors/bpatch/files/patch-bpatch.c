--- bpatch.c.orig	1990-01-17 14:33:33 UTC
+++ bpatch.c
@@ -90,10 +90,15 @@
 /*E*/
 /*S includes, globals, and defines */
 /*Page Eject*/
-#include	<curses.h>
+#include <ncurses.h>
 #include <fcntl.h>
 #include <signal.h>
 #include <ctype.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
+#include <stdio.h>
+#include <termios.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 
@@ -103,14 +108,18 @@ struct stat sb;
 void icc ();
 void copyrec ();
 void schwapp ();
-
-/* added declarations, mostly for cleanliness */
-extern long lseek();
-extern long atol();
-extern char *strncpy();
-extern void exit();
-extern unsigned sleep();	/* signal problems ??? if sleep called */
-extern void perror();
+void breakp ();
+void reset ();
+int  ckfile (char *, long *);
+int  bread (int, char *, int, int);
+void errmsg (char *, unsigned);
+void show (int, char[16][16], char *, long, int, long, char, int, int, int, int, int, int);
+void dbg_msg (register char *);
+void dohelp ();
+void search (register int);
+int  arrow (register int, register int*, register int *);
+void outstr (char *);
+void outch (register char);
 
 /* set up for calls to outstr and errmsg, etc, */
 /* by use of sprintf to fill outbuf */
@@ -190,7 +199,7 @@ WINDOW *errwin = NULL;
 #ifdef	MOD_HAX
 #else	/* use original code... */
 	/* plus some more for restoring terminal function */
-	struct termio asis, aswas;
+	struct termios asis, aswas;
 #endif	/* MOD_HAX */
 
 /*S main - control all the work from here */
@@ -202,6 +211,7 @@ WINDOW *errwin = NULL;
 *
 *********************************************************************/
 /*E*/
+int
 main (argc, argv)
 int argc;
 char *argv[];
@@ -210,12 +220,10 @@ char *argv[];
 	extern WINDOW *newwin ();
 
 	register char	*cp;		/* general purpose char ptr	*/
-	extern   char	*gets ();	/* get string from stdin	*/
 		  char	m = '\017';	/* mask for hex edit		*/
 		  char	response[512];	/* general purpose buffer	*/
 		  int 	z;		/* character read in		*/
 	 
-	int		breakp ();	/* signal trapping function	*/
 	int		c;		/* current screen column	*/
 	int		change = 0;	/* true if cmd line option toggled */
 	int		fid;		/* file descriptor 		*/
@@ -234,8 +242,7 @@ char *argv[];
 	extern char *optarg;		/* getopt pointer to opt arg	*/
 
 	extern long getnum ();
-	extern char *instr ();		/* get a string from the cmd line */
-	extern int reset ();		/* exit function - reset terminal */
+	extern char *myinstr ();	/* get a string from the cmd line */
 
 	/* ------------------------------------------------------------ */
 	/* set up signal handling					 */
@@ -333,19 +340,27 @@ char *argv[];
 		alphawin = subwin (stdscr, 16, 16, 4, 57);
 		keypad (alphawin, TRUE);
 		errwin = subwin (stdscr, 1, 80, 23, 0);
+		if (errwin == NULL)
+			errwin = stdscr;
+		if (hexwin == NULL || alphawin == NULL)
+		{
+			fprintf(stderr, "Can't create all necessary curses windows.\n");
+			reset (0);
+			exit (2);
+		}
 
 #ifdef	MOD_HAX
 		/* This is not exactly what the original code does,
 		   but it's good enough.  -r$ */
 		raw();
 #else	/* use original code... */
-		ioctl (0, TCGETA, &asis);
+		tcgetattr (0, &asis);
 		aswas = asis;	/* save termio stuff for later restore */
 		asis.c_cc[VINTR] = '\0';
 		asis.c_iflag &= ~IXON;
 		asis.c_iflag &= ~IXOFF;
 		asis.c_iflag &= ~IXANY;
-		ioctl (0, TCSETA, &asis);
+		tcsetattr (0, TCSANOW, &asis);
 #endif	/* MOD_HAX */
 	}
 
@@ -398,7 +413,7 @@ char *argv[];
 		{
 			position = lseek (fid, ((long )recno) * 256, 0);
 
-			if ((bytes = bread (fid, record, 256, block)) < 0)
+			if ((bytes = bread (fid, (char *)record, 256, block)) < 0)
 			{
 				sprintf(outbuf, "error on reading file %s", filename);
 				errmsg (outbuf, SLEEP_TIME);
@@ -478,7 +493,9 @@ char *argv[];
 				}
 				pbrk = 0;
 				fprintf (stderr, "\007");
-				gets (response);
+				fgets (response, 512, stdin);
+				if ((cp = strchr (response, '\n')))
+					*cp = 0;
 
 				if (pbrk) status = EOF;
 			}
@@ -617,7 +634,7 @@ char *argv[];
 
 			case	'\006':	/* new file (^F) */
 				close (fid);
-				fid = ckfile (cp = instr (), &size);
+				fid = ckfile (cp = myinstr (), &size);
 				if (fid < 0)
 				{
 					fid = ckfile (filename, &size);
@@ -832,7 +849,8 @@ char *argv[];
 				touchwin (alphawin);
 				wrefresh (alphawin);
 
-				while ((z = wgetch (alphawin)) != DEL)
+				while ((z = wgetch (alphawin)) != KEY_DC &&
+				       z != KEY_BACKSPACE)
 				{
 					if (!arrow (z, &r, &c))
 					{
@@ -902,7 +920,8 @@ char *argv[];
 				touchwin (hexwin);
 				wrefresh (hexwin);
 
-				while ((z = wgetch (hexwin)) != DEL)
+				while ((z = wgetch (hexwin)) != KEY_DC
+				       && z != KEY_BACKSPACE)
 				{
 					if (!arrow (z, &r, &c))
 					{
@@ -1083,21 +1102,9 @@ char *argv[];
 /*E*/
 /*checked typing of parameters as declared in fucntion */
 /* versus declarations at call */
-show (bytes, record, filename, size, recno, position,
-	  m,reclen, dump, ebcdic, swab_opt, block, honly)
-int bytes;
-char record[16][16];
-char *filename;
-long size;
-int recno;
-long position;
-char m;
-int reclen;
-int dump;
-int ebcdic;
-int swab_opt;
-int block;
-int honly;
+void
+show (int bytes, char record[16][16], char *filename, long size, int recno, long position,
+	  char m, int reclen, int dump, int ebcdic, int swab_opt, int block, int honly)
 {
 	int		i;
 	int		j;
@@ -1281,7 +1288,7 @@ int honly;
 /*S breakp - set pbrk on interrupt */
 /*H breakp */
 /*E*/
-int breakp (i)
+void breakp (i)
 int i;
 {
 	int s;
@@ -1448,6 +1455,7 @@ char *type;
 /*S ckfile - check on existence, accessibility, and type of file */
 /*H ckfile */
 /*E*/
+int
 ckfile (filename, sizep)
 char	*filename;
 long	*sizep;
@@ -1515,6 +1523,7 @@ long	*sizep;
 /*S dohelp - display help text */
 /*H dohelp */
 /*E*/
+void
 dohelp ()
 {
 	static char *helptxt[] = {
@@ -1592,6 +1601,7 @@ dohelp ()
 /*S reset - reset terminal to original state */
 /*H reset */
 /*E*/
+void
 reset (sig)
 int sig;
 {
@@ -1600,7 +1610,7 @@ int sig;
 		move (23, 0);
 		refresh ();
 #ifndef MOD_HAX
-		ioctl (0, TCSETA, &aswas);
+		tcsetattr (0, TCSANOW, &aswas);
 #endif
 		endwin ();
 	}
@@ -1610,17 +1620,17 @@ int sig;
 		fprintf (stderr, "killed with signal %d\n", sig);
 		exit (sig);
 	}
-	return (0);
 }
 /*S arrow - determine if current character is a cursor control key */
 /*H arrow */
 /*E*/
+int
 arrow (k, r, c)
 register int k;
 register int *r;
 register int *c;
 {
-	register ret = 1;
+	register int ret = 1;
 
 	/* watch out for conflict of VI_* amd KEY_* definitions */
 	if (k == KEY_UP || k == VI_UP)
@@ -1673,6 +1683,7 @@ register int *c;
 /*S dbg_msg - print a debug message */
 /*H dbg_msg */
 /*E*/
+void
 dbg_msg (msg)
 register char *msg;
 {
@@ -1683,11 +1694,11 @@ register char *msg;
 
 	return;
 }
-/*S instr - get a character string from the terminal */
-/*H instr */
+/*S myinstr - get a character string from the terminal */
+/*H myinstr */
 /*E*/
 char *
-instr ()
+myinstr ()
 {
 	static char buf[512];
 
@@ -1815,6 +1826,7 @@ register int hex;
 /*S search - look for an ascii string in the file */
 /*H search */
 /*E*/
+void
 search (fid)
 register int fid;
 {
@@ -1827,13 +1839,13 @@ register int fid;
 	register int matched = 0;
 	register int srch_len;
 
-	register char *cp = instr ();
+	register char *cp = myinstr ();
 	register char *rp;
 
 	int row, col;
 
 	srch_len = strlen (cp);
-	copyrec (record, lrecord, sizeof record);
+	copyrec ((char *)record, lrecord, sizeof record);
 	lrecord[256] = '\0';
 
 	pbrk = 0;
@@ -1875,7 +1887,7 @@ register int fid;
 	{
 		recno = currec;
 		stay = 0;
-		copyrec (record, unch_rec, sizeof record);
+		copyrec ((char *)record, (char *)unch_rec, sizeof record);
 		werase (errwin);
 		touchwin (errwin);
 		wrefresh (errwin);
@@ -1891,6 +1903,7 @@ register int fid;
 }
 /* simplified call to errmsg(), by using sprintf to load format */
 /* sleep_time is not implemented and awaits cleaning up of the signals (?) */
+void
 errmsg (fmt, sleep_time)
 unsigned sleep_time;
 char *fmt;
@@ -1911,7 +1924,7 @@ char *fmt;
 	}
 	else
 	{
-		fprintf (stderr, fmt);
+		fprintf (stderr, "%s", fmt);
 		fprintf (stderr, "\n");
 	}
 	/* signal problem ?? if sleep called
@@ -1921,16 +1934,17 @@ char *fmt;
 	return;
 }
 /* simplified call to outstr(), by using sprintf to load format */
+void
 outstr (fmt)
 char *fmt;
 {
-	if (dump) printf (fmt);
-	else printw (fmt);
+	if (dump) printf ("%s", fmt);
+	else printw ("%s", fmt);
 
 	return;
 }
-outch (ch)
-register char ch;
+void
+outch (register char ch)
 {
 	if (dump) putchar (ch);
 	else addch (ch);
