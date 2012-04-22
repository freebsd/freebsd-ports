--- ./sc/Module_sc.mk.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./sc/Module_sc.mk	2012-04-16 14:24:48.000000000 +0200
@@ -34,11 +34,6 @@
 	Package_xml \
 ))
 
-$(eval $(call gb_Module_add_check_targets,sc,\
-    CppunitTest_sc_filters_test \
-    CppunitTest_sc_ucalc \
-))
-
 $(eval $(call gb_Module_add_subsequentcheck_targets,sc,\
     CppunitTest_sc_macros_test \
     CppunitTest_sc_cellrangesbase \
