--- external/skia/UnpackedTarball_skia.mk.orig	2021-09-08 17:53:20 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -39,6 +39,8 @@ skia_patches := \
     fast-png-write.patch.1 \
     skia_sk_cpu_sse_level_0_by_default.patch.1 \
     fix-warnings.patch.1 \
+    gfx-skia-skia-src-core-SkCpu.cpp.patch.0 \
+    skia-freetype2.11.patch \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
