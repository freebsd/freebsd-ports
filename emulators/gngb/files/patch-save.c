--- src/save.c.orig	Sun Aug 15 19:46:58 2004
+++ src/save.c	Sun Aug 15 19:47:44 2004
@@ -8,6 +8,7 @@
 
 #define FILENAME_LEN 1024
 static SDL_Surface *savestate_bmp=NULL;
+void movie_add_pad(Uint8 pad);
 
 void get_filename_ext(char *f,char *ext) {
   /*  char *a=getenv("HOME");*/
