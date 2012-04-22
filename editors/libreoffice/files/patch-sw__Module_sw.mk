--- ./sw/Module_sw.mk.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./sw/Module_sw.mk	2012-04-16 14:24:48.000000000 +0200
@@ -40,12 +40,6 @@
     Package_xml \
 ))
 
-$(eval $(call gb_Module_add_check_targets,sw,\
-    CppunitTest_sw_filters_test \
-    CppunitTest_sw_macros_test \
-    CppunitTest_sw_swdoc_test \
-))
-
 $(eval $(call gb_Module_add_subsequentcheck_targets,sw,\
     JunitTest_sw_complex \
     JunitTest_sw_unoapi \
