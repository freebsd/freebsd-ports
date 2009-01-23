diff -urN -x .svn ../../vendor/curl/lib/url.c ./lib/url.c
--- ../../vendor/curl/lib/url.c	2008-11-03 18:24:56.000000000 +0200
+++ ./lib/url.c	2009-01-21 16:12:49.000000000 +0200
@@ -719,6 +719,10 @@
     data->set.httpauth = CURLAUTH_BASIC;  /* defaults to basic */
     data->set.proxyauth = CURLAUTH_BASIC; /* defaults to basic */
 
+#if defined(__FreeBSD_version)
+    data->set.no_signal = TRUE; /* different handling of signals and threads */
+#endif /* __FreeBSD_version */
+
     /* This no longer creates a connection cache here. It is instead made on
        the first call to curl_easy_perform() or when the handle is added to a
        multi stack. */
