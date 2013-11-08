--- src/image_cache.c.orig	2013-11-07 19:24:24.056322038 +0400
+++ src/image_cache.c	2013-11-07 19:32:26.759288924 +0400
@@ -356,7 +356,7 @@
   save_file = NULL;
   cl        = NULL;
 
-  if (tp->cache.cache_dir == NULL) { return; }
+  if (tp->cache.cache_dir == NULL) { return FALSE; }
 
   save_file = (gchar*)malloc(sizeof(gchar) * 
                              (strlen(tp->cache.cache_dir) +
@@ -761,9 +761,9 @@
    /* Initialize the local variables. */
    png_text_filename = buffer = NULL;
 
-   if (pixbuf == NULL)   { return; }
-   if (filename == NULL) { return; }
-   if (strcmp(filename, "") == 0) { return; }
+   if (pixbuf == NULL)   { return FALSE; }
+   if (filename == NULL) { return FALSE; }
+   if (strcmp(filename, "") == 0) { return FALSE; }
 
    fp = fopen (filename, "wb");
    if (fp == NULL) { return FALSE; }
@@ -782,7 +782,7 @@
       return FALSE;
    }
 
-   if (setjmp (png_ptr->jmpbuf)) {
+   if (setjmp (png_jmpbuf(png_ptr))) {
       png_destroy_write_struct(&png_ptr, &info_ptr);
       fclose (fp);
       return FALSE;
@@ -839,7 +839,7 @@
          /* expand RGB to RGBA using an opaque alpha value */
          gint x;
          gchar *buffer_ptr = buffer;
-         gchar *source_ptr = pixels;
+         guchar *source_ptr = pixels;
          for (x = 0; x < width; x++) {
             *buffer_ptr++ = *source_ptr++;
             *buffer_ptr++ = *source_ptr++;
