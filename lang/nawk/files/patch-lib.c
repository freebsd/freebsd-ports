--- lib.c.orig	Tue Jul  3 15:00:23 2007
+++ lib.c	Tue Jul  3 15:00:28 2007
@@ -40,7 +40,7 @@
 int	fieldssize = RECSIZE;
 
 Cell	**fldtab;	/* pointers to Cells */
-char	inputFS[10] = " ";
+char	inputFS[100] = " ";
 
 #define	MAXFLD	2
 int	nfields	= MAXFLD;	/* last allocated slot for $i */
