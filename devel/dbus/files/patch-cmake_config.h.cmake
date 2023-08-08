--- cmake/config.h.cmake.orig	2022-09-14 12:12:21 UTC
+++ cmake/config.h.cmake
@@ -198,6 +198,9 @@
 /* Define to 1 if you have clearenv */
 #cmakedefine   HAVE_CLEARENV 1
 
+/* Define to 1 if you have closefrom */
+#cmakedefine   HAVE_CLOSEFROM 1
+
 /* Define to 1 if you have writev */
 #cmakedefine   HAVE_WRITEV 1
 
