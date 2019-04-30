--- 3rdparty/asio/include/asio/detail/config.hpp.orig	2019-04-24 05:00:38 UTC
+++ 3rdparty/asio/include/asio/detail/config.hpp
@@ -713,14 +713,12 @@
 #      define ASIO_HAS_STD_STRING_VIEW 1
 #     endif
 #    endif
-#    if !defined(ASIO_HAS_STD_STRING_VIEW) && __has_include(<experimental/string_view>)
+#    if !defined(ASIO_HAS_STD_STRING_VIEW) && __has_include(<string_view>)
 #     define ASIO_HAS_STD_STRING_VIEW 1
 #     if defined(__APPLE__)
 #      if ((__clang_major__ < 10) || ((__clang_major__ == 10) && (__clang_minor__ == 0) && (__clang_patchlevel__ < 1)))
 #        define ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW 1
 #       endif // clang < 10.0.1
-#      else // for non-Xcode Clang
-#        define ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW 1
 #      endif
 #    endif // __has_include(<experimental/string_view>)
 #   endif // (__cplusplus >= 201103)
