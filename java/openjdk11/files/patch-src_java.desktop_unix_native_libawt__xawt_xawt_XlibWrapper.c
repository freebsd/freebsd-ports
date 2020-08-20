--- src/java.desktop/unix/native/libawt_xawt/xawt/XlibWrapper.c.orig	2020-07-15 18:00:08 UTC
+++ src/java.desktop/unix/native/libawt_xawt/xawt/XlibWrapper.c
@@ -2183,7 +2183,7 @@ Java_sun_awt_X11_XlibWrapper_copyLongArray(JNIEnv *env
 JNIEXPORT jint JNICALL
 Java_sun_awt_X11_XlibWrapper_XSynchronize(JNIEnv *env, jclass clazz, jlong display, jboolean onoff)
 {
-    return (jint) XSynchronize((Display*)jlong_to_ptr(display), (onoff == JNI_TRUE ? True : False));
+    return XSynchronize((Display*)jlong_to_ptr(display), (onoff == JNI_TRUE ? True : False));
 }
 
 JNIEXPORT jboolean JNICALL
