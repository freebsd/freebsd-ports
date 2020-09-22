--- src/video_std.h.orig	2003-04-03 13:27:29 UTC
+++ src/video_std.h
@@ -27,9 +27,9 @@
 extern Sint8 rb_tab[2][RB_SIZE];
 extern SDL_Surface *back;
 
-Uint8 rb_shift;
-SDL_Rect dstR;
-SDL_Rect scrR;
+extern Uint8 rb_shift;
+extern SDL_Rect dstR;
+extern SDL_Rect scrR;
 
 void draw_screen_sgb_std(void);
 void draw_screen_wb_std(void);
