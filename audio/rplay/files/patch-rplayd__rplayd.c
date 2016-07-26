--- rplayd/rplayd.c.orig	1999-03-10 07:58:04 UTC
+++ rplayd/rplayd.c
@@ -421,10 +421,9 @@ main(argc, argv)
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
 
