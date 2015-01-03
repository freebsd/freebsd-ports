--- devcfg.c.orig	2014-12-28 21:15:39.000000000 +0200
+++ devcfg.c	2014-12-28 21:18:04.000000000 +0200
@@ -31,7 +31,7 @@
 #include <signal.h>
 #include <errno.h>
 #include <syslog.h>
-#include <linux/serial.h>
+#include <sys/serial.h>
 
 #include "ser2net.h"
 #include "selector.h"
@@ -133,7 +133,7 @@ get_rate_from_baud_rate(int baud_rate, i
 }
 
 #ifdef USE_UUCP_LOCKING
-static char *uucp_lck_dir = "/var/lock";
+static char *uucp_lck_dir = "/var/spool/lock";
 
 static int
 uucp_fname_lock_size(char *devname)
