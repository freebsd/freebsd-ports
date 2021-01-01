--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2019-03-15 06:42:01 UTC
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -13,6 +13,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <iterator>
 #include <utility>
 
