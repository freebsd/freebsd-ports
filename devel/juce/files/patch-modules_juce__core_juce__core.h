--- modules/juce_core/juce_core.h.orig	2021-04-02 18:08:09 UTC
+++ modules/juce_core/juce_core.h
@@ -64,6 +64,11 @@
 
 #include "system/juce_TargetPlatform.h"
 
+#ifdef JUCE_INCLUDE_PNGLIB_CODE
+# undef JUCE_INCLUDE_PNGLIB_CODE
+#endif
+#define JUCE_INCLUDE_PNGLIB_CODE 0
+
 //==============================================================================
 /** Config: JUCE_FORCE_DEBUG
 
