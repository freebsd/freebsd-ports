--- include/ptclib/vsdl.h.orig	2008-09-25 14:51:15.000000000 +0800
+++ include/ptclib/vsdl.h	2008-09-25 14:52:15.000000000 +0800
@@ -33,7 +33,7 @@
 
 #include <ptlib.h>
 #if defined(P_FREEBSD)
-#include <SDL11/SDL.h>
+#include <SDL.h>
 #else
 #include <SDL/SDL.h>
 #endif
