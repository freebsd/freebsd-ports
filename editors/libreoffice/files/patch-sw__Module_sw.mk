--- sw/Module_sw.mk.orig	2014-09-16 16:10:41.000000000 -0400
+++ sw/Module_sw.mk	2014-10-08 17:26:44.000000000 -0400
@@ -47,10 +47,7 @@
 endif
 
 $(eval $(call gb_Module_add_slowcheck_targets,sw,\
-    CppunitTest_sw_uwriter \
     CppunitTest_sw_htmlexport \
-    CppunitTest_sw_macros_test \
-    CppunitTest_sw_ooxmlexport \
     CppunitTest_sw_ooxmlsdrexport \
     CppunitTest_sw_ooxmlw14export \
     CppunitTest_sw_ooxmlimport \
