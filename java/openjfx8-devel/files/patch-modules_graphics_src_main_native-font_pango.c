--- modules/graphics/src/main/native-font/pango.c.orig	2017-07-08 13:12:21 UTC
+++ modules/graphics/src/main/native-font/pango.c
@@ -23,7 +23,7 @@
  * questions.
  */
 
-#if defined __linux__
+#if defined __linux__ || defined(__FreeBSD__)
 #if defined _ENABLE_PANGO
 
 #include <jni.h>
