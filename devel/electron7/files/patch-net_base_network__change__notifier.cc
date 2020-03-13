--- net/base/network_change_notifier.cc.orig	2019-12-12 12:39:52 UTC
+++ net/base/network_change_notifier.cc
@@ -35,7 +35,7 @@
 #include "net/base/network_change_notifier_linux.h"
 #elif defined(OS_MACOSX)
 #include "net/base/network_change_notifier_mac.h"
-#elif defined(OS_CHROMEOS)
+#elif defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "net/base/network_change_notifier_posix.h"
 #elif defined(OS_FUCHSIA)
 #include "net/base/network_change_notifier_fuchsia.h"
@@ -224,7 +224,7 @@ std::unique_ptr<NetworkChangeNotifier> NetworkChangeNo
   // Android builds MUST use their own class factory.
   CHECK(false);
   return NULL;
-#elif defined(OS_CHROMEOS)
+#elif defined(OS_CHROMEOS) || defined(OS_BSD)
   return std::make_unique<NetworkChangeNotifierPosix>(CONNECTION_NONE,
                                                       SUBTYPE_NONE);
 #elif defined(OS_LINUX)
@@ -236,7 +236,6 @@ std::unique_ptr<NetworkChangeNotifier> NetworkChangeNo
   return std::make_unique<NetworkChangeNotifierFuchsia>(
       0 /* required_features */);
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
