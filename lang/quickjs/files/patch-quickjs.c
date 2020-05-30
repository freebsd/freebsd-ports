--- quickjs.c.orig	2020-04-12 13:18:13 UTC
+++ quickjs.c
@@ -1694,7 +1694,7 @@ static const JSMallocFunctions def_malloc_funcs = {
     (size_t (*)(const void *))malloc_usable_size,
 #else
     /* change this to `NULL,` if compilation fails */
-    malloc_usable_size,
+    NULL, //malloc_usable_size,
 #endif
 };
 
