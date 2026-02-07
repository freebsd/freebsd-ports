--- src/Widgets/PreferencesDialog.vala.orig	2020-07-22 18:10:30 UTC
+++ src/Widgets/PreferencesDialog.vala
@@ -197,6 +197,7 @@ public class PreferencesDialog : Gtk.Dialog {
         // Dark theme
         var dark_theme_label = new Gtk.Label (_("Enable dark theme"));
         dark_theme_switch = new Gtk.Switch ();
+        dark_theme_switch.halign = Gtk.Align.START;
         dark_theme_switch.active = prefs.prefer_dark_theme;
 
         layout.attach (dark_theme_label, 0, row, 1, 1);
@@ -266,6 +267,7 @@ public class PreferencesDialog : Gtk.Dialog {
         var syntax_highlighting_label = new Gtk.Label (_("Enable syntax highlighting"));
 
         syntax_highlighting_switch = new Gtk.Switch ();
+        syntax_highlighting_switch.halign = Gtk.Align.START;
         syntax_highlighting_switch.active = prefs.render_syntax_highlighting;
 
 /*        autosave_btn.toggled.connect((b) => {
