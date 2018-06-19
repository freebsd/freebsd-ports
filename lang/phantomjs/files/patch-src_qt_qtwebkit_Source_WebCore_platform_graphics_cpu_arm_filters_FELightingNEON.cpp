.obj/platform/graphics/cpu/arm/filters/FELightingNEON.o ---
<inline asm>:149:1: error: invalid instruction
vmov.u32 r2, r3, s8, s9
^

Obtained from: www/webkit-gtk3/files/patch-Source_WebCore_platform_graphics_cpu_arm_filters_FELightingNEON.cpp

--- src/qt/qtwebkit/Source/WebCore/platform/graphics/cpu/arm/filters/FELightingNEON.cpp.orig	2018-06-12 14:38:27 UTC
+++ src/qt/qtwebkit/Source/WebCore/platform/graphics/cpu/arm/filters/FELightingNEON.cpp
@@ -404,7 +404,7 @@ TOSTRING(neonDrawLighting) ":" NL
     "vmin.f32 " TMP2_D0 ", " TMP2_D0 ", " CONST_ONE_HI_D NL
     "vmul.f32 " TMP3_Q ", " COLOR_Q ", " TMP2_D0 "[1]" NL
     "vcvt.u32.f32 " TMP3_Q ", " TMP3_Q NL
-    "vmov.u32 r2, r3, " TMP3_S0 ", " TMP3_S1 NL
+    "vmov r2, r3, " TMP3_S0 ", " TMP3_S1 NL
     // The color values are stored in-place.
     "strb r2, [" PIXELS_R ", #-11]" NL
     "strb r3, [" PIXELS_R ", #-10]" NL
