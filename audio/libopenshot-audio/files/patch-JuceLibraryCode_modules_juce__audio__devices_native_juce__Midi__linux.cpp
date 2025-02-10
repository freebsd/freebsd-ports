--- JuceLibraryCode/modules/juce_audio_devices/native/juce_Midi_linux.cpp.orig	2024-12-21 22:21:33 UTC
+++ JuceLibraryCode/modules/juce_audio_devices/native/juce_Midi_linux.cpp
@@ -23,7 +23,7 @@
 namespace juce
 {
 
-#if JUCE_ALSA
+#if 0 && JUCE_ALSA
 
 //==============================================================================
 class AlsaClient
