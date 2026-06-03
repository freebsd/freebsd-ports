--- extra/abseil/abseil-cpp-20250814.1/absl/time/internal/cctz/src/time_zone_format.cc.orig	2026-05-03 16:32:15.229937000 +0200
+++ extra/abseil/abseil-cpp-20250814.1/absl/time/internal/cctz/src/time_zone_format.cc	2026-05-03 16:35:09.322797000 +0200
@@ -13,7 +13,7 @@
 //   limitations under the License.
 
 #if !defined(HAS_STRPTIME)
-#if !defined(_MSC_VER) && !defined(__MINGW32__) && !defined(__VXWORKS__)
+#if !defined(_MSC_VER) && !defined(__MINGW32__) && !defined(__VXWORKS__) && !defined(__FreeBSD__)
 #define HAS_STRPTIME 1  // Assume everyone else has strptime().
 #endif
 #endif
@@ -664,7 +664,7 @@ const char* ParseTM(const char* dp, const char* fmt, s
 // Parses a string into a std::tm using strptime(3).
 const char* ParseTM(const char* dp, const char* fmt, std::tm* tm) {
   if (dp != nullptr) {
-    dp = strptime(dp, fmt, tm);
+    dp = ::strptime(dp, fmt, tm);
   }
   return dp;
 }
