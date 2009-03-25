--- lib/include/appUtil.h.orig	2009-03-24 19:24:50.000000000 +0900
+++ lib/include/appUtil.h	2009-03-24 19:24:20.000000000 +0900
@@ -69,7 +69,7 @@
 
 #endif //_WIN32
 
-#if defined(linux)
+#if defined(linux) || defined(__FreeBSD__)
 #include <glib.h>
 
 void AppUtil_Init(void);
