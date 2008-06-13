
$FreeBSD$

--- ggadget/module.cc.orig
+++ ggadget/module.cc
@@ -34,6 +34,12 @@
 // #define DEBUG_MODULES
 #endif
 
+#if __GNUC__ < 4
+#define CAST_HACK(x) (x)
+#else
+#define CAST_HACK(x) reinterpret_cast<x>
+#endif
+
 namespace ggadget {
 
 static const char *kModulePathEnv = "GGL_MODULE_PATH";
@@ -117,10 +123,10 @@
 
     NormalizeNameString(&module_name);
 
-    InitializeFunction new_initialize = reinterpret_cast<InitializeFunction>(
+    InitializeFunction new_initialize = CAST_HACK(InitializeFunction)(
         GetModuleSymbol(new_handle, module_name.c_str(),
                         kModuleInitializeSymbol));
-    FinalizeFunction new_finalize = reinterpret_cast<FinalizeFunction>(
+    FinalizeFunction new_finalize = CAST_HACK(FinalizeFunction)(
         GetModuleSymbol(new_handle, module_name.c_str(),
                         kModuleFinalizeSymbol));
 
