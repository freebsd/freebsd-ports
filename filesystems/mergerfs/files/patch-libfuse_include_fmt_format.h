--- libfuse/include/fmt/format.h.orig	2025-11-18 14:35:27 UTC
+++ libfuse/include/fmt/format.h
@@ -42,6 +42,7 @@
 
 #ifndef FMT_MODULE
 #  include <cmath>    // std::signbit
+#  include <cstdlib>  // std::malloc, std::free
 #  include <cstddef>  // std::byte
 #  include <cstdint>  // uint32_t
 #  include <cstring>  // std::memcpy
