--- src/w_dir.c.orig	2017-10-08 18:52:17 UTC
+++ src/w_dir.c
@@ -174,7 +174,7 @@ ShowHidden(Widget w, XtPointer client_data, XtPointer 
 
 /* if the export dir diverged from the file dir, leave it there */
 void
-update_file_export_dir(const char *restrict dir)
+update_file_export_dir(const char *dir)
 {
     if (!strcmp(cur_file_dir, cur_export_dir))
 	strcpy(cur_export_dir, dir);
