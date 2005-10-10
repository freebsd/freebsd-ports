--- lib/gini/gini.c.orig	Fri Jul  8 08:10:18 2005
+++ lib/gini/gini.c	Fri Oct  7 03:35:03 2005
@@ -190,7 +190,7 @@
 
 static void value_transform_string_int64(const GValue *src, GValue *dst)
 {
-    dst->data[0].v_int64 = atoll(src->data[0].v_pointer);
+    dst->data[0].v_int64 = strtoll(src->data[0].v_pointer, NULL, 10);
 }
 
 static void value_transform_string_uint64(const GValue *src, GValue *dst)
