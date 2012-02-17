---pngrutil.c.orig	2012/02/10 19:43:42	121491
+++ pngrutil.c	2012/02/10 19:45:46	121492
@@ -363,8 +363,15 @@
       {
          /* Success (maybe) - really uncompress the chunk. */
          png_size_t new_size = 0;
-         png_charp text = png_malloc_warn(png_ptr,
-                        prefix_size + expanded_size + 1);
+         png_charp text = NULL;
+         /* Need to check for both truncation (64-bit platforms) and integer
+          * overflow.
+          */
+         if (prefix_size + expanded_size > prefix_size &&
+             prefix_size + expanded_size < 0xffffffffU)
+         {
+            text = png_malloc_warn(png_ptr, prefix_size + expanded_size + 1);
+         }
 
          if (text != NULL)
          {
