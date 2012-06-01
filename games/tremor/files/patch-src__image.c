--- image.c.orig	2005-03-25 21:39:36.000000000 +0100
+++ image.c	2012-05-01 09:41:47.000000000 +0200
@@ -20,6 +20,7 @@
 // image.c -- handling images
 
 #include "quakedef.h"
+#include "zlib.h"
 
 #define	IMAGE_MAX_DIMENSIONS	4096
 
@@ -489,7 +490,7 @@
 		return NULL;
 	}
 
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		png_destroy_read_struct (&png_ptr, &pnginfo, NULL);
 		fclose (fin);
@@ -523,7 +524,7 @@
 	}
 
 	if (colortype == PNG_COLOR_TYPE_GRAY && bitdepth < 8)
-		png_set_gray_1_2_4_to_8 (png_ptr);
+		png_set_expand_gray_1_2_4_to_8 (png_ptr);
 	
 	if (png_get_valid(png_ptr, pnginfo, PNG_INFO_tRNS))
 		png_set_tRNS_to_alpha (png_ptr);
@@ -609,7 +610,7 @@
 		return false;
 	}
 
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		png_destroy_write_struct (&png_ptr, &info_ptr);
 		fclose (fp);
