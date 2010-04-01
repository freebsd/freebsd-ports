--- src/gfx/vsimage.cpp.orig	2008-04-24 14:12:37.000000000 +0200
+++ src/gfx/vsimage.cpp	2010-03-31 16:39:55.000000000 +0200
@@ -147,7 +147,7 @@
 	unsigned char sig[8];
 	file->Begin();
 	file->Read(sig, 8);
-	if (!png_check_sig(sig, 8))
+	if (png_sig_cmp(sig, 0, 8))
 		ret = BadFormat;
 	
 	return ret;
@@ -349,7 +349,7 @@
 		png_set_palette_to_rgb(png_ptr);
 		   
 	if (this->img_color_type == PNG_COLOR_TYPE_GRAY && this->img_depth < 8)
-		png_set_gray_1_2_4_to_8(png_ptr);
+		png_set_expand_gray_1_2_4_to_8(png_ptr);
 
 	png_set_expand (png_ptr);
 	png_read_update_info (png_ptr,info_ptr);
