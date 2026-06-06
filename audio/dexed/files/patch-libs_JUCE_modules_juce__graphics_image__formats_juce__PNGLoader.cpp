--- libs/JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp.orig	2026-06-06 18:04:25 UTC
+++ libs/JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp
@@ -266,6 +266,7 @@
   #define PNG_LINKAGE_FUNCTION
 
   #define PNG_ARM_NEON_OPT 0
+  #define PNG_POWERPC_VSX_OPT 0
 
   #if ! defined (PNG_USER_WIDTH_MAX)
    #define PNG_USER_WIDTH_MAX 1000000
