--- gconf/gconftool.c.orig	Fri Mar  2 17:10:13 2007
+++ gconf/gconftool.c	Tue Mar  6 12:01:04 2007
@@ -3781,6 +3781,13 @@ do_makefile_install(GConfEngine* conf, c
     }
 
   retval |= do_sync (conf);
+
+  /*
+   * Send all the gconfd-2 processes a SIGHUP so that they reload the
+   * databases and pick up the added/removed schemas.
+   */
+  system("/usr/bin/killall -SIGHUP gconfd-2 >/dev/null 2>&1");
+
   return retval;
 }
 
