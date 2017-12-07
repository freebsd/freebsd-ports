--- src/core/image.c.orig	2017-11-14 12:17:25 UTC
+++ src/core/image.c
@@ -34,12 +34,6 @@
 #include "resourcemanager.h"
 #include "util.h"
 
-/* image structure */
-struct image_t {
-    BITMAP *data; /* this must be the first field */
-    int w, h;
-};
-
 /* useful stuff */
 #define IS_PNG(path) (str_icmp((path)+strlen(path)-4, ".png") == 0)
 typedef int (*fast_getpixel_funptr)(BITMAP*,int,int);
@@ -233,25 +227,6 @@ image_t *image_create_shared(const image
     return img;
 }
 
-/*
- * image_width()
- * The width of the image
- */
-inline int image_width(const image_t *img)
-{
-    return img->w;
-}
-
-
-/*
- * image_height()
- * The height of the image
- */
-inline int image_height(const image_t *img)
-{
-    return img->h;
-}
-
 
 /*
  * image_getpixel()
