--- src/view.c.orig	2009-08-25 05:03:53.000000000 +0900
+++ src/view.c	2009-09-28 17:09:59.000000000 +0900
@@ -5198,7 +5198,7 @@
 #ifdef G_OS_WIN32
   data_dir = g_build_filename (get_data_dir (), "icons","denemo.png", NULL);
 #else
-  data_dir = g_strconcat (get_data_dir (), "/../icons/denemo.png", NULL);//FIXME installed in wrong place
+  data_dir = g_strconcat (get_data_dir (), "../pixmaps/denemo.png", NULL);
 #endif
   gtk_window_set_default_icon_from_file (data_dir, NULL);
   gtk_signal_connect (GTK_OBJECT (Denemo.window), "delete_event",
