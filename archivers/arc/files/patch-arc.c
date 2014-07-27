--- arc.c.orig	Sun Oct  9 03:38:22 2005
+++ arc.c	Fri Oct 14 14:22:38 2005
@@ -290,7 +290,7 @@
 			keepbak = 1;
 
 		else if (*a == 'W')	/* suppress warnings */
-			warn = 0;
+			arcwarn = 0;
 #if	!DOS
 		else if (*a == 'I')	/* image mode, no ASCII/EBCDIC x-late */
 			image = !image;
@@ -426,7 +426,7 @@
 expandlst(n)			/* expand an indirect reference */
 	int		n;	/* number of entry to expand */
 {
-	FILE	       *lf, *fopen();	/* list file, opener */
+	FILE	       *lf;	/* list file, opener */
 	char		buf[100];	/* input buffer */
 	int		x;	/* index */
 	char	       *p = lst[n] + 1; /* filename pointer */
