--- libs/3rdparty/cimg/CImg.h.orig     2010-01-31 15:22:15.000000000 +0200
+++ libs/3rdparty/cimg/CImg.h  2010-03-29 10:42:42.741492686 +0300
@@ -29449,7 +29449,7 @@
         new_bit_depth = 8;
       }
       if (new_color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8){
-        png_set_gray_1_2_4_to_8(png_ptr);
+        png_set_expand_gray_1_2_4_to_8(png_ptr);
         new_bit_depth = 8;
       }
       if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
