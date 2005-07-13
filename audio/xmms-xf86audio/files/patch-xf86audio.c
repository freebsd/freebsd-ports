
$FreeBSD$

--- xf86audio.c.orig
+++ xf86audio.c
@@ -110,6 +110,7 @@
 static void plugin_about()
 {
 	static GtkWidget *about;
+	const gchar *s1, *s2;
 	gchar *s;
 
 	if (about != NULL) {
@@ -117,8 +118,8 @@
 		return;
 	}
 
-	const gchar *s1 = _("XF86Audio Keys Control Plugin");
-	const gchar *s2 = _(
+	s1 = _("XF86Audio Keys Control Plugin");
+	s2 = _(
 		"This plugin enables the XF86Audio keysyms produced by\n"
 		  "multimedia keyboards to control XMMS playback.\n\n"
 		  "Note that this plugin will not set up the initial keysym\n"
@@ -145,6 +146,11 @@
 
 static void plugin_configure()
 {
+	GtkWidget *vbox, *playaction_frame, *pa_hbox, *pa_vbox, *pa_label,
+		*pa_pause, *pa_restart, *pa_label2, *volume_frame,
+		*v_vbox, *v_hbox, *vol_label, *vol_spin, *button_hbox,
+		*ok, *cancel, *apply;
+	GtkObject *vol_adj;
 
 	if (config_window) {
 		gdk_window_raise(config_window->window);
@@ -163,29 +169,29 @@
 	gtk_signal_connect(GTK_OBJECT(config_window), "destroy", GTK_SIGNAL_FUNC(gtk_widget_destroyed), &config_window);
 	gtk_container_border_width(GTK_CONTAINER(config_window), 10);
 
-	GtkWidget *vbox = gtk_vbox_new(FALSE, 5);
+	vbox = gtk_vbox_new(FALSE, 5);
 	gtk_container_add(GTK_CONTAINER(config_window), vbox);
 
 	/* "On Play" frame */
 
-	GtkWidget *playaction_frame = gtk_frame_new(_("On Play"));
+	playaction_frame = gtk_frame_new(_("On Play"));
 	gtk_box_pack_start(GTK_BOX(vbox), playaction_frame, TRUE, TRUE, 0);
-	GtkWidget *pa_hbox = gtk_hbox_new(FALSE, 4);
+	pa_hbox = gtk_hbox_new(FALSE, 4);
 	gtk_container_add(GTK_CONTAINER(playaction_frame), pa_hbox);
 
-	GtkWidget *pa_vbox = gtk_vbox_new(FALSE, 4);
+	pa_vbox = gtk_vbox_new(FALSE, 4);
 
 	gtk_box_pack_start(GTK_BOX(pa_hbox), pa_vbox, TRUE, TRUE, 4);
-	GtkWidget *pa_label = gtk_label_new(
+	pa_label = gtk_label_new(
 			_("If the Play key is pressed while a song is"
 			" already playing:")
 		);
 	gtk_misc_set_alignment(GTK_MISC(pa_label), 0.0, 0.5);
 	gtk_box_pack_start(GTK_BOX(pa_vbox), pa_label, TRUE, TRUE, 2);
 
-	GtkWidget *pa_pause = gtk_radio_button_new_with_label(NULL,
+	pa_pause = gtk_radio_button_new_with_label(NULL,
 			_("Pause playback"));
-	GtkWidget *pa_restart = gtk_radio_button_new_with_label_from_widget(
+	pa_restart = gtk_radio_button_new_with_label_from_widget(
 			GTK_RADIO_BUTTON(pa_pause),
 			_("Restart the current song"));
 	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(
@@ -198,7 +204,7 @@
 	
 	gtk_box_pack_start(GTK_BOX(pa_vbox), pa_pause, FALSE, FALSE, 0);
 	gtk_box_pack_start(GTK_BOX(pa_vbox), pa_restart, FALSE, FALSE, 0);
-	GtkWidget *pa_label2 = gtk_label_new(
+	pa_label2 = gtk_label_new(
 			_("Regardless of this setting, the current song can be restarted"
 			"\nby holding down Shift while pressing the Play key.")
 		);
@@ -217,22 +223,22 @@
 
 	/* Volume change frame */
 
-	GtkWidget *volume_frame = gtk_frame_new(_("On Volume Change"));
+	volume_frame = gtk_frame_new(_("On Volume Change"));
 	gtk_box_pack_start(GTK_BOX(vbox), volume_frame, TRUE, TRUE, 0);
-	GtkWidget *v_vbox = gtk_vbox_new(FALSE, 0);
-	GtkWidget *v_hbox = gtk_hbox_new(FALSE, 4);
+	v_vbox = gtk_vbox_new(FALSE, 0);
+	v_hbox = gtk_hbox_new(FALSE, 4);
 	gtk_container_add(GTK_CONTAINER(volume_frame), v_vbox);
 	gtk_box_pack_start(GTK_BOX(v_vbox), v_hbox, TRUE, TRUE, 4);
 
-	GtkWidget *vol_label = gtk_label_new(
+	vol_label = gtk_label_new(
 			_("Volume change increment (%): ")
 			);
 	gtk_box_pack_start(GTK_BOX(v_hbox), vol_label, FALSE, FALSE, 4);
 
-	GtkObject *vol_adj = gtk_adjustment_new(
+	vol_adj = gtk_adjustment_new(
 			cf_active.volume_increment,
 			0, 100, 1, 10, 10);
-	GtkWidget *vol_spin = gtk_spin_button_new(GTK_ADJUSTMENT(vol_adj),
+	vol_spin = gtk_spin_button_new(GTK_ADJUSTMENT(vol_adj),
 			1.0, 0);
 	gtk_signal_connect(GTK_OBJECT(vol_spin), "changed",
 			GTK_SIGNAL_FUNC(on_volume_increment_change), NULL);
@@ -246,23 +252,23 @@
 
 	/* Button box at bottom of window */
 
-	GtkWidget *button_hbox = gtk_hbutton_box_new();
+	button_hbox = gtk_hbutton_box_new();
 	gtk_button_box_set_layout(GTK_BUTTON_BOX(button_hbox), GTK_BUTTONBOX_END);
 	gtk_button_box_set_spacing(GTK_BUTTON_BOX(button_hbox), 5);
 	gtk_box_pack_end(GTK_BOX(vbox), button_hbox, FALSE, FALSE, 0);
 
-	GtkWidget *ok = gtk_button_new_with_label("OK");
+	ok = gtk_button_new_with_label("OK");
 	GTK_WIDGET_SET_FLAGS(ok, GTK_CAN_DEFAULT);
 	gtk_signal_connect(GTK_OBJECT(ok), "clicked", on_config_ok, NULL);
 	gtk_box_pack_start(GTK_BOX(button_hbox), ok, TRUE, TRUE, 0);
 	gtk_widget_grab_default(ok);
 
-	GtkWidget *cancel = gtk_button_new_with_label(_("Cancel"));
+	cancel = gtk_button_new_with_label(_("Cancel"));
 	GTK_WIDGET_SET_FLAGS(cancel, GTK_CAN_DEFAULT);
 	gtk_signal_connect(GTK_OBJECT(cancel), "clicked", on_config_cancel, NULL);
 	gtk_box_pack_start(GTK_BOX(button_hbox), cancel, TRUE, TRUE, 0);
 
-	GtkWidget *apply = gtk_button_new_with_label(_("Apply"));
+	apply = gtk_button_new_with_label(_("Apply"));
 	GTK_WIDGET_SET_FLAGS(apply, GTK_CAN_DEFAULT);
 	gtk_signal_connect(GTK_OBJECT(apply), "clicked", on_config_apply, NULL);
 	gtk_box_pack_start(GTK_BOX(button_hbox), apply, TRUE, TRUE, 0);
