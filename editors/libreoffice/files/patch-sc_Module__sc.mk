--- sc/Module_sc.mk.orig	2017-05-03 16:46:29 UTC
+++ sc/Module_sc.mk
@@ -45,7 +45,8 @@ $(eval $(call gb_Module_add_check_targets,sc,\
 	$(if $(and $(filter $(COM),MSC),$(MERGELIBS)),, \
 		CppunitTest_sc_ucalc) \
 	CppunitTest_sc_bugfix_test \
-	CppunitTest_sc_filters_test \
+	$(if $(filter FREEBSD,$(OS)),, \
+		CppunitTest_sc_filters_test) \
 	CppunitTest_sc_rangelst_test \
 	CppunitTest_sc_mark_test \
 	CppunitTest_sc_core \
@@ -60,8 +61,9 @@ endif
 $(eval $(call gb_Module_add_slowcheck_targets,sc, \
 	CppunitTest_sc_condformats \
 	CppunitTest_sc_new_cond_format_api \
-	CppunitTest_sc_subsequent_filters_test \
-	CppunitTest_sc_subsequent_export_test \
+	$(if $(filter FREEBSD,$(OS)),, \
+		CppunitTest_sc_subsequent_filters_test \
+		CppunitTest_sc_subsequent_export_test) \
 	CppunitTest_sc_html_export_test \
 	CppunitTest_sc_opencl_test \
 	CppunitTest_sc_copypaste \
@@ -71,7 +73,7 @@ $(eval $(call gb_Module_add_slowcheck_targets,sc, \
 # point weirdness (x87, registers, compiler optimization, ... whatever),
 # disable them until someone finds a real cure.
 
-ifneq ($(PLATFORMID),linux_x86)
+ifeq ($(filter freebsd_x86 linux_x86,$(PLATFORMID)),)
 $(eval $(call gb_Module_add_slowcheck_targets,sc, \
 	CppunitTest_sc_functions_test \
 ))
