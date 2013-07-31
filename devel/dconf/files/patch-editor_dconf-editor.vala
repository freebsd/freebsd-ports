--- editor/dconf-editor.vala.orig	2013-05-01 21:48:10.000000000 +0000
+++ editor/dconf-editor.vala	2013-05-01 21:50:26.000000000 +0000
@@ -5,6 +5,10 @@
     private Settings settings;
     private Gtk.Builder ui;
     private Gtk.ApplicationWindow window;
+    private int window_width = 0;
+    private int window_height = 0;
+    private bool window_is_maximized = false;
+    private bool window_is_fullscreen = false;
     private Gtk.TreeView dir_tree_view;
     private Gtk.TreeView key_tree_view;
     private Gtk.Grid key_info_grid;
@@ -72,8 +76,10 @@
         }
         set_app_menu((MenuModel)menu_ui.get_object("menu"));
 
-        window.set_default_size (settings.get_int ("width"), settings.get_int ("height"));
-        if (settings.get_boolean ("maximized"))
+        window.set_default_size (settings.get_int ("window-width"), settings.get_int ("window-height"));
+        if (settings.get_boolean ("window-is-fullscreen"))
+            window.fullscreen ();
+        else if (settings.get_boolean ("window-is-maximized"))
             window.maximize ();
 
         dir_tree_view = new DConfDirView();
@@ -124,6 +130,15 @@
         window.present();
     }
 
+    protected override void shutdown ()
+    {
+        base.shutdown();
+        settings.set_int ("window-width", window_width);
+        settings.set_int ("window-height", window_height);
+        settings.set_boolean ("window-is-maximized", window_is_maximized);
+        settings.set_boolean ("window-is-fullscreen", window_is_fullscreen);
+    }
+
     private void dir_selected_cb()
     {
         KeyModel? key_model = null;
@@ -201,11 +216,16 @@
         {
             if (selected_key.schema != null)
             {
+                var gettext_domain = selected_key.schema.gettext_domain;
                 schema_name = selected_key.schema.schema.id;
                 if (selected_key.schema.summary != null)
                     summary = selected_key.schema.summary;
+                if (gettext_domain != null && summary != "")
+                    summary = dgettext(gettext_domain, summary);
                 if (selected_key.schema.description != null)
                     description = selected_key.schema.description;
+                if (gettext_domain != null && description != "")
+                    description = dgettext(gettext_domain, description);
                 type = key_to_description(selected_key);
                 default_value = selected_key.schema.default_value.print(false);
             }
@@ -236,10 +256,10 @@
 
     private bool main_window_configure_event_cb (Gtk.Widget widget, Gdk.EventConfigure event)
     {
-        if (!settings.get_boolean ("maximized"))
+        if (!window_is_maximized && !window_is_fullscreen)
         {
-            settings.set_int ("width", event.width);
-            settings.set_int ("height", event.height);
+            window_width = event.width;
+            window_height = event.height;
         }
 
         return false;
@@ -248,10 +268,9 @@
     private bool main_window_window_state_event_cb (Gtk.Widget widget, Gdk.EventWindowState event)
     {
         if ((event.changed_mask & Gdk.WindowState.MAXIMIZED) != 0)
-        {
-            var is_maximized = (event.new_window_state & Gdk.WindowState.MAXIMIZED) != 0;
-            settings.set_boolean ("maximized", is_maximized);
-        }
+            window_is_maximized = (event.new_window_state & Gdk.WindowState.MAXIMIZED) != 0;
+        if ((event.changed_mask & Gdk.WindowState.FULLSCREEN) != 0)
+            window_is_fullscreen = (event.new_window_state & Gdk.WindowState.FULLSCREEN) != 0;
 
         return false;
     }
@@ -266,6 +285,7 @@
     {
         search_label.set_text("");
 
+        /* Get the current position in the tree */
         Gtk.TreeIter iter;
         var key_iter = Gtk.TreeIter();
         var have_key_iter = false;
@@ -283,17 +303,31 @@
         else if (!model.get_iter_first(out iter))
             return;
 
+        var on_first_directory = true;
         do
         {
+            /* Select next directory that matches */
             var dir = model.get_directory(iter);
             if (!have_key_iter)
+            {
                 have_key_iter = dir.key_model.get_iter_first(out key_iter);
+                if (!on_first_directory && dir.name.index_of(search_entry.text) >= 0)
+                {
+                    dir_tree_view.expand_to_path(model.get_path(iter));
+                    dir_tree_view.get_selection().select_iter(iter);
+                    dir_tree_view.scroll_to_cell(model.get_path(iter), null, false, 0, 0);
+                    return;
+                }
+            }
+            on_first_directory = false;
+
+            /* Select next key that matches */
             if (have_key_iter)
             {
                 do
                 {
                     var key = dir.key_model.get_key(key_iter);
-                    if (key.name.index_of (search_entry.text) >= 0)
+                    if (key_matches(key, search_entry.text))
                     {
                         dir_tree_view.expand_to_path(model.get_path(iter));
                         dir_tree_view.get_selection().select_iter(iter);
@@ -310,6 +344,28 @@
         search_label.set_text(_("Not found"));
     }
 
+    private bool key_matches (Key key, string text)
+    {
+        /* Check key name */
+        if (key.name.index_of(text) >= 0)
+            return true;
+
+        /* Check key schema (description) */
+        if (key.schema != null)
+        {
+            if (key.schema.summary != null && key.schema.summary.index_of(text) >= 0)
+                return true;
+            if (key.schema.description != null && key.schema.description.index_of(text) >= 0)
+                return true;
+        }
+
+        /* Check key value */
+        if (key.value.is_of_type(VariantType.STRING) && key.value.get_string().index_of(text) >= 0)
+            return true;
+
+        return false;
+    }
+
     private bool get_next_iter(ref Gtk.TreeIter iter)
     {
         /* Search children next */
