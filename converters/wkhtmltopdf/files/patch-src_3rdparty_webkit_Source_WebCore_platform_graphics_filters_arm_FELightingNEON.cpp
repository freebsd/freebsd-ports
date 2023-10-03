--- src/3rdparty/webkit/Source/WebCore/platform/graphics/filters/arm/FELightingNEON.cpp.orig	2023-10-03 22:30:40 UTC
+++ src/3rdparty/webkit/Source/WebCore/platform/graphics/filters/arm/FELightingNEON.cpp
@@ -398,11 +398,11 @@ TOSTRING(neonDrawLighting) ":" NL
     "vmin.f32 " TMP2_D0 ", " TMP2_D0 ", " CONST_ONE_HI_D NL
     "vmul.f32 " TMP3_Q ", " COLOR_Q ", " TMP2_D0 "[1]" NL
     "vcvt.u32.f32 " TMP3_Q ", " TMP3_Q NL
-    "vmov.u32 r2, r3, " TMP3_S0 ", " TMP3_S1 NL
+    "vmov r2, r3, " TMP3_S0 ", " TMP3_S1 NL
     // The color values are stored in-place.
     "strb r2, [" PIXELS_R ", #-11]" NL
     "strb r3, [" PIXELS_R ", #-10]" NL
-    "vmov.u32 r2, " TMP3_S2 NL
+    "vmov r2, " TMP3_S2 NL
     "strb r2, [" PIXELS_R ", #-9]" NL
 
     // Continue to the next pixel.
