--- glib/glibmm/date.cc.orig	Sun Apr 22 12:28:36 2007
+++ glib/glibmm/date.cc	Sun Apr 22 12:28:48 2007
@@ -73,7 +73,7 @@
 
 
 #ifndef GLIBMM_DISABLE_DEPRECATED
-
+#if GLIB_SIZEOF_LONG != 4 && !defined(__alpha__)
 
 //Avoid a build problem in the case that time_t is equivalent to guint32 (GTime is also guint32)
 //That would make the set_time() method overload impossible.
@@ -84,7 +84,7 @@
   g_date_set_time(&gobject_, time);
 }
 #endif //GLIBMM_HAVE_C_STD_TIME_T_IS_NOT_INT32
-
+#endif
 #endif // GLIBMM_DISABLE_DEPRECATED
 
 
