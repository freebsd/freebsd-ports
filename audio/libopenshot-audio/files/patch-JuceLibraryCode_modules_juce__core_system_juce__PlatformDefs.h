--- JuceLibraryCode/modules/juce_core/system/juce_PlatformDefs.h.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_core/system/juce_PlatformDefs.h
@@ -57,7 +57,7 @@ namespace juce
 #endif
 
 //==============================================================================
-#if JUCE_IOS || JUCE_LINUX
+#if JUCE_BSD || JUCE_IOS || JUCE_LINUX
   /** This will try to break into the debugger if the app is currently being debugged.
       If called by an app that's not being debugged, the behaviour isn't defined - it may
       crash or not, depending on the platform.
