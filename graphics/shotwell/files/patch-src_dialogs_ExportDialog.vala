--- src/dialogs/ExportDialog.vala.orig	2022-03-24 11:17:17.231343000 +0100
+++ src/dialogs/ExportDialog.vala	2022-03-24 11:34:07.028552000 +0100
@@ -23,7 +23,8 @@
 
     private static ScaleConstraint current_constraint = ScaleConstraint.ORIGINAL;
     private static ExportFormatParameters current_parameters = ExportFormatParameters.current();
-    private static int current_scale = DEFAULT_SCALE;
+    // DEFAULT_SCALE, but vala misorders the definitions
+    private static int current_scale = 1200;
 
     private Gtk.Grid table = new Gtk.Grid();
     private Gtk.ComboBoxText quality_combo;
