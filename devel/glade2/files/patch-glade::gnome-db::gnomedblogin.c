--- glade/gnome-db/gnomedblogin.c.orig	Sat Aug  5 06:37:50 2000
+++ glade/gnome-db/gnomedblogin.c	Tue Jun 19 06:06:48 2001
@@ -48,3 +48,3 @@
 {
-  return gnome_db_login_new (NULL, NULL, NULL);
+  return gnome_db_login_new (NULL);
 }
@@ -119,3 +119,3 @@
     {
-      source_add (data, "  %s = gnome_db_login_new (NULL, NULL, NULL);\n",
+      source_add (data, "  %s = gnome_db_login_new (NULL);\n",
 		  data->wname);
