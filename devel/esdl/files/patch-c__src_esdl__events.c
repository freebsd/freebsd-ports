--- c_src/esdl_events.c.ori	Tue Sep  9 10:28:24 2003
+++ c_src/esdl_events.c	Mon Nov 17 18:23:24 2003
@@ -15,7 +15,11 @@
 #ifdef WIN32
 #include <SDL_events.h>
 #else
+#ifdef __FreeBSD__
+#include <SDL_events.h>
+#else
 #include <SDL/SDL_events.h>
+#endif
 #endif
 
 #define MAX_EVENT_SIZE 13
