--- include/surface_sdl.h.orig	2013-05-30 22:00:54.478112221 +0400
+++ include/surface_sdl.h	2013-05-30 22:02:18.114218658 +0400
@@ -46,7 +46,7 @@
   ~surface_sdl ();
   SDL_Surface* get_surface ();
   char* get_pixel_data ();
-  char* get_pixel_data (Uint32 coord_x, Uint32 coord_x);
+  char* get_pixel_data (Uint32 coord_x, Uint32 coord_y);
   Uint32 get_row_size ();
   Uint32 get_offset (Uint32 xcoord, Uint32 ycoord);
   void clear (Uint32 color = 0);
