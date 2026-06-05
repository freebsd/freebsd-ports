--- libs/JUCELV2/modules/juce_graphics/image_formats/juce_PNGLoader.cpp.orig	2026-06-05 05:17:21 UTC
+++ libs/JUCELV2/modules/juce_graphics/image_formats/juce_PNGLoader.cpp
@@ -264,6 +264,7 @@ namespace pnglibNamespace
   #define PNG_LINKAGE_FUNCTION
 
   #define PNG_ARM_NEON_OPT 0
+  #define PNG_POWERPC_VSX_OPT 0
 
   #if ! defined (PNG_USER_WIDTH_MAX)
    #define PNG_USER_WIDTH_MAX 1000000
