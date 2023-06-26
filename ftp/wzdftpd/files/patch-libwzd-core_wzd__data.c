--- libwzd-core/wzd_data.c.orig	2023-06-26 15:01:55 UTC
+++ libwzd-core/wzd_data.c
@@ -529,7 +529,7 @@ int data_start_thread_retr(wzd_context_t * context)
   int ret;
 
   thread = malloc(sizeof(wzd_thread_t));
-  ret = wzd_thread_create(thread, NULL, do_local_retr, context);
+  ret = wzd_thread_create(thread, NULL, (void *(*)(void *))do_local_retr, context);
 
   context->transfer_thread = thread;
 
@@ -544,7 +544,7 @@ int data_start_thread_stor(wzd_context_t * context)
   int ret;
 
   thread = malloc(sizeof(wzd_thread_t));
-  ret = wzd_thread_create(thread, NULL, do_local_stor, context);
+  ret = wzd_thread_create(thread, NULL, (void *(*)(void *))do_local_stor, context);
 
   context->transfer_thread = thread;
 
