--- k3dsdk/ngui/main_document_window.cpp.orig	2010-07-03 11:27:46.000000000 +0900
+++ k3dsdk/ngui/main_document_window.cpp	2012-06-20 07:13:29.000000000 +0900
@@ -1371,7 +1371,7 @@
 			Gtk::HBox import_box(false, 5);
 			Gtk::Label import_label(_("Choose import plugin:"));
 
-			Gtk::ComboBox import_combo(model);
+			Gtk::ComboBox import_combo((Glib::RefPtr<Gtk::TreeModel> &) model);
 			import_combo.pack_start(columns.icon, false);
 			import_combo.pack_start(columns.label);
 			import_combo.set_active(0);
@@ -1461,7 +1461,7 @@
 			Gtk::HBox export_box(false, 5);
 			Gtk::Label export_label(_("Choose export plugin:"));
 
-			Gtk::ComboBox export_combo(model);
+			Gtk::ComboBox export_combo((Glib::RefPtr<Gtk::TreeModel> &) model);
 			export_combo.pack_start(columns.icon, false);
 			export_combo.pack_start(columns.label);
 			export_combo.set_active(0);
