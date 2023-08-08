--- libwzd-core/wzd_libmain.c.orig	2023-02-11 10:43:55 UTC
+++ libwzd-core/wzd_libmain.c
@@ -285,7 +285,6 @@ void context_init(wzd_context_t * context)
   context->datafd = -1;
   context->pasvsock = -1;
   context->userid = (unsigned int)-1;
-  context->thread_id = (unsigned long)-1;
   context->state = STATE_UNKNOWN;
   context->datamode = DATA_PORT;
   context->current_action.current_file = -1;
