--- libziparchive/zip_archive.cc.orig	2018-06-21 00:58:42 UTC
+++ libziparchive/zip_archive.cc
@@ -47,6 +47,17 @@
 #include "zip_archive_common.h"
 #include "zip_archive_private.h"
 
+#if !defined(_WIN32)
+#if __cplusplus >= 201703 || (defined(_LIBCPP_VERSION) && __has_include(<string_view>))
+#include <string_view>
+#elif __cplusplus >= 201402
+#include <experimental/string_view>
+namespace std {
+using std::experimental::string_view;
+}
+#endif // __cplusplus >= 201703
+#endif // !defined(_WIN32)
+
 using android::base::get_unaligned;
 
 // Used to turn on crc checks - verify that the content CRC matches the values
@@ -100,7 +111,7 @@ static uint32_t RoundUpPower2(uint32_t val) {
 }
 
 static uint32_t ComputeHash(const ZipString& name) {
-#if !defined(_WIN32)
+#if __cplusplus >= 201402 && !defined(_WIN32)
   return std::hash<std::string_view>{}(
       std::string_view(reinterpret_cast<const char*>(name.name), name.name_length));
 #else
