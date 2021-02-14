--- config.h.in.cmake.orig	2020-12-16 13:02:13 UTC
+++ config.h.in.cmake
@@ -39,6 +39,8 @@
 
 #cmakedefine HAVE_VFORK
 
+#cmakedefine HAVE_SYSCTL_H
+
 #cmakedefine HAVE_CLOCK_GETTIME
 
 #cmakedefine HAVE_FDATASYNC
