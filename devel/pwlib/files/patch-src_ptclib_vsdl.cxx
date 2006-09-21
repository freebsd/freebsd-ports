--- src/ptclib/vsdl.cxx.orig	Thu Sep 21 00:50:56 2006
+++ src/ptclib/vsdl.cxx	Thu Sep 21 00:51:11 2006
@@ -102,11 +102,7 @@
 
 extern "C" {
 
-#if defined(P_FREEBSD)
-#include <SDL11/SDL.h>
-#else
 #include <SDL/SDL.h>
-#endif
 
 };
 
