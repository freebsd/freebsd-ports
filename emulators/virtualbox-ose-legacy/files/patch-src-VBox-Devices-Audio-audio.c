--- src/VBox/Devices/Audio/audio.c.orig	2009-12-15 14:54:13.000000000 +0900
+++ src/VBox/Devices/Audio/audio.c	2009-12-15 14:53:54.000000000 +0900
@@ -73,6 +73,11 @@
     &pulse_audio_driver,
 # endif
 #endif /* RT_OS_LINUX */
+#ifdef RT_OS_FREEBSD
+# ifdef VBOX_WITH_PULSE
+    &pulse_audio_driver,
+# endif
+#endif
 #ifdef RT_OS_DARWIN
     &coreaudio_audio_driver,
 #endif
