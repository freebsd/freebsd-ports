--- General/ir/about.c.orig	Tue Feb 24 22:47:57 2004
+++ General/ir/about.c	Tue Feb 24 22:48:46 2004
@@ -34,9 +34,9 @@
 	gtk_container_border_width(GTK_CONTAINER(frame),5);
 	gtk_box_pack_start(GTK_BOX(vbox),frame,FALSE,FALSE,0);
 
-	label=gtk_label_new("\nCreated by Charles Sielski <stray@teklabs.net>\n
-			 Control X11amp with your TV/VCR/Stereo remote \n
-			IRman page - http://www.evation.com/irman/\n");
+	label=gtk_label_new("Created by Charles Sielski <stray@teklabs.net>\n"
+			"Control X11amp with your TV/VCR/Stereo remote\n"
+			"IRman page - http://www.evation.com/irman/\n");
 	
 	gtk_container_add(GTK_CONTAINER(frame),label);
 
