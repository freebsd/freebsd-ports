--- config.h.in.cmake.orig	2025-05-21 11:53:16 UTC
+++ config.h.in.cmake
@@ -88,6 +88,8 @@
 
 #cmakedefine HAVE_LINUX_VSOCK_H
 
+#cmakedefine HAVE_SYSCTL_H
+
 #cmakedefine HAVE_CLOCK_GETTIME
 
 #cmakedefine HOST_COMPILER_SUPPORTS_FLOAT16
