
$FreeBSD$

--- c_src/esdl_stream.c.orig	Mon Dec  9 23:14:32 2002
+++ c_src/esdl_stream.c	Mon Dec  9 23:15:11 2002
@@ -22,7 +22,11 @@
 #else
 #include <unistd.h>
 #include <errno.h>
+#ifdef __FreeBSD__
+#include <SDL_mutex.h>
+#else
 #include <SDL/SDL_mutex.h>
+#endif
 #endif
 
 
