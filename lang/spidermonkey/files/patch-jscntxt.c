--- jscntxt.c.orig	Sat Jan 14 01:57:13 2006
+++ jscntxt.c	Sat Jan 14 02:14:51 2006
@@ -334,7 +334,7 @@
 {
     const JSResolvingKey *key = (const JSResolvingKey *)ptr;
 
-    return ((JSDHashNumber)key->obj >> JSVAL_TAGBITS) ^ key->id;
+    return ((JSDHashNumber)JS_PTR_TO_UINT32(key->obj) >> JSVAL_TAGBITS) ^ key->id;
 }
 
 JS_PUBLIC_API(JSBool)
