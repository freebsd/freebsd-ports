
$FreeBSD$

--- c_src/esdl_main.c.orig	Mon Dec  9 23:13:48 2002
+++ c_src/esdl_main.c	Mon Dec  9 23:14:21 2002
@@ -30,7 +30,11 @@
 #else
 #include <unistd.h>
 #include <errno.h>
+#ifdef __FreeBSD__
+#include <SDL_mutex.h>
+#else
 #include <SDL/SDL_mutex.h>
+#endif
 #endif
 
 #include "esdl.h"
