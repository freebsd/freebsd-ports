--- osd_sdl_gfx.c.orig	2005-04-05 19:53:14 UTC
+++ osd_sdl_gfx.c
@@ -18,7 +18,7 @@ int blit_x,blit_y;
 int screen_blit_x, screen_blit_y;
 // where on the screen we must blit XBuf
 
-UChar* XBuf;
+extern UChar* XBuf;
 // buffer for video flipping
 
 UChar index_to_RGB[256];
