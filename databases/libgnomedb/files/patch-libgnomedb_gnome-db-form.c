--- libgnomedb/gnome-db-form.c.orig	Mon Aug  2 10:13:56 2004
+++ libgnomedb/gnome-db-form.c	Mon Aug  2 10:14:09 2004
@@ -582,6 +582,6 @@
 		form->priv->navigator_current_row = row;
 		show_navigator_row (form);
 		break;
-	case GNOME_DB_FORM_TYPE_LIST :
+	case GNOME_DB_FORM_TYPE_LIST :;
 	}
 }
