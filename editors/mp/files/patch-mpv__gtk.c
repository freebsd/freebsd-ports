Fix build with GTK 2.x
mpv_gtk.c:2386:5: error: use of undeclared identifier 'GdkMonitor'
    GdkMonitor *monitor;

--- mpv_gtk.c.orig	2019-10-24 17:18:37 UTC
+++ mpv_gtk.c
@@ -2378,13 +2378,14 @@ static mpdm_t gtk_drv_startup(mpdm_t a, mpdm_t ctxt)
 #if CONFOPT_GTK == 2
     GdkPixmap *pixmap;
     GdkPixmap *mask;
+    GdkScreen *screen;
 #endif
 #if CONFOPT_GTK == 3
     GdkPixbuf *pixmap;
-#endif
     GdkDisplay *display;
     GdkMonitor *monitor;
     GdkRectangle monitor_one_size;
+#endif
     mpdm_t v;
     int w, h;
     GtkTargetEntry targets[] = {
@@ -2399,6 +2400,21 @@ static mpdm_t gtk_drv_startup(mpdm_t a, mpdm_t ctxt)
     gtk_window_set_title(GTK_WINDOW(window), "mp " VERSION);
 
     /* get real screen and pick a usable size for the main area */
+#if CONFOPT_GTK == 2
+    screen = gtk_window_get_screen(GTK_WINDOW(window));
+    if (gdk_screen_get_n_monitors(screen) > 1) {
+        GdkRectangle monitor_one_size;
+        gdk_screen_get_monitor_geometry(screen, 0, &monitor_one_size);
+
+        w = (monitor_one_size.width * 3) / 4;
+        h = (monitor_one_size.height * 2) / 3;
+    }
+    else {
+        w = (gdk_screen_get_width(screen) * 3) / 4;
+        h = (gdk_screen_get_height(screen) * 2) / 3;
+    }
+#endif
+#if CONFOPT_GTK == 3
     display = gdk_display_get_default();
 
     monitor = gdk_display_get_monitor(display, 0);
@@ -2407,6 +2423,7 @@ static mpdm_t gtk_drv_startup(mpdm_t a, mpdm_t ctxt)
         
     w = (monitor_one_size.width * 3) / 4;
     h = (monitor_one_size.height * 2) / 3;
+#endif
 
     v = mpdm_get_wcs(MP, L"state");
     if ((v = mpdm_get_wcs(v, L"window")) == NULL) {
