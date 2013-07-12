--- src-IL/src/il_png.c.orig	2009-03-08 08:10:09.000000000 +0100
+++ src-IL/src/il_png.c	2010-03-29 08:49:16.000000000 +0200
@@ -105,7 +105,7 @@
 	Read = iread(Signature, 1, 8);
 	iseek(-Read, IL_SEEK_CUR);
 
-	return png_check_sig(Signature, 8);
+	return !png_sig_cmp(Signature, 0, 8);
 }
 
 
@@ -278,7 +278,7 @@
 
 	// Expand low-bit-depth grayscale images to 8 bits
 	if (png_color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8) {
-		png_set_gray_1_2_4_to_8(png_ptr);
+		png_set_expand_gray_1_2_4_to_8(png_ptr);
 	}
 
 	// Expand RGB images with transparency to full alpha channels
