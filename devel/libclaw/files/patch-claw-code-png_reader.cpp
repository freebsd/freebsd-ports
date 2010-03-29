--- claw/code/png_reader.cpp.orig	2008-07-08 11:52:14.000000000 +0200
+++ claw/code/png_reader.cpp	2010-03-29 09:25:03.000000000 +0200
@@ -146,7 +146,7 @@
     {
       /* If we get here, we had a problem reading the file */
       /* Free all of the memory associated with the png_ptr and info_ptr */
-      png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
+      png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
       throw CLAW_EXCEPTION("Invalid PNG file.");
     }
       
@@ -156,7 +156,7 @@
                    claw__graphic__png__source_manager__read );
 
   png_set_strip_16(png_ptr);
-  png_set_gray_1_2_4_to_8(png_ptr);
+  png_set_expand_gray_1_2_4_to_8(png_ptr);
   png_set_packing(png_ptr);
 
   // transform palette index into RGB value
@@ -169,7 +169,7 @@
   png_read_info(png_ptr, info_ptr);
   read_image( png_ptr, info_ptr );
       
-  png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
+  png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
 } // png::reader::read_from_file()
 
 /*----------------------------------------------------------------------------*/
@@ -339,7 +339,7 @@
       info_ptr = png_create_info_struct(png_ptr);
 
       if (!info_ptr)
-        png_destroy_read_struct(&png_ptr, png_infopp_NULL, png_infopp_NULL);
+        png_destroy_read_struct(&png_ptr, NULL, NULL);
     }
 
   if (!png_ptr || !info_ptr)
