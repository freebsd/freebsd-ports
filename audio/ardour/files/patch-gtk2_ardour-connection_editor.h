--- gtk2_ardour/connection_editor.h.orig
+++ gtk2_ardour/connection_editor.h
@@ -20,12 +20,7 @@
 #ifndef __ardour_gtk_connection_editor_h__
 #define __ardour_gtk_connection_editor_h__
 
-#if __GNUC__ >= 3
-#include <ext/slist>
-using __gnu_cxx::slist;
-#else
-#include <slist.h>
-#endif
+#include <boost/container/slist.hpp>
 
 #include <gtkmm/box.h>
 #include <gtkmm/window.h>
@@ -116,7 +111,7 @@ class ConnectionEditor : public ArdourDi
 	Gtk::Button add_port_button;
 
 	Glib::Mutex port_display_lock;
-	slist<Gtk::ScrolledWindow *> port_displays;
+	boost::container::slist<Gtk::ScrolledWindow *> port_displays;
 
 	Gtk::Button ok_button;
 	Gtk::Button cancel_button;
