--- gnats/misc.c.orig	Sun Nov 14 17:59:15 2004
+++ gnats/misc.c	Sun Nov 14 17:56:58 2004
@@ -79,7 +79,7 @@
     {
 #ifdef HAVE_SYSLOG_H
       if (log_method == SYSLOG)
-	syslog (severity, buf);
+	syslog (severity, "%s", buf);
       else
 #endif
       if (gnats_logfile != (FILE *) NULL)
