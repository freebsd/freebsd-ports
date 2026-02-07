--- modules/javafx.graphics/src/main/native-font/freetype.c.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.graphics/src/main/native-font/freetype.c
@@ -23,7 +23,6 @@
  * questions.
  */
 
-#if defined __linux__ || ANDROID_NDK
 #if defined _ENABLE_PANGO || _ENABLE_HARFBUZZ
 
 #include <jni.h>
@@ -650,4 +649,3 @@ JNIEXPORT jboolean JNICALL JNICALL OS_NATIVE(isHarfbuz
 }
 
 #endif /* ENABLE_PANGO || ENABLE_HARFBUZZ */
-#endif /* __linux__ || ANDROID_NDK */
