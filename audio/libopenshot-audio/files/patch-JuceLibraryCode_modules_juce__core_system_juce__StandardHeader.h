--- JuceLibraryCode/modules/juce_core/system/juce_StandardHeader.h.orig	2020-09-11 12:10:25 UTC
+++ JuceLibraryCode/modules/juce_core/system/juce_StandardHeader.h
@@ -80,7 +80,7 @@
  #endif
 #endif
 
-#if JUCE_LINUX
+#if JUCE_BSD || JUCE_LINUX
  #include <cstring>
  #include <signal.h>
 
