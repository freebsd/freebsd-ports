
$FreeBSD$

--- c_src/esdl_conv.h.orig	Mon Dec  9 23:11:33 2002
+++ c_src/esdl_conv.h	Mon Dec  9 23:12:05 2002
@@ -23,7 +23,11 @@
 #ifdef WIN32
 #include <SDL_byteorder.h>
 #else 
+#ifdef __FreeBSD__
+#include <SDL_byteorder.h>
+#else
 #include <SDL/SDL_byteorder.h>
+#endif
 #endif
 
 float  readFloat(char *);
