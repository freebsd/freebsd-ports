--- src/marlin-cdda-record.c.orig	Mon Nov 17 12:45:49 2003
+++ src/marlin-cdda-record.c	Mon Nov 17 12:46:17 2003
@@ -506,7 +506,7 @@
 		if (res) {
 			if (i > 0) {
 				char *start_str, *finish_str, *length_str;
-				gint64 length = time - time_count;;
+				gint64 length = time - time_count;
 				char *full;
 				
 				cdda->track_starts[i] = time;
