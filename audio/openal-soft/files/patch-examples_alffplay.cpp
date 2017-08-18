--- examples/alffplay.cpp.orig	2017-07-23 04:34:58 UTC
+++ examples/alffplay.cpp
@@ -16,6 +16,7 @@
 #include <atomic>
 #include <mutex>
 #include <deque>
+#include <array>
 
 extern "C" {
 #include "libavcodec/avcodec.h"
