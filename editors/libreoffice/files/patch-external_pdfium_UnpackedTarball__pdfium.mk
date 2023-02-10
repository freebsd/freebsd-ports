Index: external/pdfium/UnpackedTarball_pdfium.mk
--- external/pdfium/UnpackedTarball_pdfium.mk.orig	2022-12-22 00:14:09 UTC
+++ external/pdfium/UnpackedTarball_pdfium.mk
@@ -25,6 +25,8 @@ pdfium_patches += constexpr-template.patch
 
 pdfium_patches += constexpr-template.patch
 
+pdfium_patches += pdfium-bsd.patch
+
 $(eval $(call gb_UnpackedTarball_UnpackedTarball,pdfium))
 
 $(eval $(call gb_UnpackedTarball_set_tarball,pdfium,$(PDFIUM_TARBALL)))
