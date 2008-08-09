--- ../kamera/config-kamera.h.cmake.orig	2008-02-10 12:38:09.000000000 +0100
+++ ../kamera/config-kamera.h.cmake	2008-02-10 12:38:35.000000000 +0100
@@ -1,6 +1,6 @@
 /* Define if we have va_copy */
-/* #undef HAVE_VA_COPY */
+#define HAVE_VA_COPY
 
 /* Define if we have __va_copy */
-#define HAVE___VA_COPY 1
+/* #define HAVE___VA_COPY 1 */
 
