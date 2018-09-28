--- src/zlinux.c.orig	2004-05-21 20:59:29 UTC
+++ src/zlinux.c
@@ -10,7 +10,6 @@
 
 #include <sys/types.h>		/* needed before sys/param.h is included */
 #include <errno.h>		/* define errno */
-#include <malloc.h>		/* malloc() and realloc() */
 #include <signal.h>		/* to catch ^C and ^Z signals */
 #include <stdio.h>		/* define stdin */
 #include <string.h>		/* strncpy(), strlen(), etc. */
@@ -50,8 +49,6 @@ char 	*tgetstr();		/* get str value of a
 
 static int vernum();		/* see bottom of this file */
 
-extern	int sys_nerr;		/* number of system error messages */
-
 static	int SupGotCtC = 0;
 
 static glob_t pglob;
@@ -1057,9 +1054,9 @@ char *argv[];
  * execute imbedded command line-parsing macro directly from clpars[]
  */
 
-	CStBeg = clpars;		/* command string start */
-	CBfPtr = clpars;		/* command string start */
-	CStEnd = clpars + CLPARS_LEN;		/* command string end */
+	CStBeg = (charptr)clpars;		/* command string start */
+	CBfPtr = (charptr)clpars;		/* command string start */
+	CStEnd = (charptr)((unsigned int)clpars + CLPARS_LEN);		/* command string end */
 	EStTop = EStBot;			/* clear expression stack */
 	ExeCSt();				/* execute command string */
 
