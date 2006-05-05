--- gconf/gconfd.c.orig	Fri May  5 12:40:23 2006
+++ gconf/gconfd.c	Fri May  5 12:41:43 2006
@@ -124,12 +124,6 @@
 
 static gboolean in_shutdown = FALSE;
 
-/*
- * Flag indicating we received a SIGHUP and we should reaload
- * all sources during the next periodic_cleanup()
- */
-static gboolean need_db_reload = FALSE;
-
 /* 
  * CORBA goo
  */
@@ -410,6 +404,18 @@
 }
 
 static void
+reload_db (void)
+{
+  gconf_log (GCL_INFO, _("SIGHUP received, reloading all databases"));
+
+  logfile_save ();
+  shutdown_databases ();
+  init_databases ();
+  gconf_server_load_sources ();
+  logfile_read ();
+}
+
+static void
 signal_handler (int signo)
 {
   static gint in_fatal = 0;
@@ -482,8 +488,8 @@
   case SIGHUP:
     --in_fatal;
 
-    /* reload sources during next periodic_cleanup() */
-    need_db_reload = TRUE;
+    /* reload sources immediately */
+    reload_db ();
     break;
 #endif
 
@@ -864,18 +870,6 @@
 static gboolean
 periodic_cleanup_timeout(gpointer data)
 {  
-  if (need_db_reload)
-    {
-      gconf_log (GCL_INFO, _("SIGHUP received, reloading all databases"));
-
-      need_db_reload = FALSE;
-      logfile_save ();
-      shutdown_databases ();
-      init_databases ();
-      gconf_server_load_sources ();
-      logfile_read ();
-    }
-  
   gconf_log (GCL_DEBUG, "Performing periodic cleanup, expiring cache cruft");
   
   drop_old_clients ();
