--- src/file.c.orig	Tue Oct 18 22:28:39 2005
+++ src/file.c	Tue Oct 18 22:29:14 2005
@@ -929,6 +929,7 @@
 void update_tracks (GList *selected_tracks)
 {
     GList *gl;
+    gchar *buf;
 
     if (selected_tracks == NULL)
     {
@@ -941,7 +942,7 @@
     {
 	Track *track = gl->data;
 	g_return_if_fail (track);
-	gchar *buf = g_strdup_printf (_("Updating %s"),
+	buf = g_strdup_printf (_("Updating %s"),
 				      get_track_info (track, TRUE));
 	gtkpod_statusbar_message (buf);
 	g_free (buf);
