--- src/window.c.orig	Sat Sep 10 11:30:49 2005
+++ src/window.c	Sat Oct  8 12:33:20 2005
@@ -160,7 +160,7 @@
        strlen(save_file->str) > 0)
 	gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(window.file_chooser),
 				      save_file->str);
-    else if(strlen(current_user.mmatches_file->str) > 0)
+    else if(users->len > 0 && strlen(current_user.mmatches_file->str) > 0)
 	gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(window.file_chooser),
 				      current_user.mmatches_file->str);
     else
