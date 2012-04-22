--- ./sd/Module_sd.mk.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./sd/Module_sd.mk	2012-04-16 14:24:48.000000000 +0200
@@ -40,16 +40,6 @@
     Package_xml \
 ))
 
-ifneq ($(OS),DRAGONFLY)
-$(eval $(call gb_Module_add_check_targets,sd,\
-    CppunitTest_sd_uimpress \
-))
-# disabled for now, seems to have incomplete deps and hangs on a build from scratch
-#    CppunitTest_sd_filters_test \
-
-endif
-
-
 $(eval $(call gb_Module_add_subsequentcheck_targets,sd,\
     JunitTest_sd_unoapi \
 ))
