--- src/gui/filedialogs.cc.orig	Mon Aug 20 13:14:42 2001
+++ src/gui/filedialogs.cc	Mon Aug 20 13:14:52 2001
@@ -159,7 +159,7 @@
   if (select_function == help_ok_sel || select_function == help_open_sel) {
     if (!help_browser)
       gtk_file_selection_set_filename (GTK_FILE_SELECTION(filew),
-				       "/usr/bin/");
+				       "~/");
     else
       gtk_file_selection_set_filename (GTK_FILE_SELECTION(filew),
 				       help_browser);
