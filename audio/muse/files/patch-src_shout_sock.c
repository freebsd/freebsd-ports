--- src/shout/sock.c.orig	2004-03-29 16:04:27 UTC
+++ src/shout/sock.c
@@ -336,7 +336,11 @@ int sock_write_fmt(sock_t sock, const ch
     int rc = SOCK_ERROR;
     va_list ap_retry;
 
+#if (defined(__FreeBSD__) && __FreeBSD__ < 5)
+    ap_retry = ap;
+#else
     va_copy (ap_retry, ap);
+#endif
 
     len = vsnprintf (buff, sizeof (buffer), fmt, ap);
 
