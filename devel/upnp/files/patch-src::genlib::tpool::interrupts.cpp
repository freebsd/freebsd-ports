--- src/genlib/tpool/interrupts.cpp.orig	Fri Jun 15 08:22:16 2001
+++ src/genlib/tpool/interrupts.cpp	Sat Aug  3 16:29:39 2002
@@ -82,7 +82,7 @@
     int code;
 
     newset.sa_handler = signal_handler_alpha;
-    newset.sa_flags = SA_NOMASK;
+    newset.sa_flags = SA_NODEFER;
     code = sigaction( signalNum, &newset, &g_OldAction );
     if ( code < 0 )
     {
