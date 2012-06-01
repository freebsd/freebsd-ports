--- src/render/r_surface.c.orig	2008-12-26 20:15:17.000000000 +0100
+++ src/render/r_surface.c	2012-05-09 12:14:42.000000000 +0200
@@ -269,7 +269,7 @@
         png_set_read_fn(png_ptr, (voidp)&file, (png_rw_ptr)user_png_read);
 
         /* If an error occurs in libpng, it will longjmp back here */
-        if (setjmp(png_ptr->jmpbuf)) {
+        if (setjmp(png_jmpbuf(png_ptr))) {
                 C_warning("Error loading PNG '%s'", filename);
                 goto cleanup;
         }
@@ -397,7 +397,7 @@
                          (png_flush_ptr)user_png_flush);
 
         /* If an error occurs in libpng, it will longjmp back here */
-        if (setjmp(png_ptr->jmpbuf)) {
+        if (setjmp(png_jmpbuf(png_ptr))) {
                 C_warning("Error saving PNG '%s'", filename);
                 goto cleanup;
         }
