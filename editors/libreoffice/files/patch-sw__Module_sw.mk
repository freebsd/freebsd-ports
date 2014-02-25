--- sw/Module_sw.mk.orig	2013-12-11 01:11:21.000000000 +0900
+++ sw/Module_sw.mk	2014-01-29 17:12:45.000000000 +0900
@@ -41,14 +41,8 @@
 
 endif
 
-$(eval $(call gb_Module_add_check_targets,sw,\
-    CppunitTest_sw_uwriter \
-))
-
 $(eval $(call gb_Module_add_slowcheck_targets,sw,\
     CppunitTest_sw_htmlexport \
-    CppunitTest_sw_macros_test \
-    CppunitTest_sw_ooxmlexport \
     CppunitTest_sw_ooxmlimport \
     CppunitTest_sw_ww8export \
     CppunitTest_sw_ww8import \
