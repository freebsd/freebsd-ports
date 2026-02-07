--- ./radiant/qe3.cpp.orig	Thu Mar 16 16:09:46 2006
+++ ./radiant/qe3.cpp	Thu Mar 16 16:09:46 2006
@@ -172,7 +172,7 @@
 
 
 const char* const EXECUTABLE_TYPE = 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 "x86"
 #elif defined(__APPLE__)
 "ppc"
