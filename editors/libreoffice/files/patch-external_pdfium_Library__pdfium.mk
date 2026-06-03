- fix https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=294276: libpdfiumlo.so that libreoffice installs has at least one undefined symbol: opj_image_destroy

--- external/pdfium/Library_pdfium.mk.orig
+++ external/pdfium/Library_pdfium.mk
@@ -635,8 +635,21 @@
     UnpackedTarball/pdfium/third_party/freetype/src/src/type1/type1 \
     UnpackedTarball/pdfium/third_party/freetype/src/src/base/ftdebug \
     UnpackedTarball/pdfium/third_party/freetype/src/src/base/ftfstype \
+))
+
+ifeq ($(OS),FREEBSD)
+ifeq ($(SYSTEM_OPENJPEG2),TRUE)
+$(eval $(call gb_Library_add_libs,pdfium,\
+    $(OPENJPEG2_LIBS) \
 ))
 endif
+ifeq ($(SYSTEM_ABSEIL),TRUE)
+$(eval $(call gb_Library_add_libs,pdfium,\
+    $(ABSEIL_LIBS) \
+))
+endif
+endif
+endif
 
 ifneq ($(OS),WNT)
 $(eval $(call gb_Library_add_generated_exception_objects,pdfium,\
