--- src/ptclib/vsdl.cxx.orig	2008-09-25 14:50:57.000000000 +0800
+++ src/ptclib/vsdl.cxx	2008-09-25 14:51:48.000000000 +0800
@@ -44,7 +44,7 @@
 extern "C" {
 
 #if defined(P_FREEBSD)
-#include <SDL11/SDL.h>
+#include <SDL.h>
 #else
 #include <SDL/SDL.h>
 #endif
