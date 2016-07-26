--- ui/gtk/gtk2_ui.cpp.orig	2004-09-30 04:07:54 UTC
+++ ui/gtk/gtk2_ui.cpp
@@ -285,7 +285,7 @@ gtk2_ui::gtk_interface()
 Info               chosen;
 Info               chosen2;
   
-  gtk_init (&argcc, &argvv);
+  gtk_init (NULL, NULL);
 
   cmap = gdk_colormap_get_system ();
   set_graph_colors ();                                     
