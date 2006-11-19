--- rhythmdb/rhythmdb.c.orig	Sun Nov 19 12:40:07 2006
+++ rhythmdb/rhythmdb.c	Sun Nov 19 12:40:26 2006
@@ -2817,7 +2817,7 @@ rhythmdb_entry_sync_mirrored (RhythmDBEn
 		if (entry->last_played == 0) {
 			new = rb_refstring_new (never);
 		} else {
-			val = eel_strdup_strftime (format, localtime ((glong*)&entry->last_played));
+			val = eel_strdup_strftime (format, localtime ((time_t*)&entry->last_played));
 			new = rb_refstring_new (val);
 			g_free (val);
 		}
@@ -2840,7 +2840,7 @@ rhythmdb_entry_sync_mirrored (RhythmDBEn
 			break;
 
 		old = g_atomic_pointer_get (&entry->first_seen_str);
-		val = eel_strdup_strftime (format, localtime ((glong*)&entry->first_seen));
+		val = eel_strdup_strftime (format, localtime ((time_t*)&entry->first_seen));
 		new = rb_refstring_new (val);
 		g_free (val);
 
@@ -2864,7 +2864,7 @@ rhythmdb_entry_sync_mirrored (RhythmDBEn
 		old = g_atomic_pointer_get (&entry->last_seen_str);
 		/* only store last seen time as a string for hidden entries */
 		if (entry->flags & RHYTHMDB_ENTRY_HIDDEN) {
-			val = eel_strdup_strftime (format, localtime ((glong*)&entry->last_seen));
+			val = eel_strdup_strftime (format, localtime ((time_t*)&entry->last_seen));
 			new = rb_refstring_new (val);
 			g_free (val);
 		} else {
