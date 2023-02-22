--- src/JuceLibraryCode/modules/juce_core/juce_core.cpp.orig	2020-02-23 16:47:36 UTC
+++ src/JuceLibraryCode/modules/juce_core/juce_core.cpp
@@ -123,6 +123,10 @@
  #define   JUCE_STANDALONE_APPLICATION 0
 #endif
 
+#include <sys/sysinfo.h>
+
+extern char **environ;
+
 //==============================================================================
 namespace juce
 {
