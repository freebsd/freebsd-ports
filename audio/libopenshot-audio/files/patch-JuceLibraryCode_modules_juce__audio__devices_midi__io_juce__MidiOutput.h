--- JuceLibraryCode/modules/juce_audio_devices/midi_io/juce_MidiOutput.h.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_audio_devices/midi_io/juce_MidiOutput.h
@@ -66,7 +66,7 @@ class JUCE_API  MidiOutput  final : private Thread (pu
     static MidiOutput* openDevice (int deviceIndex);
 
 
-   #if JUCE_LINUX || JUCE_MAC || JUCE_IOS || DOXYGEN
+   #if JUCE_BSD || JUCE_LINUX || JUCE_MAC || JUCE_IOS || DOXYGEN
     /** This will try to create a new midi output device (Not available on Windows).
 
         This will attempt to create a new midi output device that other apps can connect
