--- src/dparent.c.orig	2008-12-02 23:17:13 UTC
+++ src/dparent.c
@@ -308,6 +308,9 @@ static void dcc_save_pid(pid_t pid)
  **/
 void dcc_remove_pid(void)
 {
+    /* distcc user, we are running as, cannot delete files in /var/run
+     */
+#if 0
     if (!arg_pid_file)
         return;
 
@@ -315,6 +318,7 @@ void dcc_remove_pid(void)
         rs_log_warning("failed to remove pid file %s: %s",
                        arg_pid_file, strerror(errno));
     }
+#endif
 }
 
 
