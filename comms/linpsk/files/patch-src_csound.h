--- src/csound.h.orig	2013-12-24 23:45:41.000000000 -0800
+++ src/csound.h	2015-01-07 07:38:09.000000000 -0800
@@ -22,6 +22,7 @@
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <inttypes.h>
 
 #include <QMutex>
 #include <QWaitCondition>
@@ -49,7 +50,7 @@
   private: // Private attributes
     snd_pcm_t *handle;
     bool output;
-    double buffer[2*BUF_SIZE]; // 16 bit , stereo
+    int32_t buffer[2*BUF_SIZE]; // 16 bit , stereo
     QMutex LockPointers;
     QWaitCondition WakeUp;
     void record();
