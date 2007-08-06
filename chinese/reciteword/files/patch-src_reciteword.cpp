--- src/reciteword.cpp.orig	2006-03-26 16:32:27.000000000 +0800
+++ src/reciteword.cpp	2007-07-30 16:38:45.000000000 +0800
@@ -1375,7 +1375,11 @@
 	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
 //	gtk_widget_pop_visual ();
 //	gtk_widget_pop_colormap ();
+#ifdef G_OS_WIN32
+	gtk_widget_set_events(window,GDK_SCROLL_MASK | GDK_BUTTON_PRESS_MASK);
+#else
 	gtk_widget_set_events(window,GDK_SCROLL_MASK);
+#endif
 	gtk_window_set_decorated (GTK_WINDOW (window), FALSE);
 	gtk_widget_set_app_paintable(window,TRUE);
 	gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
