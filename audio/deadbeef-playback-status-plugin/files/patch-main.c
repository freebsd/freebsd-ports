--- main.c.orig	2015-09-12 12:42:47 UTC
+++ main.c
@@ -89,13 +89,13 @@ load_config (gpointer user_data)
     for (int i = 0; i < CONFIG_NUM_LINES; i++) {
         snprintf (conf_format_str, sizeof (conf_format_str), "%s%02d", CONFSTR_VM_FORMAT, i);
         if (i == 0) {
-            CONFIG_FORMAT[i] = strdup (deadbeef->conf_get_str_fast (conf_format_str, "<span foreground='grey' weight='bold' size='medium'>%playback_time% / %length%</span>"));
+            CONFIG_FORMAT[i] = strdup (deadbeef->conf_get_str_fast (conf_format_str, "<span size='xx-large' weight='semibold'>%e / %l%</span>"));
         }
         else if (i == 1) {
-            CONFIG_FORMAT[i] = strdup (deadbeef->conf_get_str_fast (conf_format_str, "<span weight='bold' size='x-large'>%tracknumber%. %title%</span>"));
+            CONFIG_FORMAT[i] = strdup (deadbeef->conf_get_str_fast (conf_format_str, "<span size='large'>%n. %t</span>"));
         }
         else if (i== 2) {
-            CONFIG_FORMAT[i] = strdup (deadbeef->conf_get_str_fast (conf_format_str, "%album% - <i>%album artist%</i>"));
+            CONFIG_FORMAT[i] = strdup (deadbeef->conf_get_str_fast (conf_format_str, "<span size='large' foreground='gray31'>%a - <i>%b</i></span>"));
         }
         else {
             CONFIG_FORMAT[i] = strdup (deadbeef->conf_get_str_fast (conf_format_str, ""));
@@ -113,12 +113,18 @@ on_config_changed (gpointer user_data, u
     load_config (user_data);
     for (int i = 0; i < MAX_LINES; i++) {
         if (w->bytecode[i]) {
+#if DDB_API_LEVEL >= 8
             deadbeef->tf_free (w->bytecode[i]);
+#endif
             w->bytecode[i] = NULL;
         }
         if (i < CONFIG_NUM_LINES) {
             gtk_widget_show (w->label[i]);
+#if DDB_API_LEVEL >= 8
             w->bytecode[i] = deadbeef->tf_compile (CONFIG_FORMAT[i]);
+#else
+            w->bytecode[i] = CONFIG_FORMAT[i];
+#endif
         }
         else {
             gtk_widget_hide (w->label[i]);
@@ -146,6 +152,8 @@ on_num_lines_changed (GtkSpinButton *spi
     return TRUE;
 }
 
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
 static void
 on_button_config (GtkMenuItem *menuitem, gpointer user_data)
 {
@@ -158,8 +166,6 @@ on_button_config (GtkMenuItem *menuitem,
     GtkWidget *applybutton1;
     GtkWidget *cancelbutton1;
     GtkWidget *okbutton1;
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
     playback_status_properties = gtk_dialog_new ();
     gtk_window_set_title (GTK_WINDOW (playback_status_properties), "Playback Status Properties");
     gtk_window_set_type_hint (GTK_WINDOW (playback_status_properties), GDK_WINDOW_TYPE_HINT_DIALOG);
@@ -231,9 +237,9 @@ on_button_config (GtkMenuItem *menuitem,
         break;
     }
     gtk_widget_destroy (playback_status_properties);
-#pragma GCC diagnostic pop
     return;
 }
+#pragma GCC diagnostic pop
 
 static void
 w_playback_status_destroy (ddb_gtkui_widget_t *w) {
@@ -241,7 +247,9 @@ w_playback_status_destroy (ddb_gtkui_wid
     deadbeef->vis_waveform_unlisten (w);
     for (int i = 0; i < MAX_LINES; ++i) {
         if (s->bytecode[i]) {
+#if DDB_API_LEVEL >= 8
             deadbeef->tf_free (s->bytecode[i]);
+#endif
             s->bytecode[i] = NULL;
         }
     }
@@ -268,6 +276,7 @@ playback_status_set_label_text (gpointer
     char title[1024];
     DB_playItem_t *playing = deadbeef->streamer_get_playing_track ();
     if (playing) {
+#if DDB_API_LEVEL >= 8
         ddb_tf_context_t ctx = {
             ._size = sizeof (ddb_tf_context_t),
             .it = playing,
@@ -282,12 +291,19 @@ playback_status_set_label_text (gpointer
             deadbeef->plt_unref (ctx.plt);
             ctx.plt = NULL;
         }
+#else
+        for (int i = 0; i < CONFIG_NUM_LINES; i++) {
+            if (deadbeef->pl_format_title(playing, -1, title, sizeof(title)
+              -1, -1, w->bytecode[i]) >= 0)
+                gtk_label_set_markup (GTK_LABEL (w->label[i]), title);
+        }
+#endif
         deadbeef->pl_item_unref (playing);
     }
     else {
-        gtk_label_set_markup (GTK_LABEL (w->label[0]), "<span weight='bold' size='x-large'>Stopped</span>");
-        for (int i = 1; i < CONFIG_NUM_LINES; i++) {
-            gtk_label_set_markup (GTK_LABEL (w->label[i]), "");
+        for (int i = 0; i < CONFIG_NUM_LINES; i++) {
+            gtk_label_set_markup (GTK_LABEL (w->label[i]), i == 1 ?
+              "<span weight='semibold' size='x-large'>Stopped</span>" : "");
         }
     }
     deadbeef->mutex_unlock (w->mutex);
@@ -371,7 +387,11 @@ w_playback_status_init (ddb_gtkui_widget
     for (int i = 0; i < MAX_LINES; i++) {
         if (i < CONFIG_NUM_LINES) {
             gtk_widget_show (s->label[i]);
+#if DDB_API_LEVEL >= 8
             s->bytecode[i] = deadbeef->tf_compile (CONFIG_FORMAT[i]);
+#else
+            s->bytecode[i] = CONFIG_FORMAT[i];
+#endif
         }
         else {
             gtk_widget_hide (s->label[i]);
