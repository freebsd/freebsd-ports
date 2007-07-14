--- src/output/RtAudio/rtaudio/RtAudio.cpp.orig	Tue Feb  6 00:07:31 2007
+++ src/output/RtAudio/rtaudio/RtAudio.cpp	Tue Feb  6 00:08:41 2007
@@ -42,7 +42,7 @@
 #include <QtGui>
 
 #ifdef Q_WS_X11
-    #define __LINUX_ALSA__
+    #define __LINUX_OSS__
 #endif
 #ifdef Q_WS_FREEBSD
     #define __LINUX_OSS__
