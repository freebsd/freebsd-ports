--- src/planner-html-plugin.c.orig	Fri Jan 12 23:10:39 2007
+++ src/planner-html-plugin.c	Fri Jan 12 23:11:32 2007
@@ -198,7 +198,6 @@
 
 		break;
 	case GTK_RESPONSE_CANCEL:
-		g_free (filename);
 		gtk_widget_destroy (filechooser);
 		break;
 	}
