--- RepositoryExternal.mk.orig	2022-12-22 00:14:09 UTC
+++ RepositoryExternal.mk
@@ -4157,6 +4157,7 @@ $(call gb_LinkTarget_use_libraries,$(1),pdfium)
        $$(INCLUDE) \
 )
 $(call gb_LinkTarget_use_libraries,$(1),pdfium)
+$(call gb_LinkTarget_add_libs,$(1),$(OPENJPEG2_LIBS))
 endef
 $(eval $(call gb_Helper_register_libraries_for_install,OOOLIBS,ooo,\
        pdfium \
