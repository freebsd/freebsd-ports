--- source/utils/ze_to_string.h.orig	2026-05-11 20:15:36 UTC
+++ source/utils/ze_to_string.h
@@ -128,9 +128,6 @@ inline std::string to_string(uint8_t value) { return s
 inline std::string to_string(uint16_t value) { return std::to_string(value); }
 inline std::string to_string(int32_t value) { return std::to_string(value); }
 inline std::string to_string(int64_t value) { return std::to_string(value); }
-#if SIZE_MAX != UINT64_MAX
-inline std::string to_string(size_t value) { return std::to_string(value); }
-#endif
 inline std::string to_string(double value) { return std::to_string(value); }
 inline std::string to_string(const char* str) {
     if (!str) return "nullptr";
@@ -162,12 +159,6 @@ inline std::string to_string(const int64_t* ptr) {
     if (!ptr) return "nullptr";
     return to_string(*ptr);
 }
-#if SIZE_MAX != UINT64_MAX
-inline std::string to_string(const size_t* ptr) {
-    if (!ptr) return "nullptr";
-    return to_string(*ptr);
-}
-#endif
 inline std::string to_string(const double* ptr) {
     if (!ptr) return "nullptr";
     return to_string(*ptr);
