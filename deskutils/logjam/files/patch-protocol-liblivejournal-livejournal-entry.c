--- protocol/liblivejournal/livejournal/entry.c.orig	Thu Aug 17 01:40:10 2006
+++ protocol/liblivejournal/livejournal/entry.c	Thu Aug 17 01:45:24 2006
@@ -610,6 +610,12 @@
 	else if (g_ascii_strcasecmp(key, "time") == 0) {
 		if (entry) lj_ljdate_to_tm(val, &entry->time);
 	}
+	else if (g_ascii_strcasecmp(key, "backdated") == 0) {
+		if (entry && val[0]) {
+			if (g_ascii_strcasecmp(val, "yes") == 0)
+				entry->backdated = TRUE;
+		}
+	}
 	else return FALSE;
 
 	return TRUE;
