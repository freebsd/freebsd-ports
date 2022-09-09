--- source/searcher.hpp.orig	2022-08-27 09:05:01 UTC
+++ source/searcher.hpp
@@ -18,7 +18,9 @@
 #define FMT_HEADER_ONLY 1
 #include <fmt/color.h>
 #include <fmt/core.h>
+#if defined(__x86_64__) || defined (__i386__)
 #include <immintrin.h>
+#endif
 #include <sse2_strstr.hpp>
 #include <thread_pool.hpp>
 
