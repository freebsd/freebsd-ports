--- thread_pthread.c.orig	2016-04-15 16:07:07 UTC
+++ thread_pthread.c
@@ -1154,7 +1154,7 @@ native_sleep(rb_thread_t *th, struct tim
 }
 
 #ifdef USE_UBF_LIST
-static LIST_HEAD(ubf_list_head);
+static CCAN_LIST_HEAD(ubf_list_head);
 
 /* The thread 'th' is registered to be trying unblock. */
 static void
