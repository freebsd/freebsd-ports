--- src/jansson.h.orig	2018-11-26 08:10:21 UTC
+++ src/jansson.h
@@ -219,10 +219,10 @@ int json_object_iter_set_new(json_t *object, void *ite
         key = json_object_iter_key(n), \
             n = json_object_iter_next(object, json_object_key_to_iter(key)))
 
-#define json_array_foreach(array, index, value) \
-	for(index = 0; \
-		index < json_array_size(array) && (value = json_array_get(array, index)); \
-		index++)
+#define json_array_foreach(array, idx, value) \
+	for(idx = 0; \
+		idx < json_array_size(array) && (value = json_array_get(array, idx)); \
+		idx++)
 
 static JSON_INLINE
 int json_object_set(json_t *object, const char *key, json_t *value)
@@ -243,11 +243,11 @@ int json_object_iter_set(json_t *object, void *iter, j
 }
 
 size_t json_array_size(const json_t *array);
-json_t *json_array_get(const json_t *array, size_t index) JANSSON_ATTRS(warn_unused_result);
-int json_array_set_new(json_t *array, size_t index, json_t *value);
+json_t *json_array_get(const json_t *array, size_t idx) JANSSON_ATTRS(warn_unused_result);
+int json_array_set_new(json_t *array, size_t idx, json_t *value);
 int json_array_append_new(json_t *array, json_t *value);
-int json_array_insert_new(json_t *array, size_t index, json_t *value);
-int json_array_remove(json_t *array, size_t index);
+int json_array_insert_new(json_t *array, size_t idx, json_t *value);
+int json_array_remove(json_t *array, size_t idx);
 int json_array_clear(json_t *array);
 int json_array_extend(json_t *array, json_t *other);
 
