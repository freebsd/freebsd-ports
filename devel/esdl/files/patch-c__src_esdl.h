
$FreeBSD$

--- c_src/esdl.h.orig	Mon Dec  9 23:10:14 2002
+++ c_src/esdl.h	Mon Dec  9 23:10:27 2002
@@ -17,7 +17,11 @@
 #include <windows.h>  /* needed by Windows' gl.h etc */
 #include <SDL.h>
 #else
+#ifdef __FreeBSD__
+#include <SDL.h>
+#else
 #include <SDL/SDL.h>
+#endif
 #endif
 
 
