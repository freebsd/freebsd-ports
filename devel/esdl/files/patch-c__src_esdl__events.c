
$FreeBSD$

--- c_src/esdl_events.c.orig	Mon Dec  9 23:13:11 2002
+++ c_src/esdl_events.c	Mon Dec  9 23:13:35 2002
@@ -14,7 +14,11 @@
 #ifdef WIN32
 #include <SDL_events.h>
 #else
+#ifdef __FreeBSD__
+#include <SDL_events.h>
+#else
 #include <SDL/SDL_events.h>
+#endif
 #endif
 
 /* Foward decls */
