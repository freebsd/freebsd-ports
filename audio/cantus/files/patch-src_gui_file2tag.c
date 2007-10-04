--- src/gui_file2tag.c.orig	2002-09-27 13:46:03.000000000 -0800
+++ src/gui_file2tag.c	2007-10-03 14:22:04.000000000 -0800
@@ -40,7 +40,7 @@
 
 
 void
-file2tag_form_fill(gchar *values[][2])
+file2tag_form_fill(gchar ***values)
 {
 	extern GtkWidget *cantus;
 	gchar foo[2048];
