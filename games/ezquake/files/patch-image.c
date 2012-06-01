--- image.c.orig	2012-05-03 06:08:56.000000000 +0200
+++ image.c	2012-05-03 06:20:20.000000000 +0200
@@ -534,7 +534,7 @@
 static void (*qpng_write_info)(png_structp, png_infop);
 static void (*qpng_read_info)(png_structp, png_infop);
 static void (*qpng_set_expand)(png_structp);
-static void (*qpng_set_gray_1_2_4_to_8)(png_structp);
+static void (*qpng_set_expand_gray_1_2_4_to_8)(png_structp);
 static void (*qpng_set_palette_to_rgb)(png_structp);
 static void (*qpng_set_tRNS_to_alpha)(png_structp);
 static void (*qpng_set_gray_to_rgb)(png_structp);
@@ -570,7 +570,7 @@
 	{"png_write_info", (void **) &qpng_write_info},
 	{"png_read_info", (void **) &qpng_read_info},
 	{"png_set_expand", (void **) &qpng_set_expand},
-	{"png_set_gray_1_2_4_to_8", (void **) &qpng_set_gray_1_2_4_to_8},
+	{"png_set_expand_gray_1_2_4_to_8", (void **) &qpng_set_gray_1_2_4_to_8},
 	{"png_set_palette_to_rgb", (void **) &qpng_set_palette_to_rgb},
 	{"png_set_tRNS_to_alpha", (void **) &qpng_set_tRNS_to_alpha},
 	{"png_set_gray_to_rgb", (void **) &qpng_set_gray_to_rgb},
@@ -734,7 +734,7 @@
 		return NULL;
 	}
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		qpng_destroy_read_struct(&png_ptr, &pnginfo, NULL);
 #ifndef WITH_FTE_VFS
 		fclose(fin);
@@ -784,7 +784,7 @@
 	}
 
 	if (colortype == PNG_COLOR_TYPE_GRAY && bitdepth < 8) 
-		qpng_set_gray_1_2_4_to_8(png_ptr);
+		qpng_set_expand_gray_1_2_4_to_8(png_ptr);
 	
 	if (qpng_get_valid(png_ptr, pnginfo, PNG_INFO_tRNS))	
 		qpng_set_tRNS_to_alpha(png_ptr);
@@ -888,7 +888,7 @@
 		return false;
 	}
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		qpng_destroy_write_struct(&png_ptr, &info_ptr);
 #ifndef WITH_FTE_VFS
 		fclose(fp);
@@ -983,7 +983,7 @@
 		return false;
 	}
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		qpng_destroy_write_struct(&png_ptr, &info_ptr);
 #ifndef WITH_FTE_VFS
 		fclose(fp);
@@ -1158,7 +1158,7 @@
 
 	// Set the return adress that PNGLib should return to if
 	// an error occurs during reading.
-	if (setjmp(png_ptr->jmpbuf)) 
+	if (setjmp(png_jmpbuf(png_ptr))) 
 	{
 		png_destroy_read_struct(&png_ptr, &pnginfo, NULL);
 #ifndef WITH_FTE_VFS
@@ -1233,7 +1233,7 @@
 
 		if (colortype == PNG_COLOR_TYPE_GRAY && bitdepth < 8) 
 		{
-			png_set_gray_1_2_4_to_8(png_ptr);
+			png_set_expand_gray_1_2_4_to_8(png_ptr);
 		}
 		
 		if (png_get_valid(png_ptr, pnginfo, PNG_INFO_tRNS))	
@@ -1281,7 +1281,7 @@
 			if (!png_get_hIST(png_ptr, pnginfo, &histogram))
 				histogram = NULL;
 
-			png_set_dither(png_ptr, quake_pal, 256, 256, histogram, true);
+			png_set_quantize(png_ptr, quake_pal, 256, 256, histogram, true);
 		}
 		#endif // !GLQUAKE
 
@@ -1507,7 +1507,7 @@
 		return false;
 	}
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		png_destroy_write_struct(&png_ptr, &info_ptr);
 #ifndef WITH_FTE_VFS
 		fclose(fp);
@@ -1598,7 +1598,7 @@
 		return false;
 	}
 
-	if (setjmp(png_ptr->jmpbuf)) {
+	if (setjmp(png_jmpbuf(png_ptr))) {
 		png_destroy_write_struct(&png_ptr, &info_ptr);
 #ifndef WITH_FTE_VFS
 		fclose(fp);
@@ -2360,7 +2360,7 @@
 }
 
 GLOBAL(void)
-jpeg_mem_src (j_decompress_ptr cinfo, byte * infile, int maxlen)
+local_jpeg_mem_src (j_decompress_ptr cinfo, byte * infile, int maxlen)
 {
 	my_source_mgr *src;
 
@@ -2471,7 +2471,7 @@
 
 	jpeg_create_decompress(&cinfo);
 
-	jpeg_mem_src(&cinfo, infile, length);
+	local_jpeg_mem_src(&cinfo, infile, length);
 
 	(void) jpeg_read_header(&cinfo, TRUE);  
 
