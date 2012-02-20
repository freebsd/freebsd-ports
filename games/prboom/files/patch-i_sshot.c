--- src/SDL/i_sshot.c.orig	2010-05-19 13:40:36.506099313 +0300
+++ src/SDL/i_sshot.c	2010-05-19 13:41:50.837973800 +0300
@@ -231,7 +231,7 @@
   if (fp)
   {
     png_struct *png_ptr = png_create_write_struct(
-        PNG_LIBPNG_VER_STRING, png_error_ptr_NULL, error_fn, warning_fn);
+        PNG_LIBPNG_VER_STRING, NULL, error_fn, warning_fn);

     if (png_ptr)
     {
@@ -279,7 +279,7 @@
             break;
         }
       }
-      png_destroy_write_struct(&png_ptr,  png_infopp_NULL);
+      png_destroy_write_struct(&png_ptr,  NULL);
     }
     fclose(fp);
   }
