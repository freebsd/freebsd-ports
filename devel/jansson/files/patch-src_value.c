--- src/value.c.orig	2016-08-25 17:21:36 UTC
+++ src/value.c
@@ -375,20 +375,20 @@ size_t json_array_size(const json_t *jso
     return json_to_array(json)->entries;
 }
 
-json_t *json_array_get(const json_t *json, size_t index)
+json_t *json_array_get(const json_t *json, size_t idx)
 {
     json_array_t *array;
     if(!json_is_array(json))
         return NULL;
     array = json_to_array(json);
 
-    if(index >= array->entries)
+    if(idx >= array->entries)
         return NULL;
 
-    return array->table[index];
+    return array->table[idx];
 }
 
-int json_array_set_new(json_t *json, size_t index, json_t *value)
+int json_array_set_new(json_t *json, size_t idx, json_t *value)
 {
     json_array_t *array;
 
@@ -402,14 +402,14 @@ int json_array_set_new(json_t *json, siz
     }
     array = json_to_array(json);
 
-    if(index >= array->entries)
+    if(idx >= array->entries)
     {
         json_decref(value);
         return -1;
     }
 
-    json_decref(array->table[index]);
-    array->table[index] = value;
+    json_decref(array->table[idx]);
+    array->table[idx] = value;
 
     return 0;
 }
@@ -481,7 +481,7 @@ int json_array_append_new(json_t *json, 
     return 0;
 }
 
-int json_array_insert_new(json_t *json, size_t index, json_t *value)
+int json_array_insert_new(json_t *json, size_t idx, json_t *value)
 {
     json_array_t *array;
     json_t **old_table;
@@ -495,7 +495,7 @@ int json_array_insert_new(json_t *json, 
     }
     array = json_to_array(json);
 
-    if(index > array->entries) {
+    if(idx > array->entries) {
         json_decref(value);
         return -1;
     }
@@ -507,21 +507,21 @@ int json_array_insert_new(json_t *json, 
     }
 
     if(old_table != array->table) {
-        array_copy(array->table, 0, old_table, 0, index);
-        array_copy(array->table, index + 1, old_table, index,
-                   array->entries - index);
+        array_copy(array->table, 0, old_table, 0, idx);
+        array_copy(array->table, idx + 1, old_table, idx,
+                   array->entries - idx);
         jsonp_free(old_table);
     }
     else
-        array_move(array, index + 1, index, array->entries - index);
+        array_move(array, idx + 1, idx, array->entries - idx);
 
-    array->table[index] = value;
+    array->table[idx] = value;
     array->entries++;
 
     return 0;
 }
 
-int json_array_remove(json_t *json, size_t index)
+int json_array_remove(json_t *json, size_t idx)
 {
     json_array_t *array;
 
@@ -529,14 +529,14 @@ int json_array_remove(json_t *json, size
         return -1;
     array = json_to_array(json);
 
-    if(index >= array->entries)
+    if(idx >= array->entries)
         return -1;
 
-    json_decref(array->table[index]);
+    json_decref(array->table[idx]);
 
     /* If we're removing the last element, nothing has to be moved */
-    if(index < array->entries - 1)
-        array_move(array, index, index + 1, array->entries - index - 1);
+    if(idx < array->entries - 1)
+        array_move(array, idx, idx + 1, array->entries - idx - 1);
 
     array->entries--;
 
