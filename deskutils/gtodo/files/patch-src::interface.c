--- src/interface.c.orig	Mon Sep 29 10:32:29 2003
+++ src/interface.c	Mon Sep 29 10:32:32 2003
@@ -177,8 +177,8 @@
 
 	
     g_signal_connect(G_OBJECT (mw.treeview), "row-activated", G_CALLBACK (gui_add_todo_item), GINT_TO_POINTER(1));
-    g_signal_connect(mw.window, "delete-event", G_CALLBACK(window_close), NULL);
-    g_signal_connect(mw.window, "destroy-event", G_CALLBACK(quit_program), NULL);
+    g_signal_connect(mw.window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
+    g_signal_connect(mw.window, "destroy-event", G_CALLBACK(gtk_main_quit), NULL);
     gtk_window_add_accel_group(GTK_WINDOW(mw.window), mw.accel_group);
     
 	if(settings.do_tray) tray_init();
