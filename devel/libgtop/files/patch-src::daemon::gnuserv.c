--- src/daemon/gnuserv.c.orig	Thu Nov 29 08:58:40 2001
+++ src/daemon/gnuserv.c	Thu Nov 29 08:58:17 2001
@@ -200,6 +200,12 @@
 
 	auth_data_len = atoi (buf);
 
+	if (auth_data_len < 1 || auth_data_len > sizeof(buf)) {
+	    syslog_message(LOG_WARNING,
+			   "Invalid data length supplied by client");
+	    return FALSE;
+	}
+
 	if (timed_read (fd, buf, auth_data_len, AUTH_TIMEOUT, 0) != auth_data_len)
 	    return FALSE;
 
