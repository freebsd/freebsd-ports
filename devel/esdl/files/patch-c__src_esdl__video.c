
$FreeBSD$

--- c_src/esdl_video.c.orig	Mon Dec  9 23:12:18 2002
+++ c_src/esdl_video.c	Mon Dec  9 23:13:01 2002
@@ -18,7 +18,11 @@
 #ifdef WIN32
 #include <SDL_syswm.h>
 #else
+#ifdef __FreeBSD__
+#include <SDL_syswm.h>
+#else
 #include <SDL/SDL_syswm.h>
+#endif
 #endif
 
 int es_setVideoMode(sdl_data *sd, int len, char * buff) 
