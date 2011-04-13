--- src/jansson.h.orig	2011-04-02 22:38:00.000000000 +0800
+++ src/jansson.h	2011-04-02 22:38:38.000000000 +0800
@@ -152,18 +152,18 @@ int json_object_iter_set(json_t *object,
 }
 
 size_t json_array_size(const json_t *array);
-json_t *json_array_get(const json_t *array, size_t index);
-int json_array_set_new(json_t *array, size_t index, json_t *value);
+json_t *json_array_get(const json_t *array, size_t my_index);
+int json_array_set_new(json_t *array, size_t my_index, json_t *value);
 int json_array_append_new(json_t *array, json_t *value);
-int json_array_insert_new(json_t *array, size_t index, json_t *value);
-int json_array_remove(json_t *array, size_t index);
+int json_array_insert_new(json_t *array, size_t my_index, json_t *value);
+int json_array_remove(json_t *array, size_t my_index);
 int json_array_clear(json_t *array);
 int json_array_extend(json_t *array, json_t *other);
 
 static JSON_INLINE
-int json_array_set(json_t *array, size_t index, json_t *value)
+int json_array_set(json_t *array, size_t my_index, json_t *value)
 {
-    return json_array_set_new(array, index, json_incref(value));
+    return json_array_set_new(array, my_index, json_incref(value));
 }
 
 static JSON_INLINE
@@ -173,9 +173,9 @@ int json_array_append(json_t *array, jso
 }
 
 static JSON_INLINE
-int json_array_insert(json_t *array, size_t index, json_t *value)
+int json_array_insert(json_t *array, size_t my_index, json_t *value)
 {
-    return json_array_insert_new(array, index, json_incref(value));
+    return json_array_insert_new(array, my_index, json_incref(value));
 }
 
 const char *json_string_value(const json_t *string);
