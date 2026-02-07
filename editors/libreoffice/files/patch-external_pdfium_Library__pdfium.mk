Index: external/pdfium/Library_pdfium.mk
--- external/pdfium/Library_pdfium.mk.orig	2022-12-22 00:14:09 UTC
+++ external/pdfium/Library_pdfium.mk
@@ -718,7 +718,7 @@ endif
 ))
 endif
 
-ifeq ($(OS),LINUX)
+ifneq (,$(filter LINUX FREEBSD OPENBSD,$(OS)))
 # fxge
 $(eval $(call gb_Library_add_generated_exception_objects,pdfium,\
     UnpackedTarball/pdfium/core/fxge/linux/fx_linux_impl \
