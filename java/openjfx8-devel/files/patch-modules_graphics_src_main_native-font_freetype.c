--- modules/graphics/src/main/native-font/freetype.c.orig	2017-09-08 16:56:55 UTC
+++ modules/graphics/src/main/native-font/freetype.c
@@ -23,7 +23,6 @@
  * questions.
  */
 
-#if defined __linux__ || ANDROID_NDK
 #if defined _ENABLE_PANGO || _ENABLE_HARFBUZZ
 
 #include <jni.h>
@@ -646,4 +645,3 @@ JNIEXPORT jboolean JNICALL JNICALL OS_NATIVE(isHarfbuz
 }
 
 #endif /* ENABLE_PANGO || ENABLE_HARFBUZZ */
-#endif /* __linux__ || ANDROID_NDK */
