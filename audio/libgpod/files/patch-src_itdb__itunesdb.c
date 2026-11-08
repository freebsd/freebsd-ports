--- src/itdb_itunesdb.c.orig	2013-07-09 15:34:38 UTC
+++ src/itdb_itunesdb.c
@@ -1156,6 +1156,7 @@ static gboolean playcounts_plist_read (FImport *fimp, 
     GHashTable *pc_dict, *track_dict;
     GValue *to_parse;
     GArray *array;
+    GValue value;
     gint i;
     guint32 mac_time;
     guint64 *dbid;
@@ -1175,11 +1176,12 @@ static gboolean playcounts_plist_read (FImport *fimp, 
 
     array = (GArray*)g_value_get_boxed (to_parse);
     for (i = 0; i < array->len; i++) {
-       if (!G_VALUE_HOLDS (g_array_index (array, GValue *, i), G_TYPE_HASH_TABLE)) {
+       value = g_array_index (array, GValue, i);
+       if (!G_VALUE_HOLDS (&value, G_TYPE_HASH_TABLE)) {
           continue;
        }
 
-       track_dict = g_value_get_boxed (g_array_index (array, GValue *, i));
+       track_dict = g_value_get_boxed (&value);
        if (track_dict == NULL)
            continue;
 
