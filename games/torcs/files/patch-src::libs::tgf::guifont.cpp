--- src/libs/tgf/guifont.cpp.orig	Sat Apr 19 02:46:41 2003
+++ src/libs/tgf/guifont.cpp	Mon May  5 00:32:07 2003
@@ -25,7 +25,7 @@
 
 #ifdef WIN32
 #include <windows.h>
-#else
+#elif !defined(__FreeBSD__)
 #include <endian.h>
 #endif
 
