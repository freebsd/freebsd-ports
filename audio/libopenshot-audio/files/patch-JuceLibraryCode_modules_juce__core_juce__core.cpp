--- JuceLibraryCode/modules/juce_core/juce_core.cpp.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_core/juce_core.cpp
@@ -66,7 +66,7 @@
  #endif
 
 #else
- #if JUCE_LINUX || JUCE_ANDROID
+ #if JUCE_BSD || JUCE_LINUX || JUCE_ANDROID
   #include <sys/types.h>
   #include <sys/socket.h>
   #include <sys/errno.h>
@@ -74,7 +74,7 @@
   #include <netinet/in.h>
  #endif
 
- #if JUCE_LINUX
+ #if JUCE_BSD || JUCE_LINUX
   #include <stdio.h>
   #include <langinfo.h>
   #include <ifaddrs.h>
@@ -209,7 +209,7 @@
 #include "native/juce_win32_Threads.cpp"
 
 //==============================================================================
-#elif JUCE_LINUX
+#elif JUCE_BSD || JUCE_LINUX
 #include "native/juce_linux_CommonFile.cpp"
 #include "native/juce_linux_Files.cpp"
 #include "native/juce_linux_Network.cpp"
