--- net/filter/zstd_source_stream.cc.orig	2023-10-19 19:58:28 UTC
+++ net/filter/zstd_source_stream.cc
@@ -6,6 +6,7 @@
 
 #include <algorithm>
 #include <utility>
+#include <unordered_map>
 
 #define ZSTD_STATIC_LINKING_ONLY
 
