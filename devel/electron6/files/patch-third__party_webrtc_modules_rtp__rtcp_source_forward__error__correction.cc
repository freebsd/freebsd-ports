--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2019-09-10 11:17:43 UTC
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -12,6 +12,7 @@
 
 #include <string.h>
 #include <algorithm>
+#include <cstdlib>
 #include <utility>
 
 #include "absl/algorithm/container.h"
