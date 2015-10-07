--- sd/Module_sd.mk.orig	2015-08-22 06:41:35 UTC
+++ sd/Module_sd.mk
@@ -25,7 +25,7 @@ $(eval $(call gb_Module_add_l10n_targets
     UIConfig_simpress \
 ))
 
-ifneq ($(OS),DRAGONFLY)
+ifeq ($(filter DRAGONFLY FREEBSD,$(OS)),)
 $(eval $(call gb_Module_add_check_targets,sd,\
 	$(if $(and $(filter $(COM),MSC),$(MERGELIBS)),, \
 		CppunitTest_sd_uimpress) \
