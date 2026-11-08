--- modules/juce_graphics/juce_graphics_libpng.c.orig	2026-08-30 05:59:56 UTC
+++ modules/juce_graphics/juce_graphics_libpng.c
@@ -87,5 +87,7 @@ JUCE_BEGIN_IGNORE_WARNINGS_MSVC (4146 4996)
 #include "juce_graphics/image_formats/pnglib/arm/arm_init.c"
 #include "juce_graphics/image_formats/pnglib/arm/filter_neon_intrinsics.c"
 #include "juce_graphics/image_formats/pnglib/arm/palette_neon_intrinsics.c"
+#include "juce_graphics/image_formats/pnglib/powerpc/powerpc_init.c"
+#include "juce_graphics/image_formats/pnglib/powerpc/filter_vsx_intrinsics.c"
 
 #endif
