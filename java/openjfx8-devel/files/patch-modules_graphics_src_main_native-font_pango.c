--- modules/graphics/src/main/native-font/pango.c.orig	2017-09-08 16:56:55 UTC
+++ modules/graphics/src/main/native-font/pango.c
@@ -23,7 +23,6 @@
  * questions.
  */
 
-#if defined __linux__
 #if defined _ENABLE_PANGO
 
 #include <jni.h>
@@ -410,4 +409,3 @@ JNIEXPORT void JNICALL OS_NATIVE(pango_1font_1descript
 }
 
 #endif /* ENABLE_PANGO */
-#endif /* __linux__ */
