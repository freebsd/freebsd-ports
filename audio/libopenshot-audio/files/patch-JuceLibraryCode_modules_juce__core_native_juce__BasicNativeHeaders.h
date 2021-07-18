--- JuceLibraryCode/modules/juce_core/native/juce_BasicNativeHeaders.h.orig	2021-05-09 14:57:33 UTC
+++ JuceLibraryCode/modules/juce_core/native/juce_BasicNativeHeaders.h
@@ -272,6 +272,9 @@
  #include <sys/wait.h>
  #include <utime.h>
  #include <poll.h>
+ #include <net/if_dl.h>
+ #include <pthread_np.h>
+ #include <sys/sysinfo.h>
 
 //==============================================================================
 #elif JUCE_ANDROID
