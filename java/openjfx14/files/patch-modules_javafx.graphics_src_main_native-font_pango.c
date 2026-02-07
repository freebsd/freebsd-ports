--- modules/javafx.graphics/src/main/native-font/pango.c.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.graphics/src/main/native-font/pango.c
@@ -23,7 +23,6 @@
  * questions.
  */
 
-#if defined __linux__
 #if defined _ENABLE_PANGO
 
 #include <jni.h>
@@ -432,4 +431,3 @@ JNIEXPORT void JNICALL OS_NATIVE(pango_1font_1descript
 }
 
 #endif /* ENABLE_PANGO */
-#endif /* __linux__ */
