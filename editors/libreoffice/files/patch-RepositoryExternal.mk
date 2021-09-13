See https://git.libreoffice.org/core/+/0e7d4d99beda181f4e22725e4b8295d25489696f

--- RepositoryExternal.mk.orig	2021-08-16 19:56:28 UTC
+++ RepositoryExternal.mk
@@ -3870,6 +3870,7 @@ endef
 define gb_Executable__register_gengal
 $(call gb_Executable_add_runtime_dependencies,gengal,\
 	$(call gb_Library_get_target_for_build,$(CPPU_ENV_FOR_BUILD)_uno) \
+	$(call gb_Library_get_target_for_build,localedata_en) \
 	$(if $(filter MACOSX,$(OS_FOR_BUILD)),$(call gb_Library_get_target_for_build,vclplug_osx)) \
 	$(if $(filter WNT,$(OS_FOR_BUILD)),$(call gb_Library_get_target_for_build,vclplug_win)) \
 	$(if $(filter host,$(gb_Side)),$(call gb_Package_get_target,postprocess_images)) \
