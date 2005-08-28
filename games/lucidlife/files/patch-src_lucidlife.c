--- src/lucidlife.c.orig	Thu Jun 23 11:36:30 2005
+++ src/lucidlife.c	Sun Aug 28 16:07:12 2005
@@ -709,12 +709,13 @@
 
 void file_new(void)
 {
+	GtkAction *action;
 	if (state.pattern_running)
 		start_stop();
 	free(state.pattern_path);
 	state.pattern_path = NULL;
 	gtk_window_set_title(GTK_WINDOW(gui.window), TITLE);
-	GtkAction *action = gtk_action_group_get_action (gui.action_group, "Revert");
+	gtk_action_group_get_action (gui.action_group, "Revert");
 	gtk_action_set_sensitive(action, FALSE);
 	state.last_drawn = null_point;
 	deactivate_selection(FALSE);
@@ -734,6 +735,9 @@
 void file_open(void)
 {
 	GtkWidget *chooser;
+	GtkFileFilter *filter;
+	char *extension;
+	int i;
 
 	chooser = gtk_file_chooser_dialog_new (
 		"Open Pattern",
@@ -746,9 +750,6 @@
 	gtk_dialog_set_default_response(
 		GTK_DIALOG(chooser), GTK_RESPONSE_ACCEPT);
 
-	GtkFileFilter *filter;
-	char *extension;
-	int i;
 	for (i=0; i < NUM_FORMATS; i++) {
 		filter = gtk_file_filter_new ();
 		extension = g_strconcat("*.", default_file_extensions[i], NULL);
@@ -872,6 +873,7 @@
 			char *message;
 			GtkWidget *dialog;
 			const gchar *path;
+			GtkWidget *label;
 
 			dialog = gtk_dialog_new_with_buttons (
 				"File Exists",
@@ -884,7 +886,7 @@
 			path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chooser));
 			message = dsprintf("<b><big>Overwrite file?</big></b>\n\nThe file '%s'"
 				" exists, do you wish to overwrite it?", path);
-			GtkWidget *label = gtk_label_new (message);
+			label = gtk_label_new (message);
 			// TODO: add big question icon
 			gtk_label_set_use_markup (GTK_LABEL (label), TRUE);
 			gtk_label_set_line_wrap (GTK_LABEL (label), TRUE);
@@ -1001,6 +1003,7 @@
 	boolean  found_collection = FALSE;
 	char*    buf;
 	int32    i;
+	gint result;
 
 	dialog = gtk_dialog_new_with_buttons (
 		_("Choose Pattern Collection"),
@@ -1072,7 +1075,7 @@
 
 
 	gtk_widget_show_all (dialog);
-	gint result = gtk_dialog_run (GTK_DIALOG (dialog));
+	result = gtk_dialog_run (GTK_DIALOG (dialog));
 	if (result == GTK_RESPONSE_ACCEPT) {
 		char*    dir;
 		int succeeded;
@@ -1375,6 +1378,11 @@
 	GtkObject *adj;
 	GtkWidget *spin;
 	guint i;
+	char* color_ui_names[NUM_COLORS] = {
+		"Background:",
+		"Live cells:",
+		"Grid lines:",
+		"Selection box:"};
 
 	dialog = gtk_dialog_new_with_buttons (
 		_("Preferences"),
@@ -1384,12 +1392,6 @@
 		GTK_RESPONSE_ACCEPT,
 		NULL);
 
-	char* color_ui_names[NUM_COLORS] = {
-		"Background:",
-		"Live cells:",
-		"Grid lines:",
-		"Selection box:"};
-
 	label = gtk_label_new (NULL);
 	gtk_label_set_markup (GTK_LABEL (label), _("<b>Colors</b>"));
 	gtk_misc_set_alignment (GTK_MISC (label), 0.0f, 0.0f);
@@ -1478,6 +1480,7 @@
 	GtkWidget*  hbox;
 	GtkWidget*  jumpspin;
 	GtkObject *jumpadj;
+	gint result;
 
 	/* Setup the dialog window */
 	dialog = gtk_dialog_new_with_buttons (
@@ -1506,7 +1509,7 @@
 
 	/* Show the dialog */
 	gtk_widget_show_all(dialog);
-	gint result = gtk_dialog_run (GTK_DIALOG (dialog));
+	result = gtk_dialog_run (GTK_DIALOG (dialog));
 	if (result == GTK_RESPONSE_ACCEPT) {
 		gtk_widget_hide (dialog);
 		run_jump_execute (
@@ -1536,20 +1539,24 @@
 		NULL);
 	
 	GtkWidget *vbox = gtk_vbox_new (FALSE, 6);
+	GtkAdjustment *adj;
+	GtkWidget *slider;
+	GtkWidget *check;
+	GtkWidget *label;
 	gtk_box_pack_start_defaults (GTK_BOX (GTK_DIALOG (dialog)->vbox), vbox);
 	gtk_container_set_border_width (GTK_CONTAINER (vbox), 12);
 	
-	GtkAdjustment *adj = gtk_range_get_adjustment (GTK_RANGE (gui.speed_slider));
-	GtkWidget *slider = gtk_hscale_new (adj);
+	adj = gtk_range_get_adjustment (GTK_RANGE (gui.speed_slider));
+	slider = gtk_hscale_new (adj);
 	gtk_box_pack_start (GTK_BOX (vbox), slider, FALSE, FALSE, 0);
 	
-	GtkWidget *check = gtk_check_button_new_with_mnemonic (
+	check = gtk_check_button_new_with_mnemonic (
 		_("_Skip frames to achieve speed"));
 	g_signal_connect (check, "toggled", G_CALLBACK (prefs_skip_cb), NULL);
 	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (check), state.skip_frames);
 	gtk_box_pack_start (GTK_BOX (vbox), check, FALSE, FALSE, 0);		
 	
-	GtkWidget *label = gtk_label_new ("");
+	label = gtk_label_new ("");
 	gtk_label_set_markup (
 		GTK_LABEL (label),
 		_("<i>The speed set here is a target: the actual speed is limited "
@@ -1584,6 +1591,7 @@
 void help_about(void)
 {
 	GtkWidget*  dialog;
+	GdkPixbuf* pixbuf;
 
 	/* Set up the dialog window */
 	dialog = gtk_about_dialog_new();
@@ -1597,8 +1605,6 @@
 	gtk_about_dialog_set_website (GTK_ABOUT_DIALOG (dialog), "http://icculus.org/~jcspray/LucidLife/");
 
 	/* Add the banner */
-	GdkPixbuf* pixbuf;
-
 	pixbuf = gdk_pixbuf_new_from_file (DATADIR "/graphics/logo.png", NULL);
 
 	if (pixbuf)
@@ -1851,6 +1857,8 @@
 	GtkWidget*  widget2;
 
 	int32       i;
+	GtkAccelGroup *accel_group;
+	GError *error = NULL;
 
 	init_rgb();
 	init_window();
@@ -1878,11 +1886,10 @@
 	gtk_ui_manager_insert_action_group (gui.ui_manager, gui.action_group, 0);
 
 	/* Associate the GtkUIManager's accelerator group with the main window */
-	GtkAccelGroup *accel_group = gtk_ui_manager_get_accel_group (gui.ui_manager);
+	accel_group = gtk_ui_manager_get_accel_group (gui.ui_manager);
 	gtk_window_add_accel_group (GTK_WINDOW (gui.window), accel_group);
 
 	/* Load the UI string for menus, toolbars and accelerators, checking for errors */
-	GError *error = NULL;
 	if (!gtk_ui_manager_add_ui_from_string (
 		gui.ui_manager, ui_description, -1, &error)) {
 			g_message ("building menus failed: %s", error->message);
@@ -1966,11 +1973,10 @@
 	GtkIconSource *icon_source;
 	gint i;
 	gchar *path;
+	const gint n_icons = sizeof (stock_icon_files) / sizeof (gchar*);
 
 	icon_factory = gtk_icon_factory_new ();
 
-	const gint n_icons = sizeof (stock_icon_files) / sizeof (gchar*);
-
 	for (i = 0; i < n_icons; ++i) {
 		icon_set = gtk_icon_set_new ();
 		icon_source = gtk_icon_source_new ();
@@ -2007,6 +2013,12 @@
  */
 void init_menubar(GtkWidget* containing_box)
 {
+	GtkWidget *file_menu = NULL;
+	int i;
+	char *str;
+	GtkWidget *item = NULL;
+	int *num;
+
 	gui.menubar = gtk_ui_manager_get_widget (gui.ui_manager, "/MainMenu");
 	gtk_box_pack_start (GTK_BOX (containing_box), gui.menubar, FALSE, FALSE, 0);
 
@@ -2042,11 +2054,6 @@
 
 
 	/* Setup recent files list */
-	GtkWidget *file_menu = NULL;
-	int i;
-	char *str;
-	GtkWidget *item = NULL;
-	int *num;
 	
 	file_menu = gtk_widget_get_parent (
 		gtk_ui_manager_get_widget (
@@ -2088,14 +2095,17 @@
  */
 void init_toolbar(GtkWidget* containing_box)
 {
+	GtkToolItem *item;
+	GtkWidget *hbox;
+
 	gui.toolbar = gtk_ui_manager_get_widget (gui.ui_manager, "/MainToolBar");
 	gtk_box_pack_start (GTK_BOX (containing_box), gui.toolbar, FALSE, FALSE, 0);
 
 	/* Create the Gen/s slider */
-	GtkToolItem *item = gtk_separator_tool_item_new();
+	item = gtk_separator_tool_item_new();
 	gtk_toolbar_insert (GTK_TOOLBAR (gui.toolbar), item, -1);
 
-	GtkWidget *hbox = gtk_hbox_new(FALSE, 0);
+	hbox = gtk_hbox_new(FALSE, 0);
 	init_speed_box(hbox);
 	item = gtk_tool_item_new();
 	gtk_tool_item_set_expand (item, TRUE);
@@ -2727,9 +2737,11 @@
  */
 void prefs_speed_max_cb (GtkAdjustment *adj, gpointer user_data)
 {
+	GtkAdjustment *speedadj;
+
 	config.speed_max = gtk_adjustment_get_value (adj);
 	
-	GtkAdjustment *speedadj = gtk_range_get_adjustment (GTK_RANGE (gui.speed_slider));
+	speedadj = gtk_range_get_adjustment (GTK_RANGE (gui.speed_slider));
 	speedadj->upper = config.speed_max;
 	gtk_adjustment_changed (speedadj);
 	
@@ -3289,12 +3301,13 @@
  */
 void set_active_tool (tool_id newtool)
 {
+	GdkCursor *newcursor = NULL;
+
 	state.active_tool = newtool;
 
 	if (state.active_tool != TOOL_SELECT)
 		deactivate_selection (TRUE);
 	
-	GdkCursor *newcursor = NULL;
 	if (state.active_tool == TOOL_GRAB) {
 		newcursor = gdk_cursor_new (GDK_FLEUR);
 	} else if (state.active_tool == TOOL_SELECT) {
@@ -3674,6 +3687,7 @@
 	char*             final_path;
 	load_result_type  load_result;
 	struct stat       statbuf;
+	GtkAction *action;
 
 	resolved_path = get_canonical_path(path);
 	if (!resolved_path) {
@@ -3734,7 +3748,7 @@
 	update_tick_label();
 	update_population_label();
 	update_description_textbox(FALSE);
-	GtkAction *action = gtk_action_group_get_action (gui.action_group, "Revert");
+	action = gtk_action_group_get_action (gui.action_group, "Revert");
 	gtk_action_set_sensitive (action, TRUE);
 	view_recenter();   /* will trigger a canvas redraw */
 	set_status_message(FILE_LOADED_MESSAGE, TRUE);
@@ -3759,11 +3773,12 @@
 	save_result = save_pattern(resolved_path, format);
 	if (save_result == SAVE_SUCCESS) {
 		if (!state.pattern_path || !STR_EQUAL(resolved_path, state.pattern_path)) {
+		    GtkAction *action;
 		    free(state.pattern_path);
 		    state.pattern_path = resolved_path;
 		    add_to_recent_files();
 		    put_filename_in_window_title();
-				GtkAction *action = gtk_action_group_get_action (gui.action_group, "Revert");
+				action = gtk_action_group_get_action (gui.action_group, "Revert");
 				gtk_action_set_sensitive(action, TRUE);
 		} else
 		    free(resolved_path);
@@ -4277,9 +4292,11 @@
  */
 void start_stop(void)
 {
+	GtkAction *action;
+
 	state.pattern_running = !state.pattern_running;
 
-	GtkAction *action = gtk_action_group_get_action (gui.action_group, "Play");
+	action = gtk_action_group_get_action (gui.action_group, "Play");
 	gtk_toggle_action_set_active (GTK_TOGGLE_ACTION (action), state.pattern_running);
 
 	if (state.pattern_running) {
