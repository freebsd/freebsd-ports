--- ./sw/Module_sw.mk.orig	2013-03-12 07:00:34.000000000 -0400
+++ ./sw/Module_sw.mk	2013-03-21 13:32:32.000000000 -0400
@@ -37,13 +37,7 @@
 
 endif
 
-$(eval $(call gb_Module_add_check_targets,sw,\
-    CppunitTest_sw_swdoc_test \
-))
-
 $(eval $(call gb_Module_add_slowcheck_targets,sw,\
-    CppunitTest_sw_macros_test \
-    CppunitTest_sw_subsequent_ooxmlexport \
     CppunitTest_sw_subsequent_ooxmlimport \
     CppunitTest_sw_subsequent_ww8export \
     CppunitTest_sw_subsequent_ww8import \
