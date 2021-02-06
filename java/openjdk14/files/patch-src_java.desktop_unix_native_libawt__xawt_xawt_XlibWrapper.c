--- src/java.desktop/unix/native/libawt_xawt/xawt/XlibWrapper.c.orig	2020-04-17 22:35:42 UTC
+++ src/java.desktop/unix/native/libawt_xawt/xawt/XlibWrapper.c
@@ -2180,10 +2180,10 @@ Java_sun_awt_X11_XlibWrapper_copyLongArray(JNIEnv *env
     }
 }
 
-JNIEXPORT jint JNICALL
+JNIEXPORT jlong JNICALL
 Java_sun_awt_X11_XlibWrapper_XSynchronize(JNIEnv *env, jclass clazz, jlong display, jboolean onoff)
 {
-    return (jint) XSynchronize((Display*)jlong_to_ptr(display), (onoff == JNI_TRUE ? True : False));
+    return ptr_to_jlong(XSynchronize((Display*)jlong_to_ptr(display), (onoff == JNI_TRUE ? True : False)));
 }
 
 JNIEXPORT jboolean JNICALL
