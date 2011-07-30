--- frontend/linux/workbench/toolbar_manager.cpp.orig	2011-06-14 23:26:35.000000000 +0200
+++ frontend/linux/workbench/toolbar_manager.cpp	2011-06-14 23:28:22.000000000 +0200
@@ -30,7 +30,7 @@
   }
 
   Glib::RefPtr<Gtk::ListStore> model= Gtk::ListStore::create(*color_combo_columns);
-  Gtk::ComboBox *combo= new Gtk::ComboBox(model);
+  Gtk::ComboBox *combo= new Gtk::ComboBox(Glib::RefPtr<Gtk::TreeModel>(model));
 
   combo->pack_start(color_combo_columns->image);
 
