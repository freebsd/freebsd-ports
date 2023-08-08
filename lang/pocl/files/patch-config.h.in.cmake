--- config.h.in.cmake.orig	2022-06-10 10:09:05 UTC
+++ config.h.in.cmake
@@ -57,6 +57,8 @@
 
 #cmakedefine HAVE_VFORK
 
+#cmakedefine HAVE_SYSCTL_H
+
 #cmakedefine HAVE_CLOCK_GETTIME
 
 #cmakedefine HAVE_FDATASYNC
