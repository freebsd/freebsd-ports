--- xvvd.c.orig	2007-04-16 06:30:19.000000000 +0200
+++ xvvd.c	2010-02-11 15:23:41.000000000 +0100
@@ -1060,6 +1060,8 @@
 #endif
 }
 
+int InSignal = 0;
+
 void vd_handler(sig)
 int sig;
 {
@@ -1068,7 +1070,7 @@
 #else
     sigblock(sigmask(sig));
 #endif
-
+    InSignal = 1;
     Quit(1); /*exit(1);*/
 }
 
