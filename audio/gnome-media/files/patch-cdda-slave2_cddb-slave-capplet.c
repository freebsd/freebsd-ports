--- cddb-slave2/cddb-slave-capplet.c.orig	Tue Aug  5 08:38:21 2003
+++ cddb-slave2/cddb-slave-capplet.c	Sat Sep 27 23:20:31 2003
@@ -838,9 +838,6 @@
 	
 	gtk_container_add (GTK_CONTAINER (sw), pd->freedb_server);
 
-	g_signal_connect (G_OBJECT (pd->update), "clicked",
-			  G_CALLBACK (update_clicked), pd);
-
 	/* create the update server list button */
 	align = gtk_alignment_new (1.0, 0.5, 0.0, 0.0);
 
