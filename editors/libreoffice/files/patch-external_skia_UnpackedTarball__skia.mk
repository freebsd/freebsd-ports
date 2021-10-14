--- external/skia/UnpackedTarball_skia.mk.orig	2021-02-05 14:00:19 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -41,6 +41,7 @@ skia_patches := \
     fix-warnings.patch.1 \
     disable-freetype-colrv1.1 \
     windows-libraries-system32.patch.1 \
+    gfx-skia-skia-src-core-SkCpu.cpp.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
