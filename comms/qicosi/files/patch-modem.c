--- src/modem.c.orig	Sat Apr  1 01:23:35 2006
+++ src/modem.c	Sat Apr  1 01:24:39 2006
@@ -314,7 +314,7 @@
 
 static int modem_get_str(char *buf, size_t nbytes, int timeout)
 {
-    timer_t tout = timer_set( timeout );
+    time_t tout = timer_set( timeout );
     int rc = ERROR, ch = 0, ptr = 0;
 
     buf[0] = '\0';
