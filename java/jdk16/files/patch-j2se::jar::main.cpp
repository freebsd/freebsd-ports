--- ../../j2se/src/share/native/com/sun/java/util/jar/pack/main.cpp.orig	Tue Oct 19 14:59:48 2004
+++ ../../j2se/src/share/native/com/sun/java/util/jar/pack/main.cpp	Thu May 24 18:46:10 2007
@@ -17,7 +17,11 @@
 
 #if defined(unix) && !defined(PRODUCT)
 #include "pthread.h"
+#if defined(_ALLBSD_SOURCE)
+#define THREAD_SELF ((jlong)pthread_self())
+#else
 #define THREAD_SELF ((int)pthread_self())
+#endif
 #endif
 
 #include "defines.h"
