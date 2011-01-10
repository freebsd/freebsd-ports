--- src/interface.c	Sat Jul 10 06:54:31 2010 -0700
+++ src/interface.c	Fri Jul 23 22:14:03 2010 -0700
@@ -258,11 +258,11 @@
   GtkWidget *frame15;
   GtkWidget *alignment21;
   GtkWidget *vbox54;
-  GtkWidget *checkbutton18;
-  GtkWidget *hbox56;
-  GtkWidget *label209;
-  GtkWidget *entry33;
-  GtkWidget *label208;
+  //GtkWidget *checkbutton18;
+  //GtkWidget *hbox56;
+  //GtkWidget *label209;
+  //GtkWidget *entry33;
+  //GtkWidget *label208;
   GtkWidget *frame12;
   GtkWidget *alignment12;
   GtkWidget *vbox22;
@@ -1528,30 +1528,30 @@
   gtk_widget_show (vbox54);
   gtk_container_add (GTK_CONTAINER (alignment21), vbox54);
 
-  checkbutton18 = gtk_check_button_new_with_mnemonic (_("Activate Heartrate Monitor"));
-  gtk_widget_show (checkbutton18);
-  gtk_box_pack_start (GTK_BOX (vbox54), checkbutton18, FALSE, FALSE, 0);
-  gtk_widget_set_size_request (checkbutton18, -1, 45);
-
-  hbox56 = gtk_hbox_new (FALSE, 0);
-  gtk_widget_show (hbox56);
-  gtk_box_pack_start (GTK_BOX (vbox54), hbox56, TRUE, TRUE, 0);
-
-  label209 = gtk_label_new (_("Bluetooth Address: "));
-  gtk_widget_show (label209);
-  gtk_box_pack_start (GTK_BOX (hbox56), label209, FALSE, FALSE, 0);
-  gtk_misc_set_alignment (GTK_MISC (label209), 0, 0.5);
-
-  entry33 = gtk_entry_new ();
-  gtk_widget_show (entry33);
-  gtk_box_pack_start (GTK_BOX (hbox56), entry33, FALSE, TRUE, 0);
-  gtk_entry_set_invisible_char (GTK_ENTRY (entry33), 9679);
-  gtk_entry_set_width_chars (GTK_ENTRY (entry33), 18);
-
-  label208 = gtk_label_new (_("<b>Heart Rate Monitor</b>"));
-  gtk_widget_show (label208);
-  gtk_frame_set_label_widget (GTK_FRAME (frame15), label208);
-  gtk_label_set_use_markup (GTK_LABEL (label208), TRUE);
+  //checkbutton18 = gtk_check_button_new_with_mnemonic (_("Activate Heartrate Monitor"));
+  //gtk_widget_show (checkbutton18);
+  //gtk_box_pack_start (GTK_BOX (vbox54), checkbutton18, FALSE, FALSE, 0);
+  //gtk_widget_set_size_request (checkbutton18, -1, 45);
+
+  //hbox56 = gtk_hbox_new (FALSE, 0);
+  //gtk_widget_show (hbox56);
+  //gtk_box_pack_start (GTK_BOX (vbox54), hbox56, TRUE, TRUE, 0);
+
+  //label209 = gtk_label_new (_("Bluetooth Address: "));
+  //gtk_widget_show (label209);
+  //gtk_box_pack_start (GTK_BOX (hbox56), label209, FALSE, FALSE, 0);
+  //gtk_misc_set_alignment (GTK_MISC (label209), 0, 0.5);
+
+  //entry33 = gtk_entry_new ();
+  //gtk_widget_show (entry33);
+  //gtk_box_pack_start (GTK_BOX (hbox56), entry33, FALSE, TRUE, 0);
+  //gtk_entry_set_invisible_char (GTK_ENTRY (entry33), 9679);
+  //gtk_entry_set_width_chars (GTK_ENTRY (entry33), 18);
+
+  //label208 = gtk_label_new (_("<b>Heart Rate Monitor</b>"));
+  //gtk_widget_show (label208);
+  //gtk_frame_set_label_widget (GTK_FRAME (frame15), label208);
+  //gtk_label_set_use_markup (GTK_LABEL (label208), TRUE);
 
   frame12 = gtk_frame_new (NULL);
   gtk_widget_show (frame12);
@@ -1828,12 +1828,6 @@
   g_signal_connect ((gpointer) radiobutton21, "toggled",
                     G_CALLBACK (on_radiobutton21_toggled),
                     NULL);
-  g_signal_connect ((gpointer) checkbutton18, "toggled",
-                    G_CALLBACK (on_checkbutton18_toggled),
-                    NULL);
-  g_signal_connect ((gpointer) entry33, "changed",
-                    G_CALLBACK (on_entry33_changed),
-                    NULL);
   g_signal_connect ((gpointer) entry3, "changed",
                     G_CALLBACK (on_entry3_changed),
                     NULL);
@@ -2074,11 +2068,11 @@
   GLADE_HOOKUP_OBJECT (window1, frame15, "frame15");
   GLADE_HOOKUP_OBJECT (window1, alignment21, "alignment21");
   GLADE_HOOKUP_OBJECT (window1, vbox54, "vbox54");
-  GLADE_HOOKUP_OBJECT (window1, checkbutton18, "checkbutton18");
-  GLADE_HOOKUP_OBJECT (window1, hbox56, "hbox56");
-  GLADE_HOOKUP_OBJECT (window1, label209, "label209");
-  GLADE_HOOKUP_OBJECT (window1, entry33, "entry33");
-  GLADE_HOOKUP_OBJECT (window1, label208, "label208");
+  //GLADE_HOOKUP_OBJECT (window1, checkbutton18, "checkbutton18");
+  //GLADE_HOOKUP_OBJECT (window1, hbox56, "hbox56");
+  //GLADE_HOOKUP_OBJECT (window1, label209, "label209");
+  //GLADE_HOOKUP_OBJECT (window1, entry33, "entry33");
+  //GLADE_HOOKUP_OBJECT (window1, label208, "label208");
   GLADE_HOOKUP_OBJECT (window1, frame12, "frame12");
   GLADE_HOOKUP_OBJECT (window1, alignment12, "alignment12");
   GLADE_HOOKUP_OBJECT (window1, vbox22, "vbox22");
