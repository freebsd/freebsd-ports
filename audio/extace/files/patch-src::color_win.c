
$FreeBSD$

--- src/color_win.c.orig	Wed Feb 26 01:22:19 2003
+++ src/color_win.c	Fri May 23 18:26:18 2003
@@ -579,12 +579,12 @@
 		button = gtk_button_new_with_label("Set Color");
 		gtk_box_pack_start(GTK_BOX(hbox),button,TRUE,TRUE,0);
 		gtk_signal_connect(GTK_OBJECT(button), "clicked",
-				(GtkSignalFunc)color_button, (gpointer)SET_COLOR);
+				(GtkSignalFunc)color_button, (gint)SET_COLOR);
 
 		button = gtk_button_new_with_label("Close");
 		gtk_box_pack_start(GTK_BOX(hbox),button,TRUE,TRUE,0);
 		gtk_signal_connect(GTK_OBJECT(button), "clicked",
-				(GtkSignalFunc)color_button, (gpointer)CLOSE);
+				(GtkSignalFunc)color_button, (gint)CLOSE);
 
 		hbox = gtk_hbox_new(TRUE,0);
 		gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE,0);
@@ -592,12 +592,12 @@
 		button = gtk_button_new_with_label("Save");
 		gtk_box_pack_start(GTK_BOX(hbox),button,TRUE,TRUE,0);
 		gtk_signal_connect(GTK_OBJECT(button), "clicked",
-				(GtkSignalFunc)color_button, (gpointer)SAVE);
+				(GtkSignalFunc)color_button, (gint)SAVE);
 
 		button = gtk_button_new_with_label("Load");
 		gtk_box_pack_start(GTK_BOX(hbox),button,TRUE,TRUE,0);
 		gtk_signal_connect(GTK_OBJECT(button), "clicked",
-				(GtkSignalFunc)color_button, (gpointer)LOAD);
+				(GtkSignalFunc)color_button, (gint)LOAD);
 
 		gtk_widget_show_all(grad_win);
 	}
