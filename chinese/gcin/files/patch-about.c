--- about.c.orig	Sat Feb 26 21:42:00 2005
+++ about.c	Thu May 12 04:02:17 2005
@@ -69,10 +69,16 @@
     gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 3);
 
     GtkWidget *separator = gtk_hseparator_new ();
+    GtkWidget *vseparator = gtk_vseparator_new ();
     gtk_box_pack_start(GTK_BOX(vbox), separator, FALSE, FALSE, 3);
 
-    GtkWidget *label_sf = gtk_label_new ("http://www.csie.nctu.edu.tw/~cp76/gcin");
+    GtkWidget *label_sf = gtk_label_new ("gcin WWW:\nhttp://www.csie.nctu.edu.tw/~cp76/gcin");
+    gtk_misc_set_alignment (GTK_MISC (label_sf), 0, 0);
+    GtkWidget *label_FreeBSD = gtk_label_new ("Feedback:\nhttp://cle.linux.org.tw/gcin/");
+    gtk_misc_set_alignment (GTK_MISC (label_FreeBSD), 0, 0);
     gtk_box_pack_start(GTK_BOX(vbox), label_sf, FALSE, FALSE, 0);
+    gtk_box_pack_start(GTK_BOX(vbox), vseparator, FALSE, FALSE, 3);
+    gtk_box_pack_start(GTK_BOX(vbox), label_FreeBSD, FALSE, FALSE, 0);
 
 
     /* Now on to the image stuff */
