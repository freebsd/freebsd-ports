--- boost/asio/detail/config.hpp.orig	2026-08-05 17:09:07 UTC
+++ boost/asio/detail/config.hpp
@@ -537,7 +537,9 @@
 #  elif defined(__GNUC__)
 #   if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #    if (__cplusplus >= 201402)
+#    if __has_include(<experimental/string_view>)
 #     define BOOST_ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW 1
+#    endif // __has_include(<experimental/string_view>)
 #    endif // (__cplusplus >= 201402)
 #   endif // ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #  endif // defined(__GNUC__)
