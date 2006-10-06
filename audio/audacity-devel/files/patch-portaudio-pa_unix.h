--- lib-src/portaudio/pa_unix_oss/pa_unix.h.orig	Tue Dec  2 19:56:56 2003
+++ lib-src/portaudio/pa_unix_oss/pa_unix.h	Tue Dec  2 19:58:33 2003
@@ -82,7 +82,7 @@
 #define MAX_TIMEOUT_MSEC   (1000)
 
 /************************************************* Definitions ********/
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
  #define DEVICE_NAME_BASE            "/dev/dsp"
 #else
  #define DEVICE_NAME_BASE            "/dev/audio"
