--- ../bridges/source/jni_uno/jni_java2uno.cxx.orig	Tue Mar 11 12:33:06 2003
+++ ../bridges/source/jni_uno/jni_java2uno.cxx	Tue Mar 11 12:34:03 2003
@@ -62,7 +62,9 @@
 #if defined _MSC_VER
 #include <malloc.h>
 #else
+#if !defined( FREEBSD)
 #include <alloca.h>
+#endif
 #endif
 
 #include "jni_bridge.h"
