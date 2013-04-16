--- ./sd/Module_sd.mk.orig	2013-03-12 07:00:34.000000000 -0400
+++ ./sd/Module_sd.mk	2013-03-20 16:36:08.000000000 -0400
@@ -44,7 +44,6 @@
 
 ifneq ($(OS),DRAGONFLY)
 $(eval $(call gb_Module_add_check_targets,sd,\
-    CppunitTest_sd_uimpress \
     CppunitTest_sd_regression_test \
     CppunitTest_sd_filters_test \
 ))
