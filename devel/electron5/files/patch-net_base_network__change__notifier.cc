--- net/base/network_change_notifier.cc.orig	2019-04-08 08:33:00 UTC
+++ net/base/network_change_notifier.cc
@@ -221,7 +221,6 @@ NetworkChangeNotifier* NetworkChangeNotifier::Create()
 #elif defined(OS_FUCHSIA)
   return new NetworkChangeNotifierFuchsia(0 /* required_features */);
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
