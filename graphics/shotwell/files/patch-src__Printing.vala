--- src/Printing.vala.orig
+++ src/Printing.vala
@@ -536,7 +536,7 @@
     }
 
     private void on_ppi_entry_insert_text(Gtk.Editable editable, string text, int length,
-        void *position) {
+        ref int position) {
         Gtk.Entry sender = (Gtk.Entry) editable;
         
         if (is_text_insertion_in_progress)
@@ -554,7 +554,7 @@
         }
 
         if (new_text.length > 0)
-            sender.insert_text(new_text, (int) new_text.length, position);
+            sender.insert_text(new_text, (int) new_text.length, ref position);
 
         Signal.stop_emission_by_name(sender, "insert-text");
 
@@ -616,7 +616,7 @@
         return Measurement(double.parse(custom_height_entry.get_text()), get_user_unit_choice());
     }
 
-    private void on_entry_insert_text(Gtk.Editable editable, string text, int length, void *position) {
+    private void on_entry_insert_text(Gtk.Editable editable, string text, int length, ref int position) {
         Gtk.Entry sender = (Gtk.Entry) editable;
         
         if (is_text_insertion_in_progress)
@@ -640,7 +640,7 @@
         }
 
         if (new_text.length > 0)
-            sender.insert_text(new_text, (int) new_text.length, position);
+            sender.insert_text(new_text, (int) new_text.length, ref position);
 
         Signal.stop_emission_by_name(sender, "insert-text");
 
