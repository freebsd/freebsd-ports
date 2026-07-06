--- src/deps/juce/modules/juce_graphics/image_formats/juce_PNGLoader.cpp.orig	2026-06-06 17:17:21 UTC
+++ src/deps/juce/modules/juce_graphics/image_formats/juce_PNGLoader.cpp
@@ -254,6 +254,7 @@
   #define PNG_LINKAGE_FUNCTION
 
   #define PNG_ARM_NEON_OPT 0
+  #define PNG_POWERPC_VSX_OPT 0
 
   #if ! defined (PNG_USER_WIDTH_MAX)
    #define PNG_USER_WIDTH_MAX 1000000
