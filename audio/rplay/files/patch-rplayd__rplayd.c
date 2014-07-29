--- rplayd/rplayd.c.orig	Wed Mar 10 16:58:04 1999
+++ rplayd/rplayd.c	Fri Jan 31 02:12:40 2003
@@ -421,10 +421,9 @@
     /* Fork */
     if (do_fork)
     {
-	int pid = fork();
-	if (pid != 0)
-	{
-	    exit(0);
+	if (daemon(1, 1) < 0) {
+	    report(REPORT_ERROR, "daemon: %s\n", sys_err_str(errno));
+	    done(1);
 	}
     }
 
