--- editeng/Module_editeng.mk.orig	2014-09-16 16:10:41.000000000 -0400
+++ editeng/Module_editeng.mk	2014-10-08 17:20:09.000000000 -0400
@@ -28,8 +28,6 @@
 ))
 
 $(eval $(call gb_Module_add_check_targets,editeng,\
-	$(if $(and $(filter $(COM),MSC),$(MERGELIBS)),, \
-		CppunitTest_editeng_core) \
 	CppunitTest_editeng_borderline \
 	CppunitTest_editeng_lookuptree \
 ))
