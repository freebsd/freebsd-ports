--- libgnomedb/utils.c.orig	Mon Aug  2 10:12:06 2004
+++ libgnomedb/utils.c	Mon Aug  2 10:12:16 2004
@@ -45,7 +45,7 @@
 		dialog = gnome_db_error_dialog_new (_("Error"));
 		gnome_db_error_dialog_show_errors (GNOME_DB_ERROR_DIALOG (dialog),
 						   gda_connection_get_errors (cnc));
-	default :
+	default :;
 	}
 }
 
