--- ./libtest/test.cc.orig	2012-01-27 17:12:33.000000000 -0500
+++ ./libtest/test.cc	2012-01-27 17:14:02.000000000 -0500
@@ -113,7 +113,10 @@
     return EXIT_FAILURE;
   }
 
-  assert(sigignore(SIGPIPE) == 0);
+  struct sigaction ignore_action;
+  ignore_action.sa_handler = SIG_IGN;
+  ignore_action.sa_flags = SA_RESTART;
+  assert(sigaction(SIGPIPE, &ignore_action, NULL) == 0);
 
   libtest::SignalThread signal;
   if (not signal.setup())
