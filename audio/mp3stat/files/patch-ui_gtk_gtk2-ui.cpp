--- ui/gtk/gtk2_ui.cpp.orig	Mon Sep 20 14:04:50 2004
+++ ui/gtk/gtk2_ui.cpp	Tue Sep 21 22:54:39 2004
@@ -279,7 +279,7 @@
 Info               chosen;
 Info               chosen2;
   
-  gtk_init (&argcc, &argvv);
+  gtk_init (NULL, NULL);
 
   cmap = gdk_colormap_get_system ();
   set_graph_colors ();                                     
