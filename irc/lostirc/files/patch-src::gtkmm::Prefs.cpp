--- src/gtkmm/Prefs.cpp.ori	Sat Feb  7 17:42:11 2004
+++ src/gtkmm/Prefs.cpp	Sat Feb  7 17:42:45 2004
@@ -127,7 +127,7 @@
     row++;
 
     // Buffer size for text
-    bufferspin.set_value(double(App->options.buffer_size()));
+    bufferspin.set_value(double(*App->options.buffer_size()));
     Gtk::Label *plabel4 = manage(new Gtk::Label(_("Maximium number of lines to cache:"), Gtk::ALIGN_LEFT));
     _prefs_table.attach(*plabel4, 0, 1, row, row + 1);
     _prefs_table.attach(bufferspin, 1, 2, row, row + 1);
