--- ./src/Base/ParameterPy.cpp.orig	Sat Feb 24 11:44:54 2007
+++ ./src/Base/ParameterPy.cpp	Sun Apr 22 00:10:34 2007
@@ -39,7 +39,7 @@
 
 
 #include <fcntl.h>
-#ifdef FC_OS_LINUX
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
 #	include <unistd.h>
 #endif
 
