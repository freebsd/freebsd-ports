--- loadbmp.c.orig	Sun May  5 04:09:25 1996
+++ loadbmp.c	Tue Jul 11 21:30:24 2000
@@ -5,6 +5,9 @@
  * Copyleft  (c) 1994-1996  Software Research Academy                   *
  ************************************************************************/
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/param.h>
 #include <X11/Xlib.h>
 #include "sxsame.h"
 
@@ -37,17 +40,24 @@
 	int c, c1,c2;
 	int width, height, planes, ncol;
 	int *col;
-	char fname[256];
+	char fname[MAXPATHLEN];
 
 	Pixmap w;
 	GC gc;
 	int i, j, k;
 
+	if (MAXPATHLEN <= strlen(bmpname) ) {
+		fprintf(stderr,"Error: BMP file name too long.\n");
+		return -1;
+	}
 	strcpy(fname,bmpname);
 	fp = fopen(fname,"rb");
 	if(fp == NULL)
 	{
-		sprintf(fname, "%s/%s", SAME_DIR, bmpname);
+		if (MAXPATHLEN <= snprintf(fname, MAXPATHLEN, "%s/%s", SAME_DIR, bmpname)) {
+			fprintf(stderr,"Error: BMP file name too long.\n");
+			return -1;
+		}
 		fp = fopen(fname, "r");
 		if(fp == NULL)
 		{
