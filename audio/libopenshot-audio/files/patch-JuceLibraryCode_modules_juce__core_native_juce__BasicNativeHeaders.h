--- JuceLibraryCode/modules/juce_core/native/juce_BasicNativeHeaders.h.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_core/native/juce_BasicNativeHeaders.h
@@ -261,6 +261,7 @@
  #include <sys/types.h>
  #include <sys/wait.h>
  #include <utime.h>
+ #include <net/if_dl.h>
 
 //==============================================================================
 #elif JUCE_ANDROID
