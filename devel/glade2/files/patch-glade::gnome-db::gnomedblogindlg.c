--- glade/gnome-db/gnomedblogindlg.c.orig	Sat Aug  5 06:37:50 2000
+++ glade/gnome-db/gnomedblogindlg.c	Tue Jun 19 06:08:28 2001
@@ -62,3 +62,3 @@
 
-  login = gnome_db_login_new (NULL, NULL, NULL);
+  login = gnome_db_login_new (NULL);
 
@@ -159,3 +159,3 @@
       title = GTK_WINDOW (widget)->title;
-      source_add (data, "  %s = gnome_db_logindlg_new (GNOME_DB_LOGIN (gnome_db_login_new (NULL, NULL, NULL)), %s);\n",
+      source_add (data, "  %s = gnome_db_logindlg_new (GNOME_DB_LOGIN (gnome_db_login_new (NULL)), %s);\n",
 		  data->wname,
