--- JuceLibraryCode/modules/juce_events/juce_events.h.orig	2020-09-11 12:10:25 UTC
+++ JuceLibraryCode/modules/juce_events/juce_events.h
@@ -90,7 +90,7 @@
 #include "interprocess/juce_ConnectedChildProcess.h"
 #include "interprocess/juce_NetworkServiceDiscovery.h"
 
-#if JUCE_LINUX
+#if JUCE_BSD || JUCE_LINUX
  #include "native/juce_linux_EventLoop.h"
 #endif
 
