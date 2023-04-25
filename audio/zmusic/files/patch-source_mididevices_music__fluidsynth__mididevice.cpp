--- source/mididevices/music_fluidsynth_mididevice.cpp.orig	2023-04-12 16:05:39 UTC
+++ source/mididevices/music_fluidsynth_mididevice.cpp
@@ -47,7 +47,7 @@
 
 FluidConfig fluidConfig;
 
-#include "../thirdparty/fluidsynth/include/fluidsynth.h"
+#include <fluidsynth.h>
 
 class FluidSynthMIDIDevice : public SoftSynthMIDIDevice
 {
