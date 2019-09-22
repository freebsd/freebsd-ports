--- quickjs.c.orig	2019-09-18 18:34:20 UTC
+++ quickjs.c
@@ -1423,7 +1423,7 @@ static const JSMallocFunctions def_malloc_funcs = {
     (size_t (*)(const void *))malloc_usable_size,
 #else
     /* change this to `NULL,` if compilation fails */
-    malloc_usable_size,
+    NULL, //malloc_usable_size,
 #endif
 };
 
