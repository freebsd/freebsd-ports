--- rplayd/rplayd.h.orig	Tue Dec 26 16:03:40 2006
+++ rplayd/rplayd.h	Tue Dec 26 16:03:44 2006
@@ -73,7 +73,6 @@
 extern fd_set read_mask;
 extern fd_set write_mask;
 extern int debug;
-extern int inetd;
 extern int rptp_timeout;
 extern char hostname[];
 extern char *hostaddr;
