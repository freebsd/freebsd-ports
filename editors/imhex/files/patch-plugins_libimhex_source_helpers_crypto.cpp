--- plugins/libimhex/source/helpers/crypto.cpp.orig	2021-12-16 17:57:41 UTC
+++ plugins/libimhex/source/helpers/crypto.cpp
@@ -15,12 +15,13 @@
 
 #include <array>
 #include <span>
-#include <concepts>
 #include <functional>
 #include <algorithm>
 #include <cstddef>
 #include <cstdint>
 
+#include <range/v3/functional/concepts.hpp>
+
 #if MBEDTLS_VERSION_MAJOR <= 2
 
 #define mbedtls_md5_starts mbedtls_md5_starts_ret
@@ -44,7 +45,7 @@
 namespace hex::crypt {
     using namespace std::placeholders;
 
-    template<std::invocable<unsigned char*, size_t> Func>
+    template<ranges::invocable<unsigned char*, size_t> Func>
     void processDataByChunks(prv::Provider* data, u64 offset, size_t size, Func func)
     {
         std::array<u8, 512> buffer = { 0 };
