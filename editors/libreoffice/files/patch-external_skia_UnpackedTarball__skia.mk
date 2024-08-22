--- external/skia/UnpackedTarball_skia.mk.orig	2024-06-11 10:45:33 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -43,6 +43,7 @@ skia_patches := \
     0001-AvoidCombiningExtrememelyLargeMeshes.patch.1 \
     sort-comparison-assumption.patch.0 \
     help-msvc-analyzer.patch \
+    powerpc64le-skia.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
