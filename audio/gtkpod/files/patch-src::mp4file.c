--- src/mp4file.c.old	Sat Jan 17 10:37:49 2004
+++ src/mp4file.c	Tue Jan 20 21:33:20 2004
@@ -342,7 +342,7 @@
     return NULL;
 }
 
-gboolean file_write_mp4_info (gchar *filename, Track *track, T_item tag_id)
+gboolean file_write_mp4_info (gchar *filename, Track *track)
 {
     gtkpod_warning (_("m4a/m4p metadata update for '%s' failed: m4a/m4p not supported without the mp4v2 library. You must compile the gtkpod source together with the mp4v2 library.\n"), filename);
     return FALSE;
