--- widgets/eggtrayicon.c.orig	Wed Jun 14 12:25:10 2006
+++ widgets/eggtrayicon.c	Wed Jun 14 12:26:41 2006
@@ -571,7 +571,7 @@
 
   if (pixbuf)
     {
-#if (LIBNOTIFY_VERSION_MICRO < 2)
+#if ((LIBNOTIFY_VERSION_MINOR <= 3) && (LIBNOTIFY_VERSION_MICRO < 2))
       notify_notification_set_icon_data_from_pixbuf (icon->notify->handle, pixbuf);
 #else
       notify_notification_set_icon_from_pixbuf (icon->notify->handle, pixbuf);
