--- dbaccess/Module_dbaccess.mk.orig	2017-04-25 20:44:01 UTC
+++ dbaccess/Module_dbaccess.mk
@@ -35,16 +35,19 @@ $(eval $(call gb_Module_add_l10n_targets,dbaccess,\
 ))
 
 ifeq ($(ENABLE_FIREBIRD_SDBC),TRUE)
+ifneq ($(OS),FREEBSD)
 $(eval $(call gb_Module_add_check_targets,dbaccess,\
     CppunitTest_dbaccess_firebird_test \
 ))
 endif
+endif
 
 $(eval $(call gb_Module_add_check_targets,dbaccess,\
 	CppunitTest_dbaccess_dialog_save \
 	CppunitTest_dbaccess_empty_stdlib_save \
 	CppunitTest_dbaccess_nolib_save \
-	CppunitTest_dbaccess_macros_test \
+	$(if $(filter FREEBSD,$(OS)),, \
+		CppunitTest_dbaccess_macros_test) \
 	$(if $(ENABLE_JAVA), \
 		CppunitTest_dbaccess_RowSetClones) \
 ))
