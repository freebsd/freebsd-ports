--- config.h.in.cmake.orig	2019-04-04 12:06:59 UTC
+++ config.h.in.cmake
@@ -41,6 +41,8 @@
 
 #cmakedefine HAVE_VFORK
 
+#cmakedefine HAVE_SYSCTL_H
+
 #cmakedefine HAVE_CLOCK_GETTIME
 
 #cmakedefine HAVE_FDATASYNC
