--- JuceLibraryCode/modules/juce_audio_devices/midi_io/juce_MidiDevices.h.orig	2020-09-11 12:10:25 UTC
+++ JuceLibraryCode/modules/juce_audio_devices/midi_io/juce_MidiDevices.h
@@ -108,7 +108,7 @@ class JUCE_API  MidiInput  final (public)
     */
     static std::unique_ptr<MidiInput> openDevice (const String& deviceIdentifier, MidiInputCallback* callback);
 
-   #if JUCE_LINUX || JUCE_MAC || JUCE_IOS || DOXYGEN
+   #if JUCE_BSD || JUCE_LINUX || JUCE_MAC || JUCE_IOS || DOXYGEN
     /** This will try to create a new midi input device (only available on Linux, macOS and iOS).
 
         This will attempt to create a new midi input device with the specified name for other
@@ -264,7 +264,7 @@ class JUCE_API  MidiOutput  final  : private Thread (p
     */
     static std::unique_ptr<MidiOutput> openDevice (const String& deviceIdentifier);
 
-   #if JUCE_LINUX || JUCE_MAC || JUCE_IOS || DOXYGEN
+   #if JUCE_BSD || JUCE_LINUX || JUCE_MAC || JUCE_IOS || DOXYGEN
     /** This will try to create a new midi output device (only available on Linux, macOS and iOS).
 
         This will attempt to create a new midi output device with the specified name that other
