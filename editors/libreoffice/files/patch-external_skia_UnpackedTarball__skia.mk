--- external/skia/UnpackedTarball_skia.mk.orig	2022-01-26 14:35:29 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -37,6 +37,7 @@ skia_patches := \
     disable-freetype-colrv1.1 \
     windows-libraries-system32.patch.1 \
     fix-graphite-ifdef.patch.1 \
+    gfx-skia-skia-src-core-SkCpu.cpp.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
