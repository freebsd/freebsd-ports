
$FreeBSD$

--- glade/glade-gnomedb.c.orig	Tue Feb 13 03:37:54 2001
+++ glade/glade-gnomedb.c	Mon Aug  6 12:02:09 2001
@@ -44,7 +44,7 @@
 {
 	GtkWidget *wid;
      
-	wid = gnome_db_login_new (NULL, NULL, NULL);
+	wid = gnome_db_login_new (NULL);
      
 	return wid;
 }
@@ -55,7 +55,7 @@
 	GtkWidget *wid = NULL;
 	GtkWidget *wid2 = NULL;
      
-	wid2 = gnome_db_login_new (NULL,NULL,NULL);
+	wid2 = gnome_db_login_new (NULL);
           
 	wid = gnome_db_logindlg_new (GNOME_DB_LOGIN (wid2), NULL);
      
@@ -150,7 +150,7 @@
 {
 	GtkWidget *wid;
        
-	wid = gnome_db_error_new (NULL);
+	wid = gnome_db_error_new ();
      
 	return (wid);
 }
