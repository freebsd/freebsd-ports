--- src/config.cmake.orig	2012-08-16 04:01:13 UTC
+++ src/config.cmake
@@ -178,6 +178,9 @@
 /* Define to enable PulseAudio driver */
 #cmakedefine PULSE_SUPPORT @PULSE_SUPPORT@
 
+/* Define to enable Sndio driver */
+#cmakedefine SNDIO_SUPPORT @SNDIO_SUPPORT@
+
 /* Define to 1 if you have the ANSI C header files. */
 #cmakedefine STDC_HEADERS @STDC_HEADERS@
 
