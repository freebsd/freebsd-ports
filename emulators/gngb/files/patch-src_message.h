--- src/message.h.orig	2003-06-28 08:42:03 UTC
+++ src/message.h
@@ -21,7 +21,7 @@
 
 #include <SDL.h>
 
-int wl,hl,xm,ym;
+extern int wl,hl,xm,ym;
 //extern void (*draw_message)(int x,int y,char *mes);
 extern SDL_Surface *fontbuf;
 
