--- src/value.c.orig	2011-04-02 22:38:44.000000000 +0800
+++ src/value.c	2011-04-02 22:39:37.000000000 +0800
@@ -401,20 +401,20 @@ size_t json_array_size(const json_t *jso
     return json_to_array(json)->entries;
 }
 
-json_t *json_array_get(const json_t *json, size_t index)
+json_t *json_array_get(const json_t *json, size_t my_index)
 {
     json_array_t *array;
     if(!json_is_array(json))
         return NULL;
     array = json_to_array(json);
 
-    if(index >= array->entries)
+    if(my_index >= array->entries)
         return NULL;
 
-    return array->table[index];
+    return array->table[my_index];
 }
 
-int json_array_set_new(json_t *json, size_t index, json_t *value)
+int json_array_set_new(json_t *json, size_t my_index, json_t *value)
 {
     json_array_t *array;
 
@@ -428,14 +428,14 @@ int json_array_set_new(json_t *json, siz
     }
     array = json_to_array(json);
 
-    if(index >= array->entries)
+    if(my_index >= array->entries)
     {
         json_decref(value);
         return -1;
     }
 
-    json_decref(array->table[index]);
-    array->table[index] = value;
+    json_decref(array->table[my_index]);
+    array->table[my_index] = value;
 
     return 0;
 }
@@ -507,7 +507,7 @@ int json_array_append_new(json_t *json, 
     return 0;
 }
 
-int json_array_insert_new(json_t *json, size_t index, json_t *value)
+int json_array_insert_new(json_t *json, size_t my_index, json_t *value)
 {
     json_array_t *array;
     json_t **old_table;
@@ -521,7 +521,7 @@ int json_array_insert_new(json_t *json, 
     }
     array = json_to_array(json);
 
-    if(index > array->entries) {
+    if(my_index > array->entries) {
         json_decref(value);
         return -1;
     }
@@ -533,21 +533,21 @@ int json_array_insert_new(json_t *json, 
     }
 
     if(old_table != array->table) {
-        array_copy(array->table, 0, old_table, 0, index);
-        array_copy(array->table, index + 1, old_table, index,
-                   array->entries - index);
+        array_copy(array->table, 0, old_table, 0, my_index);
+        array_copy(array->table, my_index + 1, old_table, my_index,
+                   array->entries - my_index);
         jsonp_free(old_table);
     }
     else
-        array_move(array, index + 1, index, array->entries - index);
+        array_move(array, my_index + 1, my_index, array->entries - my_index);
 
-    array->table[index] = value;
+    array->table[my_index] = value;
     array->entries++;
 
     return 0;
 }
 
-int json_array_remove(json_t *json, size_t index)
+int json_array_remove(json_t *json, size_t my_index)
 {
     json_array_t *array;
 
@@ -555,12 +555,12 @@ int json_array_remove(json_t *json, size
         return -1;
     array = json_to_array(json);
 
-    if(index >= array->entries)
+    if(my_index >= array->entries)
         return -1;
 
-    json_decref(array->table[index]);
+    json_decref(array->table[my_index]);
 
-    array_move(array, index, index + 1, array->entries - index);
+    array_move(array, my_index, my_index + 1, array->entries - my_index);
     array->entries--;
 
     return 0;
