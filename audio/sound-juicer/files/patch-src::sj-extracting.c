--- src/sj-extracting.c.orig	Tue Jan 13 20:19:03 2004
+++ src/sj-extracting.c	Sat Feb  7 19:12:38 2004
@@ -226,7 +226,13 @@
 pop_and_extract (void)
 {
   if (pending == NULL) {
-    g_assert_not_reached ();
+    gtk_widget_hide (progress_dialog);
+    show_finished_dialog ();
+    cleanup ();
+    extracting = FALSE;
+    if (autostart) {
+      gtk_main_quit ();
+    }
   } else {
     char *file_path, *directory;
     GError *error = NULL;
