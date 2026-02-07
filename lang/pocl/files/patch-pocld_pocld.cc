--- pocld/pocld.cc.orig	2025-05-21 11:53:16 UTC
+++ pocld/pocld.cc
@@ -27,7 +27,7 @@
 #include <unistd.h>
 #include <CL/opencl.hpp>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <sys/resource.h>
 #endif
 
