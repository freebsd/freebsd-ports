--- src/vxlog/type-to-string.h.orig	2018-07-08 08:39:58 UTC
+++ src/vxlog/type-to-string.h
@@ -62,7 +62,7 @@ class SignChecker {
  public:
   template<typename T>
   static bool NumberToString(const T &value, char *str, size_t len) {
-    int res = snprintf(str, len, "%"PRId64, static_cast<int64_t>(value));
+    int res = snprintf(str, len, "%" PRId64, static_cast<int64_t>(value));
     if ((res < 0) || (static_cast<size_t>(res) == len)) return false;
     return true;
   }
@@ -73,7 +73,7 @@ class SignChecker<false> {
  public:
   template<typename T>
   static bool NumberToString(const T &value, char *str, size_t len) {
-    int res = snprintf(str, len, "%"PRIu64, static_cast<uint64_t>(value));
+    int res = snprintf(str, len, "%" PRIu64, static_cast<uint64_t>(value));
     if ((res < 0) || (static_cast<size_t>(res) == len)) return false;
     return true;
   }
