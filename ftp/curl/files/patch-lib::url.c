--- lib/url.c.orig	Wed Jun  2 14:45:18 2004
+++ lib/url.c	Wed Jun  2 14:45:40 2004
@@ -329,6 +329,10 @@
     data->set.httpauth = CURLAUTH_BASIC;  /* defaults to basic */
     data->set.proxyauth = CURLAUTH_BASIC; /* defaults to basic */
 
+#if defined(__FreeBSD_version)
+    data->set.no_signal = TRUE; /* different handling of signals and threads */
+#endif /* __FreeBSD_version */
+
     /* create an array with connection data struct pointers */
     data->state.numconnects = 5; /* hard-coded right now */
     data->state.connects = (struct connectdata **)
