--- src/cl_enqueue.c.orig	2017-01-20 10:40:51 UTC
+++ src/cl_enqueue.c
@@ -29,6 +29,7 @@
 #include <string.h>
 #include <assert.h>
 #include <pthread.h>
+#include <sys/types.h>
 
 static cl_int
 cl_enqueue_read_buffer(enqueue_data *data, cl_int status)
