--- gtk2_ardour/io_selector.h.orig
+++ gtk2_ardour/io_selector.h
@@ -20,12 +20,7 @@
 #ifndef __ardour_ui_io_selector_h__
 #define __ardour_ui_io_selector_h__
 
-#if __GNUC__ >= 3
-#include <ext/slist>
-using __gnu_cxx::slist;
-#else
-#include <slist.h>
-#endif
+#include <boost/container/slist.hpp>
 
 #include <string>
 
@@ -110,7 +105,7 @@ class IOSelector : public Gtk::VBox {
 	Gtk::ScrolledWindow port_display_scroller;
 
 	Glib::Mutex port_display_lock;
-	slist<Gtk::TreeView *> port_displays;
+	boost::container::slist<Gtk::TreeView *> port_displays;
 	void display_ports ();
 
 	void rescan ();
