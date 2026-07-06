--- src/image.c.orig	2026-07-06 02:15:12 UTC
+++ src/image.c
@@ -12052,7 +12052,7 @@ svg_load_image (struct frame *f, struct image *img, ch
     {
       css = xmalloc (SBYTES (lcss) + 1);
       strncpy (css, SSDATA (lcss), SBYTES (lcss));
-      *(css + SBYTES (lcss) + 1) = 0;
+      *(css + SBYTES (lcss)) = 0;
     }
 #endif
 
