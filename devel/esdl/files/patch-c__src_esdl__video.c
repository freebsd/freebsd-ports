--- c_src/esdl_video.c.ori	Tue Sep  9 10:28:24 2003
+++ c_src/esdl_video.c	Mon Nov 17 18:24:48 2003
@@ -16,7 +16,11 @@
 #ifdef WIN32
 #include <SDL_syswm.h>
 #else
+#ifdef __FreeBSD__
+#include <SDL_syswm.h>
+#else
 #include <SDL/SDL_syswm.h>
+#endif
 #endif
 
 void es_setVideoMode(sdl_data *sd, int len, char* bp) 
