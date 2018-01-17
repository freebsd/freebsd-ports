--- server/red-worker.c.orig	2017-09-21 11:05:07 UTC
+++ server/red-worker.c
@@ -28,6 +28,7 @@
 #include <unistd.h>
 #include <poll.h>
 #include <pthread.h>
+#include <pthread_np.h>
 #include <openssl/ssl.h>
 #include <inttypes.h>
 #include <glib.h>
@@ -52,6 +53,16 @@
 
 #define INF_EVENT_WAIT ~0
 
+int pthread_setname_np(pthread_t, const char *);
+
+
+int pthread_setname_np(pthread_t id, const char *name)
+{
+	/* this BSD function returns no error */
+	pthread_set_name_np(id, name);
+	return 0;
+}
+
 struct RedWorker {
     pthread_t thread;
     QXLInstance *qxl;
