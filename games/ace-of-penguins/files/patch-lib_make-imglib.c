--- lib/make-imglib.c.orig	2012-03-24 18:00:49 UTC
+++ lib/make-imglib.c
@@ -86,7 +86,7 @@ scan_image_directory ()
     png_ptr = png_create_read_struct (PNG_LIBPNG_VER_STRING, 0, 0, 0);
     info_ptr = png_create_info_struct (png_ptr);
 
-    if (setjmp (png_ptr->jmpbuf)) {
+    if (setjmp (png_jmpbuf(png_ptr))) {
       fclose (f);
       continue;
     }
@@ -202,7 +202,7 @@ tokenize(char *string)
   char *rv;
   if (string) {
     next = string;
-    return;
+    return NULL;
   }
   while (*next && !isgraph(*next)) next++;
   if (!*next) return 0;
