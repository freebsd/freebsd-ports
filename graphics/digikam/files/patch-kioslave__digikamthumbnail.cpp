--- digikam/kioslave/digikamthumbnail.cpp.orig	2009-07-03 07:19:41.000000000 +0200
+++ digikam/kioslave/digikamthumbnail.cpp	2012-05-04 00:15:30.000000000 +0200
@@ -94,6 +94,7 @@
 #include <sys/shm.h>
 #include <sys/time.h>
 #include <png.h>
+#include <pngpriv.h>
 }
 
 using namespace KIO;
@@ -370,7 +371,7 @@
     unsigned char buf[PNG_BYTES_TO_CHECK];
 
     fread(buf, 1, PNG_BYTES_TO_CHECK, f);
-    if (!png_check_sig(buf, PNG_BYTES_TO_CHECK))
+    if (png_sig_cmp(buf, 0, PNG_BYTES_TO_CHECK))
     {
         fclose(f);
         return qimage;
@@ -392,7 +393,7 @@
         return qimage;
     }
 
-    if (setjmp(png_ptr->jmpbuf))
+    if (setjmp(png_jmpbuf(png_ptr)))
     {
         png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
         fclose(f);
@@ -465,7 +466,7 @@
     {
         png_set_gray_to_rgb(png_ptr);
         if (png_get_bit_depth(png_ptr, info_ptr) < 8)
-            png_set_gray_1_2_4_to_8(png_ptr);
+            png_set_expand_gray_1_2_4_to_8(png_ptr);
     }
 
     int sizeOfUint = sizeof(unsigned int);
