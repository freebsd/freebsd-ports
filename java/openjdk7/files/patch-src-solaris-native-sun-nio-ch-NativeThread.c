--- jdk/src/solaris/native/sun/nio/ch/NativeThread.c
+++ jdk/src/solaris/native/sun/nio/ch/NativeThread.c
@@ -33,12 +33,20 @@
 #include "nio_util.h"
 
 
-#ifdef __linux__
+#if defined(__linux__) || defined(_ALLBSD_SOURCE)
+#if defined(__linux__)
 #include <pthread.h>
 #include <sys/signal.h>
 
 /* Also defined in src/solaris/native/java/net/linux_close.c */
 #define INTERRUPT_SIGNAL (__SIGRTMAX - 2)
+#else
+#include <pthread.h>
+#include <signal.h>
+
+/* Also defined in src/solaris/native/java/net/bsd_close.c */
+#define INTERRUPT_SIGNAL SIGIO
+#endif
 
 static void
 nullHandler(int sig)
@@ -51,7 +59,7 @@
 JNIEXPORT void JNICALL
 Java_sun_nio_ch_NativeThread_init(JNIEnv *env, jclass cl)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(_ALLBSD_SOURCE)
 
     /* Install the null handler for INTERRUPT_SIGNAL.  This might overwrite the
      * handler previously installed by java/net/linux_close.c, but that's okay
@@ -74,7 +82,7 @@
 JNIEXPORT jlong JNICALL
 Java_sun_nio_ch_NativeThread_current(JNIEnv *env, jclass cl)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(_ALLBSD_SOURCE)
     return (long)pthread_self();
 #else
     return -1;
@@ -84,7 +92,7 @@
 JNIEXPORT void JNICALL
 Java_sun_nio_ch_NativeThread_signal(JNIEnv *env, jclass cl, jlong thread)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(_ALLBSD_SOURCE)
     if (pthread_kill((pthread_t)thread, INTERRUPT_SIGNAL))
         JNU_ThrowIOExceptionWithLastError(env, "Thread signal failed");
 #endif
