--- src/daemon/gnuserv.c.orig	Mon Oct 20 01:54:32 2003
+++ src/daemon/gnuserv.c	Tue Nov  4 15:22:38 2003
@@ -42,7 +42,7 @@
 #include <glibtop/gnuserv.h>
 
 #include <errno.h>
-#include <popt-gnome.h>
+#include <popt.h>
 
 #include "daemon.h"
 
@@ -202,6 +202,12 @@
 	
 	if (auth_data_len < 1 || auth_data_len > sizeof(buf)) {
 	    syslog_message(LOG_WARNING, "Invalid data length supplied by client");
+	    return FALSE;
+	}
+
+	if (auth_data_len < 1 || auth_data_len > sizeof(buf)) {
+	    syslog_message(LOG_WARNING,
+			   "Invalid data length supplied by client");
 	    return FALSE;
 	}
 
