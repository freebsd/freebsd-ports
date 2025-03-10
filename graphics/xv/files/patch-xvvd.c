--- src/xvvd.c.orig	2024-08-12 21:10:49 UTC
+++ src/xvvd.c
@@ -1157,6 +1157,8 @@ static void HUPhandler(XtPointer dummy, XtSignalId* Id
     unblock_signal(SIGHUP, mask);
 }
 
+int InSignal = 0;
+
 static void vd_handler(int sig)
 {
     UsedSignal = sig;
@@ -1170,6 +1172,7 @@ static void INThandler(XtPointer dummy, XtSignalId* Id
 
     block_signal(UsedSignal);
 
+    InSignal = 1;
     Quit(1); /*exit(1);*/
 }
 
