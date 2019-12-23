--- include/spdlog/details/thread_pool-inl.h.orig	2019-12-23 05:00:13 UTC
+++ include/spdlog/details/thread_pool-inl.h
@@ -3,6 +3,8 @@
 
 #pragma once
 
+#include <cassert>
+
 #ifndef SPDLOG_HEADER_ONLY
 #include "spdlog/details/thread_pool.h"
 #endif
