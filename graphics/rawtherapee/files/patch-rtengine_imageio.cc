--- rtengine/imageio.cc.orig	2009-12-31 21:43:22.000000000 +0100
+++ rtengine/imageio.cc	2010-03-29 18:32:58.000000000 +0200
@@ -151,7 +151,7 @@
 	//reading PNG header
 	unsigned char header[8];
 	fread (header, 1, 8, file);
-	if (!png_check_sig (header, 8)) {
+	if (png_sig_cmp (header, 0, 8)) {
 		fclose(file);
 		return IMIO_HEADERERROR;
 	}
@@ -184,7 +184,7 @@
     embProfile = NULL;
 
 	//retrieving image information
-	unsigned long width,height;
+	png_uint_32 width,height;
 	int bit_depth,color_type,interlace_type,compression_type,filter_method;
 	png_get_IHDR(png,info,&width,&height,&bit_depth,&color_type,&interlace_type,
 		&compression_type, &filter_method);
