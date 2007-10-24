--- glib/glibmm/date.cc.orig	Sun May  6 00:19:51 2007
+++ glib/glibmm/date.cc	Sun May  6 00:21:36 2007
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
 
 
