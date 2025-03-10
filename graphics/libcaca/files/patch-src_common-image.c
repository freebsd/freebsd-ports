Fix build when the IMLIB2 option is disabled. The _caca_alloc2d symbol
is not exported.

https://github.com/cacalabs/libcaca/issues/59

--- src/common-image.c.orig	2021-10-19 13:49:20 UTC
+++ src/common-image.c
@@ -161,7 +161,7 @@ struct image * load_image(char const * name)
     uint32_t depth = (bpp + 7) / 8;
 
     /* Allocate the pixel buffer */
-    im->pixels = _caca_alloc2d(im->w, im->h, depth);
+    im->pixels = malloc(im->w * im->h * depth);
     if (!im->pixels)
     {
         caca_file_close(f);
