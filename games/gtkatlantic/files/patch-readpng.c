--- src/readpng.c.orig	2004-06-25 09:02:45.000000000 +0200
+++ src/readpng.c	2010-03-30 14:01:35.000000000 +0200
@@ -33,7 +33,7 @@
 	png_uint_32 width, height;
 
 	fread(sig, 1, 8, infile);
-	if (!png_check_sig(sig, 8))
+	if (png_sig_cmp(sig, 0, 8))
 		return FALSE;
 
 	*png_struct = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
