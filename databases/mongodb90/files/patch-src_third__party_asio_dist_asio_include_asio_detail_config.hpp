--- src/third_party/asio/dist/asio/include/asio/detail/config.hpp.orig	2026-09-29 00:00:00 UTC
+++ src/third_party/asio/dist/asio/include/asio/detail/config.hpp
@@ -560,6 +560,9 @@
 // Standard library has invoke_result (which supersedes result_of).
 #if !defined(ASIO_HAS_STD_INVOKE_RESULT)
 # if !defined(ASIO_DISABLE_STD_INVOKE_RESULT)
+#  if defined(__FreeBSD__) && (__cplusplus >= 201703)
+#   define ASIO_HAS_STD_INVOKE_RESULT 1
+#  endif // defined(__FreeBSD__) && (__cplusplus >= 201703)
 #  if defined(ASIO_MSVC)
 #   if (_MSC_VER >= 1911 && _MSVC_LANG >= 201703)
 #    define ASIO_HAS_STD_INVOKE_RESULT 1
