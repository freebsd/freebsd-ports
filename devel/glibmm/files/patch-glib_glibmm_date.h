--- glib/glibmm/date.h.orig	Sun May  6 00:22:03 2007
+++ glib/glibmm/date.h	Sun May  6 00:22:31 2007
@@ -120,6 +120,7 @@ enum DMY
   void set_parse (const Glib::ustring& str);
 
   #ifndef GLIBMM_DISABLE_DEPRECATED
+#if GLIB_SIZEOF_LONG != 4 && !defined(__alpha__)
 
   /** Sets the value of a date from a GTime (time_t) value. 
    *
@@ -128,6 +129,7 @@ enum DMY
    * @deprecated Please use set_time(time_t) or set_time(const GTimeVal&).
    */
   void set_time(GTime time);
+#endif
   #endif // GLIBMM_DISABLE_DEPRECATED
 
 
