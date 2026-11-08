--- win0.cpp.orig	2026-09-29 20:41:36.272994000 +0800
+++ win0.cpp	2026-09-29 21:28:13.280368000 +0800
@@ -473,6 +473,7 @@
 void tsin_toggle_eng_ch();
 void set_no_focus();
 
+#if 0
 #if GTK_CHECK_VERSION(3,24,0)
 static void widget_realize_cb (GtkWidget *widget)
 {
@@ -488,6 +489,7 @@
 //  ip_surface = input_panel_get_input_panel_surface (input_panel, surface);
 //  input_panel_surface_set_panel (ip_surface);
 }
+#endif
 #endif
 
 GtkWidget *create_no_focus_win()
@@ -496,6 +498,7 @@
 //  GtkWidget *win = gtk_window_new (GTK_WINDOW_POPUP);
 //  gtk_window_set_has_resize_grip(GTK_WINDOW(win), FALSE);
 #if UNIX
+#if 0
 #if GTK_CHECK_VERSION(3,24,0)
   if (!isX11()) 
   {
@@ -508,6 +511,7 @@
 	  return win;
   }
 #endif  
+#endif
   gtk_window_set_resizable(GTK_WINDOW(win), FALSE);
 #endif
 #if WIN32
