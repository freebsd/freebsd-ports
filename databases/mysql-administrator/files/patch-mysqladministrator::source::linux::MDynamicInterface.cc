--- mysqladministrator/source/linux/MDynamicInterface.cc.orig	Tue Feb 24 03:46:44 2004
+++ mysqladministrator/source/linux/MDynamicInterface.cc	Tue Feb 24 03:51:45 2004
@@ -21,7 +21,10 @@
 #include <ctype.h>
 
 #include <list>
-
+#if defined (__FreeBSD__)
+#include <errno.h>
+#include <sys/param.h>
+#endif
 
 MDynamicInterface::MDynamicInterface(Gtk::Notebook *top_note,
                                      const Glib::RefPtr<Gdk::Pixbuf> &icon,
@@ -721,7 +724,11 @@
       else if (widget->default_value)
         value= (char*)widget->default_value;
       else
+#if defined (__FreeBSD__) && __FreeBSD_version < 500000
+        value="";
+#else
         value.clear();
+#endif
       set_option_value((char*)widget->id, value);      
     }
   }
