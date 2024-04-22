--- external/skia/UnpackedTarball_skia.mk.orig	2023-12-08 15:11:48 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -41,6 +41,7 @@ skia_patches := \
     ubsan-missing-typeinfo.patch.1 \
     incomplete-type-SkImageGenerator.patch.1 \
     0001-AvoidCombiningExtrememelyLargeMeshes.patch.1 \
+    powerpc64le-skia.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
