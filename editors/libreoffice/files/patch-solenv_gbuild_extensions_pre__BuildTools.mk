See https://git.libreoffice.org/core/+/0e7d4d99beda181f4e22725e4b8295d25489696f

--- solenv/gbuild/extensions/pre_BuildTools.mk.orig	2021-08-16 19:56:28 UTC
+++ solenv/gbuild/extensions/pre_BuildTools.mk
@@ -47,7 +47,6 @@ gb_BUILD_TOOLS = \
     $(foreach executable,$(gb_BUILD_TOOLS_executables),$(call gb_Executable_get_runtime_dependencies,$(executable))) \
     $(foreach executable,$(gb_BUILD_TOOLS_executables_extern),$(call gb_ExternalExecutable_get_dependencies,$(executable))) \
 	$(INSTROOT)/$(LIBO_URE_ETC_FOLDER)/$(call gb_Helper_get_rcfile,uno) \
-    $(if $(WITH_GALLERY_BUILD),$(call gb_Library_get_target,localedata_en)) \
 
 endif
 
