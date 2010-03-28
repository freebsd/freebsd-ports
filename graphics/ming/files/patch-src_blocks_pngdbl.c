--- src/blocks/pngdbl.c.orig	2006-02-08 20:09:27.000000000 +0100
+++ src/blocks/pngdbl.c	2010-03-28 20:34:13.000000000 +0200
@@ -34,7 +34,7 @@
 
 	if(fread(header, 1, 8, fp) != 8)
 		return NULL;
-	if(!png_check_sig(header, 8))
+	if(png_sig_cmp(header, 0, 8))
 		return NULL;
 	result = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
 	if(!result)
@@ -54,7 +54,7 @@
 	
 	if(SWFInput_read(input, header, 8) != 8)
 		return NULL;
-	if(!png_check_sig(header, 8))
+	if(png_sig_cmp(header, 0, 8))
 		return NULL;
 	result = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
 	if(!result)
