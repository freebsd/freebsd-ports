--- src/save.c.orig	2003-04-03 13:27:29 UTC
+++ src/save.c
@@ -8,6 +8,7 @@
 
 #define FILENAME_LEN 1024
 static SDL_Surface *savestate_bmp=NULL;
+void movie_add_pad(Uint8 pad);
 
 void get_filename_ext(char *f,char *ext) {
   /*  char *a=getenv("HOME");*/
