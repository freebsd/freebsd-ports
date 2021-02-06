--- external/skia/UnpackedTarball_skia.mk.orig	2021-02-05 14:00:19 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -36,7 +36,8 @@ skia_patches := \
     c++20.patch.0 \
     constexpr-debug-std-max.patch.1 \
     swap-buffers-rect.patch.1 \
-    ubsan.patch.0
+    ubsan.patch.0 \
+    gfx-skia-skia-src-core-SkCpu.cpp.patch.0
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
