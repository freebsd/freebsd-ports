--- src/interface_cb.c.orig	Mon Aug  2 13:38:56 2004
+++ src/interface_cb.c	Mon Aug  2 13:39:10 2004
@@ -2209,6 +2209,6 @@
 		gnome_db_error_dialog_show_errors (GNOME_DB_ERROR_DIALOG (conf->error_dlg),
 						   gda_connection_get_errors (cnc));
 		break;
-	default :
+	default :;
 	}
 }
