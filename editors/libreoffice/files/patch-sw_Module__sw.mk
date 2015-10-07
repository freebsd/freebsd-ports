--- sw/Module_sw.mk.orig	2015-08-22 06:41:35 UTC
+++ sw/Module_sw.mk
@@ -62,7 +62,8 @@ $(eval $(call gb_Module_add_slowcheck_ta
     CppunitTest_sw_ooxmlw14export \
     CppunitTest_sw_ooxmlimport \
     CppunitTest_sw_ww8export \
-    CppunitTest_sw_ww8import \
+    $(if $(filter FREEBSD,$(OS)),, \
+        CppunitTest_sw_ww8import) \
     CppunitTest_sw_rtfexport \
     CppunitTest_sw_rtfimport \
     CppunitTest_sw_odfexport \
