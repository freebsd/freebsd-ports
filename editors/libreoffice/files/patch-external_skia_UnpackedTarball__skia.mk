--- external/skia/UnpackedTarball_skia.mk.orig	2025-05-10 18:09:26 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -45,6 +45,7 @@ skia_patches := \
     msvc-unknown-attributes.patch.1 \
 	fix-semaphore-include.patch.1 \
 	fix-xputimage-depth.patch.1 \
+    freebsd-limits.h.patch.0 \
 
 ifneq ($(MSYSTEM),)
 # use binary flag so patch from git-bash won't choke on mixed line-endings in patches
