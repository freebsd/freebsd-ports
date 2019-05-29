--- JuceLibraryCode/modules/juce_core/threads/juce_Process.h.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_core/threads/juce_Process.h
@@ -139,7 +139,7 @@ class JUCE_API  Process (public)
     static void setDockIconVisible (bool isVisible);
    #endif
 
-   #if JUCE_MAC || JUCE_LINUX || DOXYGEN
+   #if JUCE_BSD || JUCE_MAC || JUCE_LINUX || DOXYGEN
     //==============================================================================
     /** UNIX ONLY - Attempts to use setrlimit to change the maximum number of file
         handles that the app can open. Pass 0 or less as the parameter to mean
