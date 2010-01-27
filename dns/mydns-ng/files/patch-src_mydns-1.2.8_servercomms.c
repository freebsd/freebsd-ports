--- src/mydns/servercomms.c.orig	2010-01-26 05:26:08.000000000 +0800
+++ src/mydns/servercomms.c	2010-01-26 05:26:45.000000000 +0800
@@ -406,7 +406,12 @@
     DebugX("servercomms", 1, _("%s: Server comms tick - master has not pinged for %d seconds"), desctask(t),
 	   lastseen);
 #endif
-    named_shutdown(0);
+    if (abs(lastseen) > 10*KEEPALIVE) {
+      Notice(_("Possible clock jump: master has not pinged for %d seconds"), lastseen);
+    } else {
+      Notice(_("Client shutdown: %s: master has not pinged for %d seconds"), desctask(t), lastseen);
+      named_shutdown(0);
+    }
   }
 
   return TASK_CONTINUE;
