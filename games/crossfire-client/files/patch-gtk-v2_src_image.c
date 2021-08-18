--- gtk-v2/src/image.c.orig	2021-08-18 00:18:54 UTC
+++ gtk-v2/src/image.c
@@ -164,7 +164,7 @@ static void create_map_image(guint8 *data, PixmapInfo 
             *p = (g << 8) | (g << 16) | (g << 24) | *(l + 3);
         }
 
-        for (i=0; i < width * ny; i+= 4) {
+        for (i=0; i < width * height; i+= 4) {
             guint32 *tmp;
 
             /*
