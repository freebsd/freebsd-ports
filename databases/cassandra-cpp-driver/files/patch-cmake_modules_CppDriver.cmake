--- cmake/modules/CppDriver.cmake.orig	2018-06-23 19:55:39 UTC
+++ cmake/modules/CppDriver.cmake
@@ -372,6 +372,8 @@ macro(CassUseLibuv)
 
   if (EXISTS "${LIBUV_INCLUDE_DIR}/uv-version.h")
     set(LIBUV_VERSION_HEADER_FILE "${LIBUV_INCLUDE_DIR}/uv-version.h")
+  elseif (EXISTS "${LIBUV_INCLUDE_DIR}/uv/version.h")
+    set(LIBUV_VERSION_HEADER_FILE "${LIBUV_INCLUDE_DIR}/uv/version.h")
   else()
     set(LIBUV_VERSION_HEADER_FILE "${LIBUV_INCLUDE_DIR}/uv.h")
   endif()
