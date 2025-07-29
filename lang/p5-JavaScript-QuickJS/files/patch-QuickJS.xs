Obtained from:	https://github.com/FGasper/p5-JavaScript-QuickJS/issues/13
		https://github.com/FGasper/p5-JavaScript-QuickJS/tree/quickjs_2025_04

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
