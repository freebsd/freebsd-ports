--- src/c4/std/string_fwd.hpp.orig	2022-01-06 01:20:26 UTC
+++ src/c4/std/string_fwd.hpp
@@ -14,7 +14,7 @@
 // forward declarations for std::string
 #if defined(__GLIBCXX__) || defined(__GLIBCPP__)
 #include <bits/stringfwd.h>  // use the fwd header in glibcxx
-#elif defined(_LIBCPP_VERSION) || defined(__APPLE_CC__)
+#elif defined(_LIBCPP_VERSION) || defined(__APPLE_CC__) || __cplusplus > 199711L
 #include <iosfwd>  // use the fwd header in stdlibc++
 #elif defined(_MSC_VER)
 //! @todo is there a fwd header in msvc?
