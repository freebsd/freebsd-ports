--- ./src/Main/MainGui.cpp.orig	Mon Feb 26 10:36:38 2007
+++ ./src/Main/MainGui.cpp	Sun Apr 22 00:32:00 2007
@@ -27,7 +27,7 @@
 # undef _PreComp_
 #endif
 
-#ifdef FC_LINUX
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
 #	include <unistd.h>
 #endif
 
