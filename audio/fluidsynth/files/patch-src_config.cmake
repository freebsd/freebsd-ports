--- src/config.cmake.orig	2018-12-30 11:42:00 UTC
+++ src/config.cmake
@@ -199,6 +199,9 @@
 /* Define to enable Windows MIDI driver */
 #cmakedefine WINMIDI_SUPPORT @WINMIDI_SUPPORT@
 
+/* Define to enable Sndio driver */
+#cmakedefine SNDIO_SUPPORT @SNDIO_SUPPORT@
+
 /* Define to 1 if you have the ANSI C header files. */
 #cmakedefine STDC_HEADERS @STDC_HEADERS@
 
