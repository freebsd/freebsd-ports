--- lib/url.c.old	Wed Nov 27 17:22:24 2002
+++ lib/url.c	Wed Nov 27 17:23:29 2002
@@ -288,6 +288,10 @@
   
   data->set.proxytype = CURLPROXY_HTTP; /* defaults to HTTP proxy */
 
+#if defined(__FreeBSD_version)
+  data->set.no_signal = TRUE; /* different handling of signals and threads */
+#endif /* __FreeBSD_version */
+
   /* create an array with connection data struct pointers */
   data->state.numconnects = 5; /* hard-coded right now */
   data->state.connects = (struct connectdata **)
