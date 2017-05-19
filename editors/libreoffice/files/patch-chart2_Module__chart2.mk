--- chart2/Module_chart2.mk.orig	2017-05-03 16:46:29 UTC
+++ chart2/Module_chart2.mk
@@ -30,7 +30,8 @@ $(eval $(call gb_Module_add_check_targets,chart2,\
 ))
 
 $(eval $(call gb_Module_add_slowcheck_targets,chart2,\
-    CppunitTest_chart2_export \
+    $(if $(filter FREEBSD,$(OS)),, \
+        CppunitTest_chart2_export) \
     CppunitTest_chart2_import \
     CppunitTest_chart2_trendcalculators \
 ))
