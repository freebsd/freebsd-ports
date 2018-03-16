--- platform/x11/os_x11.cpp.orig	2018-01-03 04:32:19 UTC
+++ platform/x11/os_x11.cpp
@@ -2469,6 +2469,10 @@ OS_X11::OS_X11() {
 	AudioDriverManager::add_driver(&driver_pulseaudio);
 #endif
 
+#ifdef RTAUDIO_ENABLED
+	AudioDriverManager::add_driver(&driver_rtaudio);
+#endif
+
 #ifdef ALSA_ENABLED
 	AudioDriverManager::add_driver(&driver_alsa);
 #endif
