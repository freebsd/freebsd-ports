--- src/file.c.orig	2000-10-13 08:45:02.000000000 +0200
+++ src/file.c	2007-11-04 00:56:29.000000000 +0100
@@ -46,7 +46,7 @@
 static void cancel_cb(GtkWidget *widget, gpointer *data);
 
 gint fs_code;
-static GtkWidget *file_sel;
+GtkWidget *file_sel;
 
 /*
  *
@@ -80,7 +80,7 @@
 	gtk_widget_destroy(GTK_WIDGET(file_sel));
 	file_sel = NULL;
 
-    if(file_name) {
+    if(file_name[0]) {
         dedit_new_document(NULL, file_name);
     }
 
@@ -318,7 +318,7 @@
 	gtk_widget_destroy(GTK_WIDGET(file_sel));
 	file_sel = NULL;
 
-    if(tmp){
+    if(tmp[0]){
         save_file(doc, tmp);
     }
 
@@ -330,7 +330,6 @@
 {
     gchar *tmp;
     gint i;
-    struct stat status;
     gzFile *gzfp = NULL;
     gboolean gzMode = FALSE; 
     FILE *fp = NULL;
@@ -340,7 +339,7 @@
     gchar backup[PATH_MAX];
     gboolean bkFlag = FALSE;
     
-    struct stat st0, st1;
+    struct stat st0;
 
 #ifdef TRACE_FUNC
     printf("save_file()\n");
