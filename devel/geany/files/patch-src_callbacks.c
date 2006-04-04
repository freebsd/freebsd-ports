--- src/callbacks.c.orig	Tue Apr  4 14:17:38 2006
+++ src/callbacks.c	Tue Apr  4 14:20:19 2006
@@ -151,7 +151,8 @@
 		gtk_widget_destroy(app->default_tag_tree);
 	}
 	gtk_widget_destroy(app->window);
-	if (app->have_vte) vte_close();
+	// this causes a crash, for some reason
+	// if (app->have_vte) vte_close();
 
 	g_free(app);
 
