--- JuceLibraryCode/modules/juce_audio_devices/juce_audio_devices.cpp.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_audio_devices/juce_audio_devices.cpp
@@ -119,7 +119,7 @@
  #endif
 
 //==============================================================================
-#elif JUCE_LINUX
+#elif JUCE_BSD || JUCE_LINUX
  #if JUCE_ALSA
   /* Got an include error here? If so, you've either not got ALSA installed, or you've
      not got your paths set up correctly to find its header files.
@@ -212,7 +212,7 @@
  #endif
 
 //==============================================================================
-#elif JUCE_LINUX
+#elif JUCE_BSD || JUCE_LINUX
  #if JUCE_ALSA
   #include "native/juce_linux_ALSA.cpp"
  #endif
