--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2021-01-07 00:39:37 UTC
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -13,6 +13,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <utility>
 
 #include "absl/algorithm/container.h"
