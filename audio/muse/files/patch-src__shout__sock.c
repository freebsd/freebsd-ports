--- src/shout/sock.c.orig	Tue Mar 30 01:04:27 2004
+++ src/shout/sock.c	Mon Apr 19 23:32:09 2004
@@ -336,7 +336,11 @@
     int rc = SOCK_ERROR;
     va_list ap_retry;
 
+#if (defined(__FreeBSD__) && __FreeBSD__ < 5)
+    ap_retry = ap;
+#else
     va_copy (ap_retry, ap);
+#endif
 
     len = vsnprintf (buff, sizeof (buffer), fmt, ap);
 
