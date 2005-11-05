--- subversion/bindings/swig/proxy/swig_perl_external_runtime.swg.orig	Sat Nov  5 16:48:10 2005
+++ subversion/bindings/swig/proxy/swig_perl_external_runtime.swg	Sat Nov  5 16:49:08 2005
@@ -945,13 +945,13 @@
 
 SWIGRUNTIMEINLINE swig_type_info *
 SWIG_TypeQuery(const char *name) {
-  swig_module_info *module = SWIG_GetModule();
+  swig_module_info *module = SWIG_GetModule(NULL);
   return SWIG_TypeQueryModule(module, module, name);
 }
 
 SWIGRUNTIMEINLINE swig_type_info *
 SWIG_MangledTypeQuery(const char *name) {
-  swig_module_info *module = SWIG_GetModule();
+  swig_module_info *module = SWIG_GetModule(NULL);
   return SWIG_MangledTypeQueryModule(module, module, name);
 }
 
