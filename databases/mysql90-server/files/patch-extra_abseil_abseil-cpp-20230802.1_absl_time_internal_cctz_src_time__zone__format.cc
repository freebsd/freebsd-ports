--- extra/abseil/abseil-cpp-20230802.1/absl/time/internal/cctz/src/time_zone_format.cc.orig	2024-05-09 19:37:37 UTC
+++ extra/abseil/abseil-cpp-20230802.1/absl/time/internal/cctz/src/time_zone_format.cc
@@ -13,7 +13,7 @@
 //   limitations under the License.
 
 #if !defined(HAS_STRPTIME)
-#if !defined(_MSC_VER) && !defined(__MINGW32__) && !defined(__VXWORKS__)
+#if !defined(_MSC_VER) && !defined(__MINGW32__) && !defined(__VXWORKS__) && !defined(__FreeBSD__)
 #define HAS_STRPTIME 1  // Assume everyone else has strptime().
 #endif
 #endif
@@ -648,7 +648,7 @@ const char* ParseTM(const char* dp, const char* fmt, s
 // Parses a string into a std::tm using strptime(3).
 const char* ParseTM(const char* dp, const char* fmt, std::tm* tm) {
   if (dp != nullptr) {
-    dp = strptime(dp, fmt, tm);
+    dp = ::strptime(dp, fmt, tm);
   }
   return dp;
 }
