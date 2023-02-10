--- external/skia/UnpackedTarball_skia.mk.orig	2022-05-12 13:26:05 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -40,6 +40,7 @@ skia_patches := \
     tdf148624.patch.1 \
     constexpr-template.patch.0 \
     missing-include.patch.0 \
+    gfx-skia-skia-src-core-SkCpu.cpp.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
