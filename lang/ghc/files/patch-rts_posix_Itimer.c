--- rts/posix/Itimer.c.orig	2020-02-24 23:55:56 UTC
+++ rts/posix/Itimer.c
@@ -48,7 +48,7 @@
 #define USE_PTHREAD_FOR_ITIMER
 #endif
 
-#if defined(freebsd_HOST_OS) && defined(THREADED_RTS)
+#if defined(freebsd_HOST_OS)
 #define USE_PTHREAD_FOR_ITIMER
 #endif
 
