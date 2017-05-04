--- filter/Module_filter.mk.orig	2017-04-25 20:44:01 UTC
+++ filter/Module_filter.mk
@@ -58,7 +58,8 @@ $(eval $(call gb_Module_add_targets,filter,\
 endif
 
 $(eval $(call gb_Module_add_check_targets,filter,\
-    CppunitTest_filter_xslt \
+    $(if $(filter FREEBSD,$(OS)),, \
+        CppunitTest_filter_xslt) \
     CppunitTest_filter_priority \
     CppunitTest_filter_msfilter \
 ))
