--- net/base/address_tracker_linux_unittest.cc.orig	2019-09-10 11:14:08 UTC
+++ net/base/address_tracker_linux_unittest.cc
@@ -4,7 +4,11 @@
 
 #include "net/base/address_tracker_linux.h"
 
+#if defined(__linux__)
 #include <linux/if.h>
+#else
+#include <net/if.h>
+#endif
 
 #include <memory>
 #include <unordered_set>
