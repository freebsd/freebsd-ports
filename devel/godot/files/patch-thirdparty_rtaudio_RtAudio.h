--- thirdparty/rtaudio/RtAudio.h.orig	2016-08-09 07:52:15 UTC
+++ thirdparty/rtaudio/RtAudio.h
@@ -5,7 +5,13 @@
 #if defined(OSX_ENABLED)
     #define __MACOSX_CORE__
 #elif defined(UNIX_ENABLED)
+#if defined(OSS_ENABLED)
+    #define __LINUX_OSS__
+#elif defined(ALSA_ENABLED)
     #define __LINUX_ALSA__
+#elif defined(PULSEAUDIO_ENABLED)
+    #define __LINUX_PULSE__
+#endif
 #elif defined(WINDOWS_ENABLED)
     #if defined(WINRT_ENABLED)
         #define __RTAUDIO_DUMMY__
