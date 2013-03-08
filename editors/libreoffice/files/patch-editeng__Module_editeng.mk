--- editeng/Module_editeng.mk.orig	2013-01-31 05:54:53.000000000 -0500
+++ editeng/Module_editeng.mk	2013-02-22 14:31:45.000000000 -0500
@@ -28,7 +28,6 @@
 # add any runtime tests (unit tests) here
 # remove if no tests
 $(eval $(call gb_Module_add_check_targets,editeng,\
-    CppunitTest_editeng_core \
     CppunitTest_editeng_borderline \
     CppunitTest_editeng_lookuptree \
 ))
