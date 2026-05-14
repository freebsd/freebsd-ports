--- 3rdparty/fmt/include/fmt/format.h.orig	2025-06-29 19:47:12 UTC
+++ 3rdparty/fmt/include/fmt/format.h
@@ -44,6 +44,7 @@
 #  include <cmath>    // std::signbit
 #  include <cstddef>  // std::byte
 #  include <cstdint>  // uint32_t
+#  include <cstdlib>  // malloc(), free()
 #  include <cstring>  // std::memcpy
 #  include <limits>   // std::numeric_limits
 #  include <new>      // std::bad_alloc
