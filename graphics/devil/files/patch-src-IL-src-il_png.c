--- src-IL/src/il_png.c.orig	Thu Jun 24 11:38:54 2004
+++ src-IL/src/il_png.c	Wed Oct  5 22:44:17 2005
@@ -282,11 +282,11 @@
 
 ILboolean readpng_get_image(ILdouble display_exponent)
 {
-	ILuint		i;
 	png_bytepp	row_pointers = NULL;
-	ILuint		width, height, channels;
-	ILdouble	screen_gamma = 1.0, image_gamma;
-	ILuint		bit_depth;
+	png_uint_32   width, height;
+	ILuint      i, channels, bit_depth;
+	ILdouble      screen_gamma = 1.0, image_gamma;
+
 
 
 	/* setjmp() must be called in every function that calls a PNG-reading
