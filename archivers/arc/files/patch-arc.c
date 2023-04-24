--- arc.c.orig	2013-06-27 02:00:19 UTC
+++ arc.c
@@ -280,7 +280,7 @@ main(num, arg)			/* system entry point */
 			keepbak = 1;
 
 		else if (*a == 'W')	/* suppress warnings */
-			warn = 0;
+			arcwarn = 0;
 #if	!DOS
 		else if (*a == 'I')	/* image mode, no ASCII/EBCDIC x-late */
 			image = !image;
@@ -416,7 +416,7 @@ expandlst(n)			/* expand an indirect reference */
 expandlst(n)			/* expand an indirect reference */
 	int		n;	/* number of entry to expand */
 {
-	FILE	       *lf, *fopen();	/* list file, opener */
+	FILE	       *lf;	/* list file, opener */
 	char		buf[100];	/* input buffer */
 	int		x;	/* index */
 	char	       *p = lst[n] + 1; /* filename pointer */
