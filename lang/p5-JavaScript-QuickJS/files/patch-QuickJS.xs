Obtained from:	https://github.com/FGasper/p5-JavaScript-QuickJS/issues/13
		https://github.com/FGasper/p5-JavaScript-QuickJS/tree/quickjs_2025_04
Reference:	https://github.com/bellard/quickjs/commit/f10ef299a6ab4c36c4162cc5840f128f74ec197c

--- QuickJS.xs.orig	2024-02-12 14:21:20 UTC
+++ QuickJS.xs
@@ -44,9 +44,8 @@ const char* __jstype_name_back[] = {
 } ctx_opaque_s;
 
 const char* __jstype_name_back[] = {
-    [JS_TAG_BIG_DECIMAL - JS_TAG_FIRST] = "big decimal",
+    [JS_TAG_SHORT_BIG_INT - JS_TAG_FIRST] = "short big integer",
     [JS_TAG_BIG_INT - JS_TAG_FIRST] = "big integer",
-    [JS_TAG_BIG_FLOAT - JS_TAG_FIRST] = "big float",
     [JS_TAG_SYMBOL - JS_TAG_FIRST] = "symbol",
     [JS_TAG_MODULE - JS_TAG_FIRST] = "module",
     [JS_TAG_OBJECT - JS_TAG_FIRST] = "object",
@@ -649,7 +648,7 @@ static JSModuleDef *pqjs_module_loader(JSContext *ctx,
 }
 
 static JSModuleDef *pqjs_module_loader(JSContext *ctx,
-                              const char *module_name, void *opaque) {
+                              const char *module_name, void *opaque, JSValueConst attributes) {
     char** module_base_path_p = (char**) opaque;
 
     char* module_base_path = *module_base_path_p;
@@ -666,10 +665,10 @@ static JSModuleDef *pqjs_module_loader(JSContext *ctx,
         memcpy(real_path + base_path_len, module_name, module_name_len);
         real_path[base_path_len + module_name_len] = 0;
 
-        moduledef = js_module_loader(ctx, real_path, NULL);
+        moduledef = js_module_loader(ctx, real_path, NULL, attributes);
     }
     else {
-        moduledef = js_module_loader(ctx, module_name, NULL);
+        moduledef = js_module_loader(ctx, module_name, NULL, attributes);
     }
 
     return moduledef;
@@ -751,7 +750,7 @@ _new (SV* classname_sv)
     CODE:
         JSRuntime *rt = JS_NewRuntime();
         JS_SetHostPromiseRejectionTracker(rt, js_std_promise_rejection_tracker, NULL);
-        JS_SetModuleLoaderFunc(rt, NULL, js_module_loader, NULL);
+        JS_SetModuleLoaderFunc2(rt, NULL, js_module_loader, js_module_check_attributes, NULL);
 
         JSContext *ctx = _create_new_jsctx(aTHX_ rt);
 
@@ -763,10 +762,11 @@ _new (SV* classname_sv)
             .pid = getpid(),
         };
 
-        JS_SetModuleLoaderFunc(
+        JS_SetModuleLoaderFunc2(
             rt,
             NULL,
             pqjs_module_loader,
+            js_module_check_attributes,
             &pqjs->module_base_path
         );
 
