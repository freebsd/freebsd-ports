--- src/c4/std/string_fwd.hpp.orig	2025-04-10 19:49:39 UTC
+++ src/c4/std/string_fwd.hpp
@@ -14,7 +14,7 @@
 // forward declarations for std::string
 #if defined(__GLIBCXX__) || defined(__GLIBCPP__)
 #include <bits/stringfwd.h>  // use the fwd header in glibcxx
-#elif defined(_LIBCPP_VERSION) || defined(__APPLE_CC__)
+#elif defined(_LIBCPP_VERSION) || defined(__APPLE_CC__) || __cplusplus > 199711L
 #include <iosfwd>  // use the fwd header in stdlibc++
 #elif defined(_MSC_VER)
 #include "c4/error.hpp"
