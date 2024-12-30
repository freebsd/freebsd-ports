--- src/SDL/i_sshot.c.orig	2008-10-18 13:32:29 UTC
+++ src/SDL/i_sshot.c
@@ -231,7 +231,7 @@ int I_ScreenShot (const char *fname)
   if (fp)
   {
     png_struct *png_ptr = png_create_write_struct(
-        PNG_LIBPNG_VER_STRING, png_error_ptr_NULL, error_fn, warning_fn);
+        PNG_LIBPNG_VER_STRING, NULL, error_fn, warning_fn);
 
     if (png_ptr)
     {
@@ -279,7 +279,7 @@ int I_ScreenShot (const char *fname)
             break;
         }
       }
-      png_destroy_write_struct(&png_ptr,  png_infopp_NULL);
+      png_destroy_write_struct(&png_ptr,  NULL);
     }
     fclose(fp);
   }
