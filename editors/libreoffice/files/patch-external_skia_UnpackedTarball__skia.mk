--- external/skia/UnpackedTarball_skia.mk.orig	2024-11-22 20:05:31 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -41,6 +41,8 @@ skia_patches := \
     help-msvc-analyzer.patch \
     always_inline_and_multiversioning_conflict.patch.1 \
     windows-define-conflict.patch.1 \
+    freebsd-limits.h.patch.0 \
+    powerpc64le-skia.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
