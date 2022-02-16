Index: external/pdfium/Library_pdfium.mk
--- external/pdfium/Library_pdfium.mk.orig	2022-01-26 14:35:29 UTC
+++ external/pdfium/Library_pdfium.mk
@@ -726,7 +726,7 @@ $(eval $(call gb_Library_add_generated_exception_objec
 ))
 endif
 
-ifeq ($(OS),LINUX)
+ifneq (,$(filter LINUX FREEBSD OPENBSD,$(OS)))
 # fxge
 $(eval $(call gb_Library_add_generated_exception_objects,pdfium,\
     UnpackedTarball/pdfium/core/fxge/linux/fx_linux_impl \
