--- JuceLibraryCode/modules/juce_core/native/juce_BasicNativeHeaders.h.orig	2020-09-11 12:10:25 UTC
+++ JuceLibraryCode/modules/juce_core/native/juce_BasicNativeHeaders.h
@@ -272,6 +272,8 @@
  #include <sys/wait.h>
  #include <utime.h>
  #include <poll.h>
+ #include <net/if_dl.h>
+ #include <pthread_np.h>
 
 //==============================================================================
 #elif JUCE_ANDROID
