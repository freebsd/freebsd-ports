--- audio.c.orig	Thu Aug 21 14:38:53 2003
+++ audio.c	Thu Feb  5 03:27:09 2004
@@ -10,6 +10,7 @@
 #include <errno.h>
 #include <signal.h>
 #include <pthread.h>
+#include <dlfcn.h>
 
 static arts_stream_t handle;
 
@@ -269,6 +270,7 @@
 int artsxmms_open(AFormat fmt, int rate, int nch)
 {
 	int err;
+	static int libstdcpp_preloaded = 0;
 
 	pthread_mutex_lock(&artsm);
 	/* Stop the arts initialization from complaining */
@@ -291,6 +293,20 @@
 
 	going = 1;
 	pthread_mutex_unlock(&artsm);
+
+	/*
+	 * This is a hack to prevent unloading of libstdc++
+	 * (required by arts libraries) in arts_free() but before
+	 * this thread is terminated. libstdc++ registers thread cleanup
+	 * handler and xmms crashes when this cleanup function is called
+	 * on thread termination.
+	 */
+	if (!libstdcpp_preloaded) {
+		if (dlopen("libstdc++.so", RTLD_NOW) != NULL)
+			libstdcpp_preloaded = 1;
+		else
+			fprintf(stderr, "Failed to preload libstdc++.so\n");
+	}
 	return 1;
 }
 
