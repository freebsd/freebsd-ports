--- common/drivers/rtaudio/rt_audio.cpp.orig	Mon Jun 30 12:29:43 2003
+++ common/drivers/rtaudio/rt_audio.cpp	Thu Oct 30 12:04:02 2003
@@ -68,6 +68,10 @@
   #define MUTEX_UNLOCK(A)     pthread_mutex_unlock(A)
 #endif
 
+#if defined(__FreeBSD__)
+  #define O_SYNC O_FSYNC
+#endif
+
 // *************************************************** //
 //
 // Public common (OS-independent) methods.
