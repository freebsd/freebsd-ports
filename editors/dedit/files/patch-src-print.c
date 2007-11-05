--- src/print.c.orig	2007-11-04 00:37:11.000000000 +0100
+++ src/print.c	2007-11-04 00:38:50.000000000 +0100
@@ -46,7 +46,7 @@
 static GtkWidget *print_dialog = NULL;
 static GtkWidget *print_cmd_entry = NULL;
 
-static GtkWidget *file_sel;
+GtkWidget *file_sel;
 gchar *print_cmd;
 
 /* °õºþ
