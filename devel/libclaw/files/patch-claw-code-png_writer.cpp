--- claw/code/png_writer.cpp.orig	2008-07-08 11:52:14.000000000 +0200
+++ claw/code/png_writer.cpp	2010-03-29 10:14:49.000000000 +0200
@@ -296,7 +296,7 @@
       info_ptr = png_create_info_struct(png_ptr);
 
       if (!info_ptr)
-        png_destroy_write_struct(&png_ptr, png_infopp_NULL);
+        png_destroy_write_struct(&png_ptr, NULL);
     }
 
   if (!png_ptr || !info_ptr)
