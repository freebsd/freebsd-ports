--- libpolyml/sighandler.cpp.orig	2008-04-05 16:03:20.000000000 +1100
+++ libpolyml/sighandler.cpp	2008-04-05 16:03:29.000000000 +1100
@@ -381,7 +381,7 @@
     struct sigaltstack ex_stack;
 #endif
     memset(&ex_stack, 0, sizeof(ex_stack));
-    ex_stack.ss_sp    = taskData->signalStack;
+    ex_stack.ss_sp    = (char *)taskData->signalStack;
     ex_stack.ss_size  = SIGSTKSZ;
     ex_stack.ss_flags = 0; /* not SS_DISABLE */
     int sigaltstack_result = sigaltstack(&ex_stack, NULL);
