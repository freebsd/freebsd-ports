--- glpng.c.orig	2000-07-10 21:27:10.000000000 +0200
+++ glpng.c	2012-04-27 08:58:12.000000000 +0200
@@ -25,11 +25,11 @@
 	#include <windows.h>
 #endif
 
+#include "png.h"
 #include <GL/glpng.h>
 #include <GL/gl.h>
 #include <stdlib.h>
 #include <math.h>
-#include "png/png.h"
 
 /* Used to decide if GL/gl.h supports the paletted extension */
 #ifdef GL_COLOR_INDEX1_EXT
@@ -269,14 +269,14 @@
 	if (pinfo == NULL) return 0;
 
 	fread(header, 1, 8, fp);
-	if (!png_check_sig(header, 8)) return 0;
+	if (png_sig_cmp(header, 0, 8)) return 0;
 
 	png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
 	info = png_create_info_struct(png);
 	endinfo = png_create_info_struct(png);
 
 	// DH: added following lines
-	if (setjmp(png->jmpbuf))
+	if (setjmp(png_jmpbuf(png)))
 	{
 		png_destroy_read_struct(&png, &info, &endinfo);
 		return 0;
@@ -373,14 +373,14 @@
 	png_uint_32 i;
 
 	fread(header, 1, 8, fp);
-	if (!png_check_sig(header, 8)) return 0;
+	if (png_sig_cmp(header, 0, 8)) return 0;
 
 	png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
 	info = png_create_info_struct(png);
 	endinfo = png_create_info_struct(png);
 
 	// DH: added following lines
-	if (setjmp(png->jmpbuf))
+	if (setjmp(png_jmpbuf(png)))
 	{
 		png_destroy_read_struct(&png, &info, &endinfo);
 		return 0;
