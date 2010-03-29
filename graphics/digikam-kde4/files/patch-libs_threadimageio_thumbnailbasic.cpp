--- libs/threadimageio/thumbnailbasic.cpp.orig 2010-01-31 15:21:53.000000000 +0200
+++ libs/threadimageio/thumbnailbasic.cpp      2010-03-29 10:40:10.024395457 +0300
@@ -137,7 +137,7 @@
     unsigned char buf[PNG_BYTES_TO_CHECK];

     size_t itemsRead = fread(buf, 1, PNG_BYTES_TO_CHECK, f);
-    if (itemsRead != 1 || !png_check_sig(buf, PNG_BYTES_TO_CHECK))
+    if (itemsRead != 1 || png_sig_cmp(buf, 0, PNG_BYTES_TO_CHECK))
     {
         fclose(f);
         return qimage;
@@ -232,7 +232,7 @@
     {
         png_set_gray_to_rgb(png_ptr);
         if (png_get_bit_depth(png_ptr, info_ptr) < 8)
-            png_set_gray_1_2_4_to_8(png_ptr);
+            png_set_expand_gray_1_2_4_to_8(png_ptr);
     }

     int sizeOfUint = sizeof(unsigned int);
