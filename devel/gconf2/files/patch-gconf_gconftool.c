--- gconf/gconftool.c.orig	Fri May  5 12:36:01 2006
+++ gconf/gconftool.c	Fri May  5 12:39:29 2006
@@ -3724,6 +3724,8 @@
 static int
 do_makefile_install(GConfEngine* conf, const gchar** args, gboolean unload)
 {
+  int sync_result;
+
   if (args == NULL)
     {
       g_printerr (_("Must specify some schema files to install\n"));
@@ -3738,7 +3740,15 @@
       ++args;
     }
 
-  return do_sync (conf);
+  sync_result = do_sync (conf);
+
+  /*
+   * Send all the gconfd-2 processes a SIGHUP so that they reload the
+   * databases and pick up the added/removed schemas.
+   */
+  system("/usr/bin/killall -SIGHUP gconfd-2 >/dev/null 2>&1");
+
+  return sync_result;
 }
 
 typedef enum {
