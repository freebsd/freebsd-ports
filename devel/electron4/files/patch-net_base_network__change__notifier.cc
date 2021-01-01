--- net/base/network_change_notifier.cc.orig	2019-03-15 06:37:29 UTC
+++ net/base/network_change_notifier.cc
@@ -217,7 +217,6 @@ NetworkChangeNotifier* NetworkChangeNotifier::Create()
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
