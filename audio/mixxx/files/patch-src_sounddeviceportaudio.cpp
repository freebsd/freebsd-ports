--- src/sounddeviceportaudio.cpp.orig	2013-05-08 23:20:26 UTC
+++ src/sounddeviceportaudio.cpp
@@ -182,10 +182,10 @@ int SoundDevicePortAudio::open()
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
