
$FreeBSD$

--- src/color_win.c	2002/08/30 13:00:11	1.1
+++ src/color_win.c	2002/08/30 13:00:52
@@ -61,18 +61,18 @@
     //    printf("Color_button()\n");
     switch ((gint)data)
     {
-	case (gpointer)SET_COLOR:
+	case (gint)SET_COLOR:
 	    update_gradient(NULL, color_loc);
 	    init_colortab();
 	    gradient_update();
 	    break;
 
-	case (gpointer)CLOSE:
+	case (gint)CLOSE:
 	    gtk_widget_hide(grad_win_ptr);
 	    grad_win_present = 0;
 	    break;
 
-	case (gpointer)SAVE:
+	case (gint)SAVE:
 	    filew = gtk_file_selection_new("Save Colormap");
 	    gtk_signal_connect (GTK_OBJECT(filew), "destroy",
 		    (GtkSignalFunc) gtk_widget_destroy, GTK_OBJECT (filew));
@@ -85,7 +85,7 @@
 	    gtk_file_selection_set_filename(GTK_FILE_SELECTION(filew),g_strconcat(g_get_home_dir(),"/.eXtace/ColorMaps/", NULL));
 	    gtk_widget_show(filew);
 	    break;
-	case (gpointer)LOAD:
+	case (gint)LOAD:
 	    filew = gtk_file_selection_new("Load Colormap");
 	    gtk_signal_connect (GTK_OBJECT(filew), "destroy",
 		    (GtkSignalFunc) gtk_widget_destroy, GTK_OBJECT (filew));
