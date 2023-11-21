--- external/skia/UnpackedTarball_skia.mk.orig	2023-09-22 19:07:01 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -39,6 +39,8 @@ skia_patches := \
     tdf147342.patch.0 \
     redefinition-of-op.patch.0 \
     0001-Added-missing-include-cstdio.patch \
+    gfx-skia-skia-src-core-SkCpu.cpp.patch.0 \
+    powerpc64le-skia.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
