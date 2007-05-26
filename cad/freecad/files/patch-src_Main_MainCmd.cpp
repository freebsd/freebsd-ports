--- ./src/Main/MainCmd.cpp.orig	Mon Feb 26 10:36:38 2007
+++ ./src/Main/MainCmd.cpp	Sun Apr 22 00:33:00 2007
@@ -28,7 +28,7 @@
 # include <sstream>
 #endif
 
-#ifdef FC_LINUX
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
 #	include <unistd.h>
 #endif
 
