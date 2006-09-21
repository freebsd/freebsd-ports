--- include/ptclib/vsdl.h.orig	Thu Sep 21 00:49:29 2006
+++ include/ptclib/vsdl.h	Thu Sep 21 00:49:53 2006
@@ -98,11 +98,7 @@
 #if P_SDL
 
 #include <ptlib.h>
-#if defined(P_FREEBSD)
-#include <SDL11/SDL.h>
-#else
 #include <SDL/SDL.h>
-#endif
 
 #undef main
 
