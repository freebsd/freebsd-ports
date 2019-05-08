--- JuceLibraryCode/modules/juce_audio_devices/midi_io/juce_MidiInput.h.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_audio_devices/midi_io/juce_MidiInput.h
@@ -123,7 +123,7 @@ class JUCE_API  MidiInput  final (public)
     static MidiInput* openDevice (int deviceIndex,
                                   MidiInputCallback* callback);
 
-   #if JUCE_LINUX || JUCE_MAC || JUCE_IOS || DOXYGEN
+   #if JUCE_BSD || JUCE_LINUX || JUCE_MAC || JUCE_IOS || DOXYGEN
     /** This will try to create a new midi input device (Not available on Windows).
 
         This will attempt to create a new midi input device with the specified name,
