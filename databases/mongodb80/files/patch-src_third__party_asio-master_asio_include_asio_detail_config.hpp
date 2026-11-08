--- src/third_party/asio-master/asio/include/asio/detail/config.hpp.orig	2026-09-29 00:00:00 UTC
+++ src/third_party/asio-master/asio/include/asio/detail/config.hpp
@@ -881,12 +881,15 @@
 #if !defined(ASIO_HAS_STD_INVOKE_RESULT)
 # if !defined(ASIO_DISABLE_STD_INVOKE_RESULT)
+#  if defined(__FreeBSD__) && (__cplusplus >= 201703)
+#   define ASIO_HAS_STD_INVOKE_RESULT 1
+#  endif // defined(__FreeBSD__) && (__cplusplus >= 201703)
 #  if defined(ASIO_MSVC)
 #   if (_MSC_VER >= 1911 && _MSVC_LANG >= 201703)
 #    define ASIO_HAS_STD_INVOKE_RESULT 1
 #   endif // (_MSC_VER >= 1911 && _MSVC_LANG >= 201703)
 #  endif // defined(ASIO_MSVC)
 # endif // !defined(ASIO_DISABLE_STD_INVOKE_RESULT)
 #endif // !defined(ASIO_HAS_STD_INVOKE_RESULT)
 
 // Windows App target. Windows but with a limited API.
 #if !defined(ASIO_WINDOWS_APP)
