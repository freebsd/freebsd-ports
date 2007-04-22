--- glib/glibmm/date.h.orig	Sun Apr 22 12:29:49 2007
+++ glib/glibmm/date.h	Sun Apr 22 12:30:39 2007
@@ -121,7 +121,7 @@
 
 
   #ifndef GLIBMM_DISABLE_DEPRECATED
-
+#if GLIB_SIZEOF_LONG != 4 && !defined(__alpha__)
   
   //Avoid a build problem in the case that time_t is equivalent to guint32 (GTime is also guint32)
   //That would make the set_time() method overload impossible.
@@ -134,7 +134,7 @@
    */
   void set_time(GTime time);
   #endif //GLIBMM_HAVE_C_STD_TIME_T_IS_NOT_INT32
-
+#endif
   #endif // GLIBMM_DISABLE_DEPRECATED
 
 
