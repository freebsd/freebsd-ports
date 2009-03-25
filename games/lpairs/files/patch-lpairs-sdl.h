--- lpairs/sdl.h.orig	2001-03-16 21:43:22.000000000 +0300
+++ lpairs/sdl.h	2009-03-25 22:04:45.000000000 +0300
@@ -40,8 +40,8 @@
 SDL_Surface* load_surf(char *fname, int f);
 SDL_Surface* create_surf(int w, int h, int f);
 int  disp_format(SDL_Surface *sur);
-inline void lock_surf(SDL_Surface *sur);
-inline void unlock_surf(SDL_Surface *sur);
+void lock_surf(SDL_Surface *sur);
+void unlock_surf(SDL_Surface *sur);
 void blit_surf(void);
 void alpha_blit_surf(int alpha);
 void fill_surf(int c);
@@ -86,8 +86,8 @@
 Font* load_fixed_font(char *fname, int off, int len, int w);
 void free_font(Font *sfnt);
 int  write_text(Font *sfnt, SDL_Surface *dest, int x, int y, char *str, int alpha);
-inline void lock_font(Font *sfnt);
-inline void unlock_font(Font *sfnt);
+void lock_font(Font *sfnt);
+void unlock_font(Font *sfnt);
 SDL_Rect last_write_rect(Font *fnt);
 int  text_width(Font *fnt, char *str);
 
@@ -116,16 +116,16 @@
 void quit_sdl();
 int  set_video_mode( int w, int h, int d, int f );
 void hardware_cap();
-inline void refresh_screen( int x, int y, int w, int h );
+void refresh_screen( int x, int y, int w, int h );
 void refresh_rects();
 void add_refresh_rect(int x, int y, int w, int h);
 void dim_screen(int steps, int delay, int trp);
 void undim_screen(int steps, int delay, int trp);
 int  wait_for_key();
 void wait_for_click();
-inline void lock_screen();
-inline void unlock_screen();
-inline void flip_screen();
+void lock_screen();
+void unlock_screen();
+void flip_screen();
 
 /* cursor */
 /* creates cursor */
