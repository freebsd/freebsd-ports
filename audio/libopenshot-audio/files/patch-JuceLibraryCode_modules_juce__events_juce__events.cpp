--- JuceLibraryCode/modules/juce_events/juce_events.cpp.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_events/juce_events.cpp
@@ -49,7 +49,7 @@
  #import <IOKit/hid/IOHIDKeys.h>
  #import <IOKit/pwr_mgt/IOPMLib.h>
 
-#elif JUCE_LINUX
+#elif JUCE_BSD || JUCE_LINUX
  #include <unistd.h>
 #endif
 
@@ -94,7 +94,7 @@
   #include "native/juce_win32_WinRTWrapper.cpp"
  #endif
 
-#elif JUCE_LINUX
+#elif JUCE_BSD || JUCE_LINUX
  #include "native/juce_linux_Messaging.cpp"
 
 #elif JUCE_ANDROID
