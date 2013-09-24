--- src/value.c.orig	2013-09-25 06:13:36.000000000 +0800
+++ src/value.c	2013-09-25 06:15:37.000000000 +0800
@@ -360,20 +360,20 @@ size_t json_array_size(const json_t *jso
     return json_to_array(json)->entries;
 }
 
-json_t *json_array_get(const json_t *json, size_t index)
+json_t *json_array_get(const json_t *json, size_t ind)
 {
     json_array_t *array;
     if(!json_is_array(json))
         return NULL;
     array = json_to_array(json);
 
-    if(index >= array->entries)
+    if(ind >= array->entries)
         return NULL;
 
-    return array->table[index];
+    return array->table[ind];
 }
 
-int json_array_set_new(json_t *json, size_t index, json_t *value)
+int json_array_set_new(json_t *json, size_t ind, json_t *value)
 {
     json_array_t *array;
 
@@ -387,14 +387,14 @@ int json_array_set_new(json_t *json, siz
     }
     array = json_to_array(json);
 
-    if(index >= array->entries)
+    if(ind >= array->entries)
     {
         json_decref(value);
         return -1;
     }
 
-    json_decref(array->table[index]);
-    array->table[index] = value;
+    json_decref(array->table[ind]);
+    array->table[ind] = value;
 
     return 0;
 }
@@ -466,7 +466,7 @@ int json_array_append_new(json_t *json, 
     return 0;
 }
 
-int json_array_insert_new(json_t *json, size_t index, json_t *value)
+int json_array_insert_new(json_t *json, size_t ind, json_t *value)
 {
     json_array_t *array;
     json_t **old_table;
@@ -480,7 +480,7 @@ int json_array_insert_new(json_t *json, 
     }
     array = json_to_array(json);
 
-    if(index > array->entries) {
+    if(ind > array->entries) {
         json_decref(value);
         return -1;
     }
@@ -492,21 +492,21 @@ int json_array_insert_new(json_t *json, 
     }
 
     if(old_table != array->table) {
-        array_copy(array->table, 0, old_table, 0, index);
-        array_copy(array->table, index + 1, old_table, index,
-                   array->entries - index);
+        array_copy(array->table, 0, old_table, 0, ind);
+        array_copy(array->table, ind + 1, old_table, ind,
+                   array->entries - ind);
         jsonp_free(old_table);
     }
     else
-        array_move(array, index + 1, index, array->entries - index);
+        array_move(array, ind + 1, ind, array->entries - ind);
 
-    array->table[index] = value;
+    array->table[ind] = value;
     array->entries++;
 
     return 0;
 }
 
-int json_array_remove(json_t *json, size_t index)
+int json_array_remove(json_t *json, size_t ind)
 {
     json_array_t *array;
 
@@ -514,14 +514,14 @@ int json_array_remove(json_t *json, size
         return -1;
     array = json_to_array(json);
 
-    if(index >= array->entries)
+    if(ind >= array->entries)
         return -1;
 
-    json_decref(array->table[index]);
+    json_decref(array->table[ind]);
 
     /* If we're removing the last element, nothing has to be moved */
-    if(index < array->entries - 1)
-        array_move(array, index, index + 1, array->entries - index - 1);
+    if(ind < array->entries - 1)
+        array_move(array, ind, ind + 1, array->entries - ind - 1);
 
     array->entries--;
 
