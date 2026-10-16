--- src/Widgets/Window.vala.orig	2020-07-22 18:10:30 UTC
+++ src/Widgets/Window.vala
@@ -227,6 +227,8 @@ public class Window : Gtk.ApplicationWindow {
         box.expand = true;
 
         Gtk.Builder builder;
+        Gtk.MenuToolButton? pref_menu = null, export_menu = null;
+
         if (prefs.use_headerbar) {
             builder = new Gtk.Builder.from_resource ("/com/voldyman/markmywords/ui/headerbar.ui");
             headerbar = (Gtk.HeaderBar) builder.get_object ("headerbar");
@@ -240,27 +242,27 @@ public class Window : Gtk.ApplicationWindow {
 
             layout.pack_start (box, false);
             add (layout);
+
+            pref_menu = (Gtk.MenuToolButton) builder.get_object ("prefMenu");
+            export_menu = (Gtk.MenuToolButton) builder.get_object ("exportMenu");
         }
 
         Gtk.IconTheme icon_theme = Gtk.IconTheme.get_default ();
-        var pref_menu = (Gtk.MenuToolButton) builder.get_object ("prefMenu");
-        var export_menu = (Gtk.MenuToolButton) builder.get_object ("exportMenu");
+        Gtk.Image menu_icon = (Gtk.Image) builder.get_object ("menuIcon");
+        Gtk.Image export_icon = (Gtk.Image) builder.get_object ("exportIcon");
 
-        Gtk.Image menu_icon = (Gtk.Image) builder.get_object ("menu-icon");
-        Gtk.Image export_icon = (Gtk.Image) builder.get_object ("export-icon");
-
         if (!icon_theme.has_icon ("open-menu")) {
             var alternate_icon = "preferences-system";
             if (!icon_theme.has_icon (alternate_icon)) {
                 alternate_icon = "gtk-preferences";
             }
             menu_icon.set_from_icon_name (alternate_icon, Gtk.IconSize.LARGE_TOOLBAR);
-            pref_menu.icon_name = alternate_icon;
+            if (pref_menu != null) pref_menu.icon_name = alternate_icon;
         }
 
         if (!icon_theme.has_icon ("document-export")) {
             export_icon.set_from_icon_name ("document-revert-rtl", Gtk.IconSize.LARGE_TOOLBAR);
-            export_menu.icon_name = "document-revert-rtl";
+            if (export_menu != null) export_menu.icon_name = "document-revert-rtl";
         }
 
         int width;
