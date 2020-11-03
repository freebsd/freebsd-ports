--- src/php/ext/grpc/completion_queue.h.orig	2020-10-31 11:47:58 UTC
+++ src/php/ext/grpc/completion_queue.h
@@ -23,6 +23,10 @@
 
 #include <grpc/grpc.h>
 
+#if PHP_MAJOR_VERSION >= 8
+#define TSRMLS_D
+#endif
+
 /* The global completion queue for all operations */
 extern grpc_completion_queue *completion_queue;
 
