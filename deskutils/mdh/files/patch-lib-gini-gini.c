--- lib/gini/gini.c.orig	2005-07-07 23:10:18 UTC
+++ lib/gini/gini.c
@@ -190,7 +190,7 @@ static void value_transform_string_ulong
 
 static void value_transform_string_int64(const GValue *src, GValue *dst)
 {
-    dst->data[0].v_int64 = atoll(src->data[0].v_pointer);
+    dst->data[0].v_int64 = strtoll(src->data[0].v_pointer, NULL, 10);
 }
 
 static void value_transform_string_uint64(const GValue *src, GValue *dst)
