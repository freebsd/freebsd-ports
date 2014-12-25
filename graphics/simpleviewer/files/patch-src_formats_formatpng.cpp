--- src/formats/formatpng.cpp.orig	2010-08-29 14:33:33 UTC
+++ src/formats/formatpng.cpp
@@ -57,9 +57,9 @@ bool CFormatPng::Load(const char* filena
 	png_read_info(png, info);
 
 	// get real bits per pixel
-	m_bppImage	= info->pixel_depth;
+	m_bppImage	= png_get_bit_depth(png, info) * png_get_channels(png, info);
 
-	if(info->color_type == PNG_COLOR_TYPE_PALETTE) {
+	if(png_get_color_type(png, info) == PNG_COLOR_TYPE_PALETTE) {
 		png_set_palette_to_rgb(png);
 	}
 
@@ -73,20 +73,20 @@ bool CFormatPng::Load(const char* filena
     if(png_get_valid(png, info, PNG_INFO_tRNS)) {
         png_set_tRNS_to_alpha(png);
     }
-	if(info->bit_depth == 16) {
+	if(png_get_bit_depth(png, info) == 16) {
 		png_set_strip_16(png);
 	}
-	if(info->color_type == PNG_COLOR_TYPE_GRAY || info->color_type == PNG_COLOR_TYPE_GRAY_ALPHA) {
+	if(png_get_color_type(png, info) == PNG_COLOR_TYPE_GRAY || png_get_color_type(png, info) == PNG_COLOR_TYPE_GRAY_ALPHA) {
 		png_set_gray_to_rgb(png);
 	}
 
 //	int number_of_passes	= png_set_interlace_handling(png);
 	png_read_update_info(png, info);
 
-	m_width		= info->width;
-	m_height	= info->height;
-	m_pitch		= info->rowbytes;
-	m_bpp		= info->pixel_depth;
+	m_width		= png_get_image_width(png, info);
+	m_height	= png_get_image_height(png, info);
+	m_pitch		= png_get_rowbytes(png, info);
+	m_bpp		= png_get_bit_depth(png, info) * png_get_channels(png, info);
 
 	// read file
 	if(setjmp(png_jmpbuf(png)) != 0) {
@@ -98,7 +98,7 @@ bool CFormatPng::Load(const char* filena
 	// create buffer and read data
 	png_bytep* row_pointers	= new png_bytep[m_height];
 	for(int y = 0; y < m_height; y++) {
-		row_pointers[y]	= new png_byte[info->rowbytes];
+		row_pointers[y]	= new png_byte[png_get_rowbytes(png, info)];
 	}
 	png_read_image(png, row_pointers);
 
@@ -106,7 +106,7 @@ bool CFormatPng::Load(const char* filena
 	m_sizeMem	= m_pitch * m_height;
 	m_bitmap	= new unsigned char[m_sizeMem];
 
-	if(info->color_type == PNG_COLOR_TYPE_RGB) {
+	if(png_get_color_type(png, info) == PNG_COLOR_TYPE_RGB) {
 		m_format	= GL_RGB;
 		for(int y = 0; y < m_height; y++) {
 			int dst	= y * m_pitch;
@@ -123,7 +123,7 @@ bool CFormatPng::Load(const char* filena
 			delete[] row_pointers[y];
 		}
 	}
-	else if(info->color_type == PNG_COLOR_TYPE_RGB_ALPHA) {
+	else if(png_get_color_type(png, info) == PNG_COLOR_TYPE_RGB_ALPHA) {
 		m_format	= GL_RGBA;
 		for(int y = 0; y < m_height; y++) {
 			int dst	= y * m_pitch;
