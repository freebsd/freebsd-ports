--- src/vte.c.orig	2019-09-28 12:38:17 UTC
+++ src/vte.c
@@ -399,6 +399,7 @@ void vte_close(void)
 	g_free(vf);
 	/* free the vte widget before unloading vte module
 	 * this prevents a segfault on X close window if the message window is hidden */
+	g_signal_handlers_disconnect_by_func(vc->vte, G_CALLBACK(vte_start), NULL);
 	gtk_widget_destroy(vc->vte);
 	gtk_widget_destroy(vc->menu);
 	g_object_unref(vc->menu);
