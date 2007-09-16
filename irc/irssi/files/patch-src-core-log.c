Index: src/core/log.c
===================================================================
--- src/core/log.c	(revision 4490)
+++ src/core/log.c	(revision 4491)
@@ -299,9 +299,7 @@
 		if ((level & rec->level) == 0)
 			continue;
 
-		if (item == NULL) {
-			if (rec->temp == 0) log_write_rec(rec, str, level);
-		} else if (rec->items == NULL)
+		if (rec->items == NULL)
 			fallbacks = g_slist_append(fallbacks, rec);
 		else if (log_item_find(rec, LOG_ITEM_TARGET, item,
 				       server_tag) != NULL)
