
$FreeBSD$

--- extensions/gtk_system_framework/gtk_system_framework.cc.orig
+++ extensions/gtk_system_framework/gtk_system_framework.cc
@@ -99,7 +99,7 @@
         GTK_FILE_CHOOSER_ACTION_OPEN,
         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
         GTK_STOCK_OK, GTK_RESPONSE_OK,
-        NULL);
+        (gint*)0);
 
     gtk_file_chooser_set_select_multiple(GTK_FILE_CHOOSER(dialog), multiple);
     if (filter && *filter) {
