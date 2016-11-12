--- sc/Module_sc.mk.orig	2016-10-28 14:50:26 UTC
+++ sc/Module_sc.mk
@@ -54,7 +54,8 @@ $(eval $(call gb_Module_add_check_target
 $(eval $(call gb_Module_add_slowcheck_targets,sc, \
 	CppunitTest_sc_condformats \
 	CppunitTest_sc_new_cond_format_api \
-	CppunitTest_sc_subsequent_filters_test \
+	$(if $(filter FREEBSD,$(OS)),, \
+		CppunitTest_sc_subsequent_filters_test) \
 	CppunitTest_sc_subsequent_export_test \
 	CppunitTest_sc_html_export_test \
 	CppunitTest_sc_opencl_test \
