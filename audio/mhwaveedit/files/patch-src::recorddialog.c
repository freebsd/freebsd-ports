--- src/recorddialog.c.orig	Sat Apr 17 12:41:52 2004
+++ src/recorddialog.c	Mon Apr 19 19:27:35 2004
@@ -590,8 +590,7 @@
 void record_dialog_init(RecordDialog *obj)
 {
      GtkWidget *a,*b,*c,*d,*e;
-GtkAccelGroup* ag;
-ag = gtk_accel_group_new();
+     GtkAccelGroup* ag = gtk_accel_group_new();
      GList *l2 = NULL;
      RecordFormat *rf;
      guint i;
