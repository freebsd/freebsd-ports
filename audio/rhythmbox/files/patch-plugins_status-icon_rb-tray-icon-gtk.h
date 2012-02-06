--- plugins/status-icon/rb-tray-icon-gtk.h.orig	2012-02-05 23:22:03.000000000 -0500
+++ plugins/status-icon/rb-tray-icon-gtk.h	2012-02-05 23:22:11.000000000 -0500
@@ -74,10 +74,6 @@ gboolean		rb_tray_icon_is_embedded (RBTr
 
 void			rb_tray_icon_menu_popup (RBTrayIcon *icon, GtkWidget *popup, gint button);
 
-#if defined(HAVE_NOTIFY)
-void			rb_tray_icon_attach_notification (RBTrayIcon *icon, NotifyNotification *notification);
-#endif
-
 void			rb_tray_icon_set_visible (RBTrayIcon *icon, gboolean visible);
 
 G_END_DECLS
