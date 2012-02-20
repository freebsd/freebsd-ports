--- src/sounddeviceportaudio.cpp.orig	2011-12-24 11:53:20.000000000 +0900
+++ src/sounddeviceportaudio.cpp	2012-01-16 06:10:09.000000000 +0900
@@ -182,10 +182,10 @@
         qDebug() << "Opened PortAudio stream successfully... starting";
     }
 
-#ifdef __LINUX__
+#if defined(__BSD__) || defined(__LINUX__)
     //Attempt to dynamically load and resolve stuff in the PortAudio library
     //in order to enable RT priority with ALSA.
-    QLibrary portaudio("libportaudio.so.2");
+    QLibrary portaudio("libportaudio.so");
     if (!portaudio.load())
        qWarning() << "Failed to dynamically load PortAudio library";
     else
