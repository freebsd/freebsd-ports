--- objconv/basemaker/base_maker_texture.cpp.orig	2008-04-24 14:12:53.000000000 +0200
+++ objconv/basemaker/base_maker_texture.cpp	2010-04-01 06:40:29.000000000 +0200
@@ -73,7 +73,7 @@
 		png_set_palette_to_rgb(png_ptr);
 
 	if (ctype == PNG_COLOR_TYPE_GRAY && data->bpp < 8)
-		png_set_gray_1_2_4_to_8(png_ptr);
+		png_set_expand_gray_1_2_4_to_8(png_ptr);
 
 	png_set_expand (png_ptr);
 	png_read_update_info (png_ptr,info_ptr);
@@ -211,7 +211,7 @@
 		unsigned char sig[8];
 		fread(sig, sizeof(char), 8, fp);
 		fseek(fp,0,SEEK_SET);
-		if (png_check_sig(sig, 8)) {
+		if (!png_sig_cmp(sig, 0, 8)) {
 			return FORMAT_PNG;
 		}
 	}
