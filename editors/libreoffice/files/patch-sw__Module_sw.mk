--- ./sw/Module_sw.mk.orig	2013-01-31 05:54:53.000000000 -0500
+++ ./sw/Module_sw.mk	2013-02-22 14:30:05.000000000 -0500
@@ -37,10 +37,6 @@
 
 endif
 
-$(eval $(call gb_Module_add_check_targets,sw,\
-    CppunitTest_sw_swdoc_test \
-))
-
 $(eval $(call gb_Module_add_slowcheck_targets,sw,\
     CppunitTest_sw_macros_test \
     CppunitTest_sw_subsequent_ooxmlexport \
