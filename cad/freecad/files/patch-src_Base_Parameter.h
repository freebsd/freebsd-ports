--- ./src/Base/Parameter.h.orig	Sat Feb 24 11:44:54 2007
+++ ./src/Base/Parameter.h	Sun Apr 22 00:09:23 2007
@@ -40,7 +40,7 @@
 
 
 // Include files
-#ifdef FC_OS_LINUX
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
 #  include <sstream>
 #endif
 #include <map>
