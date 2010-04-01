--- krita/plugins/filters/cimg/CImg.h.orig	2007-05-30 23:40:02.000000000 +0200
+++ krita/plugins/filters/cimg/CImg.h	2010-04-01 13:09:06.000000000 +0200
@@ -14840,7 +14840,7 @@
       png_uint_32 width, height;
       int bit_depth, color_type, interlace_type;
       png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, &interlace_type,
-		   int_p_NULL, int_p_NULL);
+		   NULL, NULL);
       int new_bit_depth = bit_depth;
       int new_color_type = color_type;
       
@@ -14851,7 +14851,7 @@
 	new_bit_depth = 8;
       }
       if (new_color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8){
-	png_set_gray_1_2_4_to_8(png_ptr);
+	png_set_extend_gray_1_2_4_to_8(png_ptr);
 	new_bit_depth = 8;
       }
       if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
