--- glib/glibmm/date.cc.orig	Mon Feb  6 00:50:58 2006
+++ glib/glibmm/date.cc	Mon Feb  6 00:51:32 2006
@@ -72,12 +72,14 @@ void Date::set_parse(const Glib::ustring
 }
 
 #ifndef GLIBMM_DISABLE_DEPRECATED
+#if GLIB_SIZEOF_LONG != 4 && !defined(__alpha__)
 
 void Date::set_time(GTime time)
 {
   //This method, and the C function that it wraps, are deprecated.
   g_date_set_time(&gobject_, time);
 }
+#endif
 #endif // GLIBMM_DISABLE_DEPRECATED
 
 
