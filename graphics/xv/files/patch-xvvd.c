--- src/xvvd.c.orig	2023-07-17 01:25:42 UTC
+++ src/xvvd.c
@@ -1072,6 +1072,8 @@ static void HUPhandler(XtPointer dummy, XtSignalId* Id
 #endif
 }
 
+int InSignal = 0;
+
 static void vd_handler(int sig)
 {
     UsedSignal = sig;
@@ -1085,7 +1087,7 @@ static void INThandler(XtPointer dummy, XtSignalId* Id
 #else
     sigblock(sigmask(UsedSignal));
 #endif
-
+    InSignal = 1;
     Quit(1); /*exit(1);*/
 }
 
