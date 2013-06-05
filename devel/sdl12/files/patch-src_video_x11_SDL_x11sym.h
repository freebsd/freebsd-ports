--- src/video/x11/SDL_x11sym.h.orig	2013-06-05 11:06:34.000000000 +0200
+++ src/video/x11/SDL_x11sym.h	2013-06-05 11:08:02.000000000 +0200
@@ -165,7 +165,7 @@
  */
 #ifdef LONG64
 SDL_X11_MODULE(IO_32BIT)
-SDL_X11_SYM(int,_XData32,(Display *dpy,register long *data,unsigned len),(dpy,data,len),return)
+SDL_X11_SYM(int,_XData32,(Display *dpy,register _Xconst long *data,unsigned len),(dpy,data,len),return)
 SDL_X11_SYM(void,_XRead32,(Display *dpy,register long *data,long len),(dpy,data,len),)
 #endif
 
