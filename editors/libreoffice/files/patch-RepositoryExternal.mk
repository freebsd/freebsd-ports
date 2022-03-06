--- RepositoryExternal.mk.orig	2022-02-28 18:19:33 UTC
+++ RepositoryExternal.mk
@@ -4203,6 +4203,7 @@ $(call gb_LinkTarget_set_include,$(1),\
        $$(INCLUDE) \
 )
 $(call gb_LinkTarget_use_libraries,$(1),pdfium)
+$(call gb_LinkTarget_add_libs,$(1),$(OPENJPEG2_LIBS))
 endef
 $(eval $(call gb_Helper_register_libraries_for_install,OOOLIBS,ooo,\
        pdfium \
