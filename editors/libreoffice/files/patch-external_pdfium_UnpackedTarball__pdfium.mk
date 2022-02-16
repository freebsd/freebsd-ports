Index: external/pdfium/UnpackedTarball_pdfium.mk
--- external/pdfium/UnpackedTarball_pdfium.mk.orig	2022-01-26 14:35:29 UTC
+++ external/pdfium/UnpackedTarball_pdfium.mk
@@ -24,6 +24,8 @@ pdfium_patches += AndroidNDK19.patch.1
 # --with-latest-c++:
 pdfium_patches += gcc-c++20-comparison.patch
 
+pdfium_patches += pdfium-bsd.patch
+
 $(eval $(call gb_UnpackedTarball_UnpackedTarball,pdfium))
 
 $(eval $(call gb_UnpackedTarball_set_tarball,pdfium,$(PDFIUM_TARBALL)))
