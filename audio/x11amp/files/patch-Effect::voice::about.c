--- Effect/voice/about.c.orig	Tue Feb 24 22:46:03 2004
+++ Effect/voice/about.c	Tue Feb 24 22:46:43 2004
@@ -31,9 +31,8 @@
 	dialog=gtk_dialog_new();
 	gtk_window_set_title(GTK_WINDOW(dialog),"About Voice Removal Plugin 0.9");
 	gtk_container_border_width(GTK_CONTAINER(dialog),5);
-	label=gtk_label_new("X11AMP Voice Removal Plugin 0.9\n
-A simple voice removal plugin by 
-Anders Carlsson <anders.carlsson@tordata.se>"
+	label=gtk_label_new("X11AMP Voice Removal Plugin 0.9\n"
+"A simple voice removal plugin by Anders Carlsson <anders.carlsson@tordata.se>"
 );
 	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox),label,TRUE,TRUE,0);
       	gtk_widget_show(label);
