--- external/skia/UnpackedTarball_skia.mk.orig	2025-05-10 18:09:26 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -44,6 +44,7 @@ skia_patches := \
 	0004-loong64-Fix-the-remaining-implicit-vector-casts.patch \
     msvc-unknown-attributes.patch.1 \
 	fix-semaphore-include.patch.1 \
+    freebsd-limits.h.patch.0 \
 
 ifneq ($(MSYSTEM),)
 # use binary flag so patch from git-bash won't choke on mixed line-endings in patches
