--- JuceLibraryCode/modules/juce_core/system/juce_StandardHeader.h.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_core/system/juce_StandardHeader.h
@@ -72,7 +72,7 @@
  #include <xlocale.h>
 #endif
 
-#if JUCE_LINUX
+#if JUCE_BSD || JUCE_LINUX
  #include <cstring>
  #include <signal.h>
 
