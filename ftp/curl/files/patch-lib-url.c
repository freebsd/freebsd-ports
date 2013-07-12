Description: Different handling of signals and threads.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-12-18

--- lib/url.c.orig	2012-01-23 23:31:30.000000000 +0800
+++ lib/url.c	2012-02-26 17:52:21.937920303 +0800
@@ -797,6 +797,10 @@
     data->progress.flags |= PGRS_HIDE;
     data->state.current_speed = -1; /* init to negative == impossible */
 
+#if defined(__FreeBSD_version)
+    data->set.no_signal = TRUE; /* different handling of signals and threads */
+#endif /* __FreeBSD_version */
+
     data->wildcard.state = CURLWC_INIT;
     data->wildcard.filelist = NULL;
     data->set.fnmatch = ZERO_NULL;
