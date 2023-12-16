--- external/skia/UnpackedTarball_skia.mk.orig	2023-11-30 13:04:41 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -40,6 +40,8 @@ skia_patches := \
     redefinition-of-op.patch.0 \
     0001-Added-missing-include-cstdio.patch \
     0001-AvoidCombiningExtrememelyLargeMeshes.patch.1 \
+    gfx-skia-skia-src-core-SkCpu.cpp.patch.0 \
+    powerpc64le-skia.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
