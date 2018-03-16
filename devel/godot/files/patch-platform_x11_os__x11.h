--- platform/x11/os_x11.h.orig	2018-01-03 09:26:19 UTC
+++ platform/x11/os_x11.h
@@ -38,6 +38,7 @@
 //#include "servers/visual/visual_server_wrap_mt.h"
 #include "drivers/alsa/audio_driver_alsa.h"
 #include "drivers/pulseaudio/audio_driver_pulseaudio.h"
+#include "drivers/rtaudio/audio_driver_rtaudio.h"
 #include "joypad_linux.h"
 #include "main/input_default.h"
 #include "power_x11.h"
@@ -166,6 +167,10 @@ class OS_X11 : public OS_Unix {
 	AudioDriverPulseAudio driver_pulseaudio;
 #endif
 
+#ifdef RTAUDIO_ENABLED
+	AudioDriverRtAudio driver_rtaudio;
+#endif
+
 	Atom net_wm_icon;
 
 	PowerX11 *power_manager;
