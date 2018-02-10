--- devcfg.c.orig	2017-10-23 12:43:23 UTC
+++ devcfg.c
@@ -144,7 +144,7 @@ get_rate_from_baud_rate(int baud_rate, int *val, int c
 }
 
 #ifdef USE_UUCP_LOCKING
-static char *uucp_lck_dir = "/var/lock/";
+static char *uucp_lck_dir = "/var/spool/lock/";
 static char *dev_prefix = "/dev/";
 
 static int
