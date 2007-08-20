--- src/client/qal.h	Mon Apr  2 10:06:41 2007
+++ src/client/qal.h	Mon Apr  2 10:06:57 2007
@@ -28,7 +28,7 @@
 	#include "../ports/win32/qal_win.h"
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	#include "../ports/linux/qal_linux.h"
 #endif
 
