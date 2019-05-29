--- JuceLibraryCode/modules/juce_core/juce_core.h.orig	2019-04-17 16:56:20 UTC
+++ JuceLibraryCode/modules/juce_core/juce_core.h
@@ -137,7 +137,7 @@
     If you disable this then https/ssl support will not be available on linux.
 */
 #ifndef JUCE_USE_CURL
- #if JUCE_LINUX
+ #if JUCE_BSD || JUCE_LINUX
   #define JUCE_USE_CURL 1
  #else
   #define JUCE_USE_CURL 0
