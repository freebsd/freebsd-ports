--- gnuradio-runtime/lib/thread/thread.cc.orig	2025-04-10 17:29:44 UTC
+++ gnuradio-runtime/lib/thread/thread.cc
@@ -22,7 +22,7 @@
     defined(__NetBSD__) || defined(__OpenBSD__)
 #define __GR_TARGET_BSD__
 #include <pthread.h>
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <pthread_np.h>
 #endif
 #else
