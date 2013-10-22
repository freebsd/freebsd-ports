--- ./modules/highgui/src/window_QT.cpp.orig	2013-10-22 11:01:57.000000000 -0400
+++ ./modules/highgui/src/window_QT.cpp	2013-10-22 11:03:10.000000000 -0400
@@ -46,6 +46,8 @@
 #ifdef _WIN32
 #include <windows.h>
 #define usleep Sleep
+#else
+#include <unistd.h>
 #endif
 
 #ifndef M_PI
