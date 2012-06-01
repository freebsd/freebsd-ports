--- gl_image.c.orig	2012-04-27 12:56:30.000000000 +0200
+++ gl_image.c	2012-04-27 12:58:31.000000000 +0200
@@ -21,6 +21,7 @@
 
 #include "quakedef.h"
 #include <png.h>
+#include <zlib.h>
 
 int	image_width, image_height;
 
@@ -470,7 +471,7 @@
 		return NULL;
 	}
 
-	if (setjmp(png->jmpbuf))
+	if (setjmp(png_jmpbuf(png)))
 	{
 		png_destroy_read_struct (&png, &pnginfo, NULL);
 		fclose (fin);
@@ -496,7 +497,7 @@
 	}
 
 	if (colortype == PNG_COLOR_TYPE_GRAY && bitdepth < 8)
-		png_set_gray_1_2_4_to_8 (png);
+		png_set_expand_gray_1_2_4_to_8 (png);
 	
 	if (png_get_valid(png, pnginfo, PNG_INFO_tRNS))
 		png_set_tRNS_to_alpha (png);
@@ -582,7 +583,7 @@
 		return false;
 	}
 
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		png_destroy_write_struct (&png_ptr, &info_ptr);
 		fclose (fp);
