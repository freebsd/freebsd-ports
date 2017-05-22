--- config.h.in.cmake.orig	2017-04-05 14:15:40 UTC
+++ config.h.in.cmake
@@ -44,6 +44,8 @@
 
 #cmakedefine HAVE_VFORK
 
+#cmakedefine HAVE_SYSCTL_H
+
 #cmakedefine HAVE_CLOCK_GETTIME
 
 #cmakedefine HAVE_LTTNG_UST
