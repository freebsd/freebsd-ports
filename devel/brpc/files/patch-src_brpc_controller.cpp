--- src/brpc/controller.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/brpc/controller.cpp
@@ -1577,7 +1577,7 @@ void Controller::CallAfterRpcResp(const google::protob
     }
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 typedef sig_t SignalHandler;
 #else
 typedef sighandler_t SignalHandler;
