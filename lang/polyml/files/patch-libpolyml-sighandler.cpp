--- libpolyml/sighandler.cpp.orig	2008-02-28 00:20:51.000000000 +1100
+++ libpolyml/sighandler.cpp	2008-07-27 21:26:41.000000000 +1000
@@ -357,7 +357,7 @@
     struct sigaltstack ex_stack;
 #endif
     memset(&ex_stack, 0, sizeof(ex_stack));
-    ex_stack.ss_sp    = taskData->signalStack;
+    ex_stack.ss_sp    = (char *)taskData->signalStack;
     ex_stack.ss_size  = SIGSTKSZ;
     ex_stack.ss_flags = 0; /* not SS_DISABLE */
     int sigaltstack_result = sigaltstack(&ex_stack, NULL);
@@ -526,7 +526,7 @@
     pthread_attr_init(&attrs);
     pthread_attr_setdetachstate(&attrs, PTHREAD_CREATE_DETACHED);
 #ifdef PTHREAD_STACK_MIN
-    pthread_attr_setstacksize(&attrs, PTHREAD_STACK_MIN); // Only small stack.
+    pthread_attr_setstacksize(&attrs, PTHREAD_STACK_MIN + 100); // Only small stack.
 #endif
     pthread_create(&detectionThreadId, &attrs, SignalDetectionThread, 0);
     pthread_attr_destroy(&attrs);
