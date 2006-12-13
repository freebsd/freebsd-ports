--- lib/url.c.orig	Mon Oct 30 00:46:27 2006
+++ lib/url.c	Fri Dec  1 14:04:02 2006
@@ -542,6 +542,10 @@
     data->set.httpauth = CURLAUTH_BASIC;  /* defaults to basic */
     data->set.proxyauth = CURLAUTH_BASIC; /* defaults to basic */
 
+#if defined(__FreeBSD_version)
+    data->set.no_signal = TRUE; /* different handling of signals and threads */
+#endif /* __FreeBSD_version */
+
     /* This no longer creates a connection cache here. It is instead made on
        the first call to curl_easy_perform() or when the handle is added to a
        multi stack. */
