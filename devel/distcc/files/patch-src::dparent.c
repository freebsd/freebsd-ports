--- src/dparent.c.orig	Tue Jun 25 15:58:35 2002
+++ src/dparent.c	Tue Jun 25 15:58:48 2002
@@ -126,7 +126,7 @@
 
     memset(&act_exited, 0, sizeof act_exited);
     act_exited.sa_handler = dcc_child_exited;
-    act_exited.sa_flags = SA_NOCLDSTOP;
+    act_exited.sa_flags = SA_NOCLDSTOP|SA_RESTART;
 
     if (sigaction(SIGTERM, &act_catch, NULL)
         || sigaction(SIGHUP, &act_catch, NULL)
