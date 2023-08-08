--- wzdftpd/wzd_ServerThread.c.orig	2023-02-11 11:33:03 UTC
+++ wzdftpd/wzd_ServerThread.c
@@ -934,7 +934,7 @@ static void server_login_accept(wzd_context_t * contex
     out_err(LEVEL_CRITICAL,"Unable to create thread\n");
     return;
   }
-  context->pid_child = (unsigned long)WZD_THREAD_VOID(&thread);
+  context->pid_child = (pthread_t)WZD_THREAD_VOID(&thread);
   wzd_thread_attr_destroy(&thread_attr); /* not needed anymore */
 }
 
@@ -1624,10 +1624,12 @@ void serverMainThreadCleanup(int retcode)
   {
     ListElmt * elmnt;
     wzd_context_t * loop_context;
+    wzd_thread_t child;
     for (elmnt=list_head(context_list); elmnt!=NULL; elmnt=list_next(elmnt))
     {
       if ((loop_context = list_data(elmnt))) {
-        wzd_thread_cancel(loop_context->pid_child);
+        child._t = loop_context->pid_child;
+        wzd_thread_cancel(&child);
 #ifdef WIN32
         /** \todo remove this when wzd_thread_cancel is implemented on windows */
         loop_context->exitclient = 1;
