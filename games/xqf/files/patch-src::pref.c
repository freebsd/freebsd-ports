--- src/pref.c.orig	Sun Aug  8 03:34:05 2004
+++ src/pref.c	Mon Aug 16 21:44:39 2004
@@ -2486,6 +2486,7 @@
   GtkWidget *defaults_button;
   GtkWidget *page_vbox;
   struct game *g;
+  gint width;
 
   //tooltips = gtk_tooltips_new ();
   
@@ -2660,7 +2661,7 @@
     }
   }
 
-  gint width = gtk_clist_optimal_column_width (GTK_CLIST (arguments_clist), 0);
+  width = gtk_clist_optimal_column_width (GTK_CLIST (arguments_clist), 0);
   gtk_clist_set_column_width (GTK_CLIST (arguments_clist), 0, width?width:60);
   gtk_clist_set_column_width (GTK_CLIST (arguments_clist), 1,
 	  gtk_clist_optimal_column_width (GTK_CLIST (arguments_clist), 1));
