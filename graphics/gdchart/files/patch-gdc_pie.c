--- gdc_pie.c.orig	Fri Nov 13 05:00:55 1998
+++ gdc_pie.c	Mon Jun  4 02:42:16 2001
@@ -1,7 +1,7 @@
 /* GDCHART 0.94b  GDC_PIE.C  12 Nov 1998 */
 
 #include <stdio.h>
-#include <values.h>
+#include <limits.h>
 #include <math.h>
 
 #define GDC_INCL
@@ -610,7 +610,7 @@
 		rad -= GDCPIE_label_dist;
 		}
 
-	gdImageGif(im, gif_fptr);
+	gdImagePng(im, gif_fptr);
 
 	gdImageDestroy(im);
 	return;
