--- sd/Module_sd.mk.orig	2013-12-11 01:11:21.000000000 +0900
+++ sd/Module_sd.mk	2014-01-29 17:01:07.000000000 +0900
@@ -24,7 +24,6 @@
 
 ifneq ($(OS),DRAGONFLY)
 $(eval $(call gb_Module_add_check_targets,sd,\
-    CppunitTest_sd_uimpress \
     CppunitTest_sd_import_tests \
     CppunitTest_sd_filters_test \
 ))
