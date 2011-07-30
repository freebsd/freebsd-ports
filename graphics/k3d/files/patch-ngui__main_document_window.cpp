--- ngui/main_document_window.cpp.orig	2007-01-23 05:06:31.000000000 +0100
+++ ngui/main_document_window.cpp	2011-07-26 20:57:07.000000000 +0200
@@ -1501,7 +1501,7 @@ private:
 			Gtk::HBox import_box(false, 5);
 			Gtk::Label import_label(_("Choose import plugin:"));
 
-			Gtk::ComboBox import_combo(model);
+			Gtk::ComboBox import_combo((Glib::RefPtr<Gtk::TreeModel> &) model);
 			import_combo.pack_start(columns.icon, false);
 			import_combo.pack_start(columns.label);
 			import_combo.set_active(0);
@@ -1582,7 +1582,7 @@ private:
 			Gtk::HBox export_box(false, 5);
 			Gtk::Label export_label(_("Choose export plugin:"));
 
-			Gtk::ComboBox export_combo(model);
+			Gtk::ComboBox export_combo((Glib::RefPtr<Gtk::TreeModel> &) model);
 			export_combo.pack_start(columns.icon, false);
 			export_combo.pack_start(columns.label);
 			export_combo.set_active(0);
