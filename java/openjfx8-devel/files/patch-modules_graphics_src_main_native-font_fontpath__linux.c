--- modules/graphics/src/main/native-font/fontpath_linux.c.orig	2017-09-08 16:56:55 UTC
+++ modules/graphics/src/main/native-font/fontpath_linux.c
@@ -23,7 +23,7 @@
  * questions.
  */
 
-#if defined (__linux__) && ! defined (ANDROID_NDK)
+#if (defined (__linux__) && ! defined (ANDROID_NDK)) || defined(__FreeBSD__)
 
 #include <string.h>
 #include <stdio.h>
