--- src/readpng.c.orig	2010-04-18 11:36:49.000000000 +0900
+++ src/readpng.c	2010-09-14 03:27:35.000000000 +0900
@@ -33,7 +33,7 @@
 	png_uint_32 width, height;
 
 	fread(sig, 1, 8, infile);
-	if (!png_check_sig((png_bytep)sig, 8))
+	if (png_sig_cmp((png_bytep)sig, 0, 8))
 		return FALSE;
 
 	*png_struct = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
