--- ./src/Base/Parameter.cpp.orig	Sat Feb 24 11:44:54 2007
+++ ./src/Base/Parameter.cpp	Sun Apr 22 00:07:49 2007
@@ -52,7 +52,7 @@
 
 
 #include <fcntl.h>
-#ifdef FC_OS_LINUX
+#if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD)
 #	include <unistd.h>
 #endif
 
@@ -1117,7 +1117,7 @@
 
 		catch(const XMLException& toCatch)
 		{
-#if defined(FC_OS_LINUX) || defined(FC_OS_CYGWIN)
+#if defined(FC_OS_LINUX) || defined(FC_OS_FREEBSD) || defined(FC_OS_CYGWIN)
 			std::ostringstream err;
 #else
 			std::stringstream err;
