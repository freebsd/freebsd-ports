--- dataxfer.c.orig	Thu Dec  7 20:09:25 2006
+++ dataxfer.c	Thu Dec  7 20:10:33 2006
@@ -53,7 +53,7 @@
 #endif /* HAVE_TCPD_H */
 
 #ifdef USE_UUCP_LOCKING
-static char *uucp_lck_dir = "/var/lock";
+static char *uucp_lck_dir = "/var/spool/lock";
 #ifndef HAVE_TCPD_H
 static char *progname = "ser2net";
 #endif
