--- Lib/runtime.swg.orig	Fri Jul 29 14:23:14 2005
+++ Lib/runtime.swg	Fri Jul 29 14:23:58 2005
@@ -25,13 +25,13 @@
 
 SWIGRUNTIMEINLINE swig_type_info *
 SWIG_TypeQuery(const char *name) {
-  swig_module_info *module = SWIG_GetModule();
+  swig_module_info *module = SWIG_GetModule(clientdata);
   return SWIG_TypeQueryModule(module, module, name);
 }
 
 SWIGRUNTIMEINLINE swig_type_info *
 SWIG_MangledTypeQuery(const char *name) {
-  swig_module_info *module = SWIG_GetModule();
+  swig_module_info *module = SWIG_GetModule(clientdata);
   return SWIG_MangledTypeQueryModule(module, module, name);
 }
 
