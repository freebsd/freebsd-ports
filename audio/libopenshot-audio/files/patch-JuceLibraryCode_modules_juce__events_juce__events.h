--- JuceLibraryCode/modules/juce_events/juce_events.h.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_events/juce_events.h
@@ -89,7 +89,7 @@
 #include "interprocess/juce_ConnectedChildProcess.h"
 #include "interprocess/juce_NetworkServiceDiscovery.h"
 
-#if JUCE_LINUX
+#if JUCE_BSD || JUCE_LINUX
  #include "native/juce_linux_EventLoop.h"
 #endif
 
