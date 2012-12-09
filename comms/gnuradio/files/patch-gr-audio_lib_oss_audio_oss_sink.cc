--- gr-audio/lib/oss/audio_oss_sink.cc.orig	2012-11-11 17:30:04.000000000 -0500
+++ gr-audio/lib/oss/audio_oss_sink.cc	2012-11-11 17:30:48.000000000 -0500
@@ -24,6 +24,10 @@
 #include "config.h"
 #endif
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #include "gr_audio_registry.h"
 #include <audio_oss_sink.h>
 #include <gr_io_signature.h>
@@ -38,7 +42,11 @@
 #include <iostream>
 #include <stdexcept>
 
+#if defined(BSD)
+AUDIO_REGISTER_SINK(REG_PRIO_HIGH, oss)(
+#else
 AUDIO_REGISTER_SINK(REG_PRIO_LOW, oss)(
+#endif
     int sampling_rate, const std::string &device_name, bool ok_to_block
 ){
     return audio_sink::sptr(new audio_oss_sink(sampling_rate, device_name, ok_to_block));
