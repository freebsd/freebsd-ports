--- state.h.orig	Tue Sep 12 17:30:34 2006
+++ state.h	Tue Sep 12 17:30:40 2006
@@ -22,7 +22,7 @@
 
 // LINUX: SDL/
 #ifdef __FreeBSD__
-#include <SDL11/SDL.h>
+#include <SDL/SDL.h>
 #else
 #include <SDL/SDL.h>
 #endif
