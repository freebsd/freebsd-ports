--- src/core/image.h.orig	2017-11-14 12:16:37 UTC
+++ src/core/image.h
@@ -22,10 +22,15 @@
 #ifndef _IMAGE_H
 #define _IMAGE_H
 
+#include "allegro.h"
 #include "global.h"
 #include "v2d.h"
 
-/* opaque image type */
+/* image structure */
+struct image_t {
+    BITMAP *data; /* this must be the first field */
+    int w, h;
+};
 typedef struct image_t image_t;
 
 /* image flags (bitwise OR) */
@@ -42,13 +47,29 @@ void image_save(const image_t *img, cons
 image_t *image_create_shared(const image_t *parent, int x, int y, int width, int height); /* creates a sub-image */
 
 /* properties */
-inline int image_width(const image_t *img);
-inline int image_height(const image_t *img);
 uint32 image_rgb(uint8 r, uint8 g, uint8 b);
 void image_color2rgb(uint32 color, uint8 *r, uint8 *g, uint8 *b);
 int image_pixelperfect_collision(const image_t *img1, const image_t *img2, int x1, int y1, int x2, int y2);
 uint32 image_getpixel(const image_t *img, int x, int y);
 
+/*
+ * image_width()
+ * The width of the image
+ */
+inline int image_width(const image_t *img)
+{ 
+    return img->w;
+}
+
+/*
+ * image_height()
+ * The height of the image
+ */
+inline int image_height(const image_t *img)
+{
+    return img->h;
+}
+
 /* drawing primitives */
 void image_clear(image_t *img, uint32 color);
 void image_putpixel(image_t *img, int x, int y, uint32 color);
