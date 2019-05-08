--- JuceLibraryCode/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_audio_devices/audio_io/juce_AudioIODeviceType.cpp
@@ -62,15 +62,15 @@ AudioIODeviceType* AudioIODeviceType::createAudioIODev
 AudioIODeviceType* AudioIODeviceType::createAudioIODeviceType_ASIO()            { return nullptr; }
 #endif
 
-#if ! (JUCE_LINUX && JUCE_ALSA)
+#if ! ((JUCE_BSD || JUCE_LINUX) && JUCE_ALSA)
 AudioIODeviceType* AudioIODeviceType::createAudioIODeviceType_ALSA()            { return nullptr; }
 #endif
 
-#if ! (JUCE_LINUX && JUCE_JACK)
+#if ! ((JUCE_BSD || JUCE_LINUX) && JUCE_JACK)
 AudioIODeviceType* AudioIODeviceType::createAudioIODeviceType_JACK()            { return nullptr; }
 #endif
 
-#if ! (JUCE_LINUX && JUCE_BELA)
+#if ! ((JUCE_BSD || JUCE_LINUX) && JUCE_BELA)
 AudioIODeviceType* AudioIODeviceType::createAudioIODeviceType_Bela()            { return nullptr; }
 #endif
 
