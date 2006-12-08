--- libs/ardour/ardour/configuration_vars.h.orig	Thu Dec  7 17:48:57 2006
+++ libs/ardour/ardour/configuration_vars.h	Thu Dec  7 17:49:18 2006
@@ -7,8 +7,8 @@
 CONFIG_VARIABLE (std::string, auditioner_output_left, "auditioner-output-left",  "coreaudio:Built-in Audio:in1")
 CONFIG_VARIABLE (std::string, auditioner_output_right, "auditioner-output-right", "coreaudio:Built-in Audio:in2")
 #else
-CONFIG_VARIABLE (std::string, auditioner_output_left, "auditioner-output-left", "alsa_pcm:playback_1")
-CONFIG_VARIABLE (std::string, auditioner_output_right, "auditioner-output-right", "alsa_pcm:playback_2")
+CONFIG_VARIABLE (std::string, auditioner_output_left, "auditioner-output-left", "oss:playback_1")
+CONFIG_VARIABLE (std::string, auditioner_output_right, "auditioner-output-right", "oss:playback_2")
 #endif
 
 /* MIDI and MIDI related */
