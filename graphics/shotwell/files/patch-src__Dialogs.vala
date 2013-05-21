--- src/Dialogs.vala.orig
+++ src/Dialogs.vala
@@ -419,7 +419,7 @@
         ok_button.sensitive = (pixels_entry.get_text_length() > 0) && (int.parse(pixels_entry.get_text()) > 0);
     }
     
-    private void on_pixels_insert_text(string text, int length, void *position) {
+    private void on_pixels_insert_text(string text, int length, ref int position) {
         // This is necessary because SignalHandler.block_by_func() is not properly bound
         if (in_insert)
             return;
@@ -438,7 +438,7 @@
         }
         
         if (new_text.length > 0)
-            pixels_entry.insert_text(new_text, (int) new_text.length, position);
+            pixels_entry.insert_text(new_text, (int) new_text.length, ref position);
         
         Signal.stop_emission_by_name(pixels_entry, "insert-text");
         
