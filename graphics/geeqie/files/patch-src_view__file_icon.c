--- ./src/view_file_icon.c.orig	2016-05-28 21:43:05 UTC
+++ ./src/view_file_icon.c
@@ -379,6 +379,7 @@ static void vficon_mark_toggled_cb(GtkCe
 
 static void tip_show(ViewFile *vf)
 {
+	return; // or crash
 	GtkWidget *label;
 	gint x, y;
 
@@ -460,6 +461,7 @@ static void tip_unschedule(ViewFile *vf)
 
 static void tip_update(ViewFile *vf, IconData *id)
 {
+	return; // or crash
 	if (VFICON(vf)->tip_window)
 		{
 		gint x, y;
