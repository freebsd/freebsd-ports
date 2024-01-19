--- cmake/config.h.cmake.orig	2022-10-02 14:06:53 UTC
+++ cmake/config.h.cmake
@@ -198,6 +198,12 @@
 /* Define to 1 if you have clearenv */
 #cmakedefine   HAVE_CLEARENV 1
 
+/* Define to 1 if you have closefrom */
+#cmakedefine   HAVE_CLOSEFROM 1
+
+/* Define to 1 if you have close_range */
+#cmakedefine   HAVE_CLOSE_RANGE 1
+
 /* Define to 1 if you have writev */
 #cmakedefine   HAVE_WRITEV 1
 
