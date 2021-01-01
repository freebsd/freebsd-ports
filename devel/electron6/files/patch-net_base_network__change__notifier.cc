--- net/base/network_change_notifier.cc.orig	2019-09-10 11:14:08 UTC
+++ net/base/network_change_notifier.cc
@@ -225,7 +225,6 @@ NetworkChangeNotifier* NetworkChangeNotifier::Create()
 #elif defined(OS_FUCHSIA)
   return new NetworkChangeNotifierFuchsia(0 /* required_features */);
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
