--- external/skia/UnpackedTarball_skia.mk.orig	2025-05-10 18:09:26 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -43,6 +43,7 @@ skia_patches := \
 	0002-loong64-Honor-existing-LASX-LSX-settings.patch \
 	0003-loong64-Fix-missing-rounding-in-loong64-scaled_mult-.patch \
 	0004-loong64-Fix-the-remaining-implicit-vector-casts.patch \
+    freebsd-limits.h.patch.0 \
 
 ifneq ($(MSYSTEM),)
 # use binary flag so patch from git-bash won't choke on mixed line-endings in patches
