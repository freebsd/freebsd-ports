--- gconf/gconfd.c.orig	2008-05-10 08:34:31.000000000 -0400
+++ gconf/gconfd.c	2008-08-16 14:08:05.000000000 -0400
@@ -123,12 +123,6 @@ static void gconf_handle_segv (int signu
 
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
@@ -408,6 +402,18 @@ gconf_server_load_sources(void)
     }
 }
 
+static void
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
 /*
  * Signal handlers should not log debug messages as this code is non-reentrant.
  * Please avoid calling gconf_log in this function.
@@ -471,8 +477,7 @@ signal_handler (int signo)
   case SIGHUP:
     --in_fatal;
 
-    /* reload sources during next periodic_cleanup() */
-    need_db_reload = TRUE;
+    reload_db ();
     break;
 #endif
 
@@ -828,17 +833,6 @@ static gboolean need_log_cleanup = FALSE
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
   
   gconf_log (GCL_DEBUG, "Performing periodic cleanup, expiring cache cruft");
   
