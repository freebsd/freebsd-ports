--- k3dsdk/ngui/render.cpp.orig	2010-07-03 11:27:46.000000000 +0900
+++ k3dsdk/ngui/render.cpp	2012-06-20 07:15:53.000000000 +0900
@@ -169,7 +169,7 @@
 		row[columns.separator] = false;
 	}
 
-	Gtk::ComboBox combo(model);
+	Gtk::ComboBox combo((Glib::RefPtr<Gtk::TreeModel> &) model);
 
 	combo.pack_start(columns.icon, false);
 
@@ -295,7 +295,7 @@
 		row[columns.separator] = false;
 	}
 
-	Gtk::ComboBox combo(model);
+	Gtk::ComboBox combo((Glib::RefPtr<Gtk::TreeModel> &) model);
 
 	combo.pack_start(columns.icon, false);
 
