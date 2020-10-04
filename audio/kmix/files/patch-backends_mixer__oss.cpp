--- backends/mixer_oss.cpp.orig	2020-10-03 12:41:46 UTC
+++ backends/mixer_oss.cpp
@@ -52,9 +52,9 @@
    The #define below is only there for internal reasons.
    In other words: Don't play around with this value
  */
-#define MAX_MIXDEVS 32
+#define MAX_MIXDEVS 25
 
-const char* MixerDevNames[32]={
+const char* MixerDevNames[25]={
     I18N_NOOP("Volume"),   I18N_NOOP("Bass"),       I18N_NOOP("Treble"),
     I18N_NOOP("Synth"),    I18N_NOOP("Pcm"),        I18N_NOOP("Speaker"),
     I18N_NOOP("Line"),     I18N_NOOP("Microphone"), I18N_NOOP("CD"),
@@ -63,11 +63,9 @@ const char* MixerDevNames[32]={
     I18N_NOOP("Line2"),    I18N_NOOP("Line3"),      I18N_NOOP("Digital1"),
     I18N_NOOP("Digital2"), I18N_NOOP("Digital3"),   I18N_NOOP("PhoneIn"),
     I18N_NOOP("PhoneOut"), I18N_NOOP("Video"),      I18N_NOOP("Radio"),
-    I18N_NOOP("Monitor"),  I18N_NOOP("3D-depth"),   I18N_NOOP("3D-center"),
-    I18N_NOOP("unknown"),  I18N_NOOP("unknown"),    I18N_NOOP("unknown"),
-    I18N_NOOP("unknown") , I18N_NOOP("unused") };
+    I18N_NOOP("Monitor") };
 
-const MixDevice::ChannelType MixerChannelTypes[32] = {
+const MixDevice::ChannelType MixerChannelTypes[25] = {
     MixDevice::VOLUME,   MixDevice::BASS,       MixDevice::TREBLE,
     MixDevice::MIDI,     MixDevice::AUDIO,      MixDevice::SPEAKER,
     MixDevice::EXTERNAL, MixDevice::MICROPHONE, MixDevice::CD,
@@ -76,9 +74,7 @@ const MixDevice::ChannelType MixerChannelTypes[32] = {
     MixDevice::EXTERNAL, MixDevice::EXTERNAL,   MixDevice::DIGITAL,
     MixDevice::DIGITAL,  MixDevice::DIGITAL,    MixDevice::EXTERNAL,
     MixDevice::EXTERNAL, MixDevice::VIDEO,      MixDevice::EXTERNAL,
-    MixDevice::EXTERNAL, MixDevice::VOLUME,     MixDevice::VOLUME,
-    MixDevice::UNKNOWN,  MixDevice::UNKNOWN,    MixDevice::UNKNOWN,
-    MixDevice::UNKNOWN,  MixDevice::UNKNOWN };
+    MixDevice::EXTERNAL };
 
 Mixer_Backend* OSS_getMixer( Mixer* mixer, int device )
 {
