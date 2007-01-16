diff -u -r1.1 pidfile.h
--- include/pidfile.h	11 Jan 2007 21:36:06 -0000	1.1
+++ include/pidfile.h	13 Jan 2007 04:13:10 -0000
@@ -30,7 +30,7 @@
 #define PR_PIDFILE_H
 
 /* For internal use only. */
-int pidfile_remove(void);
-void pidfile_write(void);
+int pr_pidfile_remove(void);
+void pr_pidfile_write(void);
 
 #endif /* PR_PIDFILE_H */
Index: src/main.c
===================================================================
RCS file: /cvsroot/proftp/proftpd/src/main.c,v
retrieving revision 1.298
diff -u -r1.298 main.c
--- src/main.c	11 Jan 2007 21:36:06 -0000	1.298
+++ src/main.c	13 Jan 2007 04:13:10 -0000
@@ -261,7 +261,7 @@
     PRIVS_ROOT
     pr_delete_scoreboard();
     if (!nodaemon)
-      pidfile_remove();
+      pr_pidfile_remove();
     PRIVS_RELINQUISH
   }
 
@@ -1760,7 +1760,7 @@
     /* Do not need the pidfile any longer. */
     if (is_standalone &&
         !nodaemon)
-      pidfile_remove();
+      pr_pidfile_remove();
 
     /* Run any exit handlers registered in the master process here, so that
      * they may have the benefit of root privs.  More than likely these
@@ -2261,7 +2261,7 @@
   pr_log_pri(PR_LOG_NOTICE, "ProFTPD %s (built %s) standalone mode STARTUP",
     PROFTPD_VERSION_TEXT " " PR_STATUS, BUILD_STAMP);
 
-  pidfile_write();
+  pr_pidfile_write();
   daemon_loop();
 }
 
Index: src/pidfile.c
===================================================================
RCS file: /cvsroot/proftp/proftpd/src/pidfile.c,v
retrieving revision 1.2
diff -u -r1.2 pidfile.c
--- src/pidfile.c	12 Jan 2007 05:40:37 -0000	1.2
+++ src/pidfile.c	13 Jan 2007 04:13:10 -0000
@@ -32,7 +32,7 @@
 
 static const char *pidfile_path = PR_PID_FILE_PATH;
 
-void pidfile_write(void) {
+void pr_pidfile_write(void) {
   FILE *fh = NULL;
 
   pidfile_path = get_param_ptr(main_server->conf, "PidFile", FALSE);
@@ -56,6 +56,6 @@
   }
 }
 
-int pidfile_remove(void) {
+int pr_pidfile_remove(void) {
   return unlink(pidfile_path);
 }
