--- gr-audio/lib/alsa/audio_alsa_source.cc.orig	2012-11-11 17:33:00.000000000 -0500
+++ gr-audio/lib/alsa/audio_alsa_source.cc	2012-11-11 17:33:39.000000000 -0500
@@ -24,6 +24,10 @@
 #include "config.h"
 #endif
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #include "gr_audio_registry.h"
 #include <audio_alsa_source.h>
 #include <gr_io_signature.h>
@@ -33,7 +37,11 @@
 #include <stdexcept>
 #include <gri_alsa.h>
 
+#if defined(BSD)
+AUDIO_REGISTER_SOURCE(REG_PRIO_LOW, alsa)(
+#else
 AUDIO_REGISTER_SOURCE(REG_PRIO_HIGH, alsa)(
+#endif
     int sampling_rate, const std::string &device_name, bool ok_to_block
 ){
     return audio_source::sptr(new audio_alsa_source(sampling_rate, device_name, ok_to_block));
