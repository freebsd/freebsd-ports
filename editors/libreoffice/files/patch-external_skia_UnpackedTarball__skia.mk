--- external/skia/UnpackedTarball_skia.mk.orig	2020-11-11 11:32:22 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -38,7 +38,8 @@ skia_patches := \
     windows-typeface-directwrite.patch.0 \
     windows-raster-surface-no-copies.patch.1 \
     fix-windows-dwrite.patch.1 \
-    public-make-from-backend-texture.patch.1 \
+    public-make-from-backend-texture.patch.1 \
+    gfx-skia-skia-src-core-SkCpu.cpp.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
