--- lgc-pg/shp.c.orig	2020-10-31 10:02:28 UTC
+++ lgc-pg/shp.c
@@ -134,6 +134,9 @@ Locals
 ====================================================================
 */
 
+/* the low 'bpp' bytes of a pixel value are the raw surface data */
+#define PIXEL_OFFSET( bpp ) ( SDL_BYTEORDER == SDL_BIG_ENDIAN ? sizeof( Uint32 ) - (bpp) : 0 )
+
 /*
 ====================================================================
 Read icon header from file pos.
@@ -261,16 +264,18 @@ void set_pixel( SDL_Surface *surf, int x, int y, int p
 void set_pixel( SDL_Surface *surf, int x, int y, int pixel )
 {
     int pos = 0;
+    int bpp = surf->format->BytesPerPixel;
 
-    pos = y * surf->pitch + x * surf->format->BytesPerPixel;
-    memcpy( surf->pixels + pos, &pixel, surf->format->BytesPerPixel );
+    pos = y * surf->pitch + x * bpp;
+    memcpy( surf->pixels + pos, (char*)&pixel + PIXEL_OFFSET( bpp ), bpp );
 }
 Uint32 get_pixel( SDL_Surface *surf, int x, int y )
 {
     int pos = 0;
     Uint32 pixel = 0;
-    pos = y * surf->pitch + x * surf->format->BytesPerPixel;
-    memcpy( &pixel, surf->pixels + pos, surf->format->BytesPerPixel );
+    int bpp = surf->format->BytesPerPixel;
+    pos = y * surf->pitch + x * bpp;
+    memcpy( (char*)&pixel + PIXEL_OFFSET( bpp ), surf->pixels + pos, bpp );
     return pixel;
 }
 
