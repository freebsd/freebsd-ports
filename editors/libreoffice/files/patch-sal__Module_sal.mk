--- ./sal/Module_sal.mk.orig	2012-03-27 18:22:01.000000000 +0200
+++ ./sal/Module_sal.mk	2012-04-16 14:24:48.000000000 +0200
@@ -28,12 +28,4 @@
 
 $(eval $(call gb_Module_Module,sal))
 
-$(eval $(call gb_Module_add_subsequentcheck_targets,sal,\
-	CppunitTest_sal_osl_mutex \
-	CppunitTest_sal_osl_pipe \
-	CppunitTest_sal_osl_profile \
-	CppunitTest_sal_osl_setthreadname \
-	CppunitTest_sal_rtl_math \
-))
-
 # vim: set noet sw=4 ts=4:
