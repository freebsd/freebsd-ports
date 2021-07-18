--- net/dns/dns_config_service_posix_unittest.cc.orig	2021-01-07 00:36:38 UTC
+++ net/dns/dns_config_service_posix_unittest.cc
@@ -2,8 +2,6 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
-#include <resolv.h>
-
 #include <memory>
 
 #include "base/cancelable_callback.h"
