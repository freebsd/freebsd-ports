--- cmake/config.h.cmake.orig	2018-02-23 10:25:17 UTC
+++ cmake/config.h.cmake
@@ -181,6 +181,9 @@
 /* Define to 1 if you have clearenv */
 #cmakedefine   HAVE_CLEARENV 1
 
+/* Define to 1 if you have closefrom */
+#cmakedefine   HAVE_CLOSEFROM 1
+
 /* Define to 1 if you have writev */
 #cmakedefine   HAVE_WRITEV 1
 
