--- arc.c.orig	2010-08-07 13:06:42 UTC
+++ arc.c
@@ -298,7 +298,7 @@ main(num, arg)			/* system entry point *
 			keepbak = 1;
 
 		else if (*a == 'W')	/* suppress warnings */
-			warn = 0;
+			arcwarn = 0;
 #if	!DOS
 		else if (*a == 'I')	/* image mode, no ASCII/EBCDIC x-late */
 			image = !image;
@@ -434,7 +434,7 @@ static	VOID
 expandlst(n)			/* expand an indirect reference */
 	int		n;	/* number of entry to expand */
 {
-	FILE	       *lf, *fopen();	/* list file, opener */
+	FILE	       *lf;	/* list file, opener */
 	char		buf[100];	/* input buffer */
 	int		x;	/* index */
 	char	       *p = lst[n] + 1; /* filename pointer */
