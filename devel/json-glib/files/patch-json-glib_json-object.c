diff --git a/json-glib/json-gobject.c b/json-glib/json-gobject.c
index 15e9ed5..eeb571c 100644
--- json-glib/json-gobject.c
+++ json-glib/json-gobject.c
@@ -189,7 +189,7 @@ json_deserialize_pspec (GValue     *value,
         {
           JsonArray *array = json_node_get_array (node);
           guint i, array_len = json_array_get_length (array);
-          GPtrArray *str_array = g_ptr_array_sized_new (array_len);
+          GPtrArray *str_array = g_ptr_array_sized_new (array_len + 1);
 
           for (i = 0; i < array_len; i++)
             {
@@ -201,6 +201,7 @@ json_deserialize_pspec (GValue     *value,
               if (json_node_get_string (val) != NULL);
                 g_ptr_array_add (str_array, (gpointer) json_node_get_string (val));
             }
+          g_ptr_array_add (str_array, NULL);
 
           g_value_set_boxed (value, str_array->pdata);
 
