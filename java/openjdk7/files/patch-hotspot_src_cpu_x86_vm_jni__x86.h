--- hotspot/src/cpu/x86/vm/jni_x86.h.orig	2020-03-01 18:10:20 UTC
+++ hotspot/src/cpu/x86/vm/jni_x86.h
@@ -28,7 +28,10 @@
 
 #if defined(SOLARIS) || defined(LINUX) || defined(_ALLBSD_SOURCE)
 
-#if defined(__GNUC__) && (__GNUC__ > 4) || (__GNUC__ == 4) && (__GNUC_MINOR__ > 2)
+#ifndef __has_attribute
+  #define __has_attribute(x) 0
+#endif
+#if (defined(__GNUC__) && ((__GNUC__ > 4) || (__GNUC__ == 4) && (__GNUC_MINOR__ > 2))) || __has_attribute(visibility)
   #define JNIEXPORT     __attribute__((visibility("default")))
   #define JNIIMPORT     __attribute__((visibility("default")))
 #else
