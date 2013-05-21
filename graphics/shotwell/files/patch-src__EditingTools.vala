--- src/EditingTools.vala.orig
+++ src/EditingTools.vala
@@ -773,15 +773,15 @@
         return false;
     }
 
-    private void on_width_insert_text(string text, int length, void *position) {
-        on_entry_insert_text(crop_tool_window.custom_width_entry, text, length, position);
+    private void on_width_insert_text(string text, int length, ref int position) {
+        on_entry_insert_text(crop_tool_window.custom_width_entry, text, length, ref position);
     }
 
-    private void on_height_insert_text(string text, int length, void *position) {
-        on_entry_insert_text(crop_tool_window.custom_height_entry, text, length, position);
+    private void on_height_insert_text(string text, int length, ref int position) {
+        on_entry_insert_text(crop_tool_window.custom_height_entry, text, length, ref position);
     }
 
-    private void on_entry_insert_text(Gtk.Entry sender, string text, int length, void *position) {
+    private void on_entry_insert_text(Gtk.Entry sender, string text, int length, ref int position) {
         if (entry_insert_in_progress)
             return;
             
@@ -799,7 +799,7 @@
         }
         
         if (new_text.length > 0)
-            sender.insert_text(new_text, (int) new_text.length, position);
+            sender.insert_text(new_text, (int) new_text.length, ref position);
 
         Signal.stop_emission_by_name(sender, "insert-text");
         
