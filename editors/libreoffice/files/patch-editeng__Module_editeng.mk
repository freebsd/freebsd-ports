--- ./editeng/Module_editeng.mk.orig	2013-03-12 07:00:34.000000000 -0400
+++ ./editeng/Module_editeng.mk	2013-03-21 13:26:15.000000000 -0400
@@ -28,7 +28,6 @@
 # add any runtime tests (unit tests) here
 # remove if no tests
 $(eval $(call gb_Module_add_check_targets,editeng,\
-    CppunitTest_editeng_core \
     CppunitTest_editeng_borderline \
     CppunitTest_editeng_lookuptree \
 ))
