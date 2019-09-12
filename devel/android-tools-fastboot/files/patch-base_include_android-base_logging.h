--- base/include/android-base/logging.h.orig	2019-07-17 19:54:09 UTC
+++ base/include/android-base/logging.h
@@ -350,7 +350,7 @@ struct LogAbortAfterFullExpr {
 // DCHECKs are debug variants of CHECKs only enabled in debug builds. Generally
 // CHECK should be used unless profiling identifies a CHECK as being in
 // performance critical code.
-#if defined(NDEBUG) && !defined(__clang_analyzer__)
+#if defined(NDEBUG) && !defined(__clang_analyzer__) || !defined(__ANDROID__)
 static constexpr bool kEnableDChecks = false;
 #else
 static constexpr bool kEnableDChecks = true;
@@ -486,8 +486,9 @@ namespace std {  // NOLINT(cert-dcl58-cpp)
 #pragma clang diagnostic ignored "-Wgcc-compat"
 #define OSTREAM_STRING_POINTER_USAGE_WARNING \
     __attribute__((diagnose_if(true, "Unexpected logging of string pointer", "warning")))
+OSTREAM_STRING_POINTER_USAGE_WARNING // GCC
 inline std::ostream& operator<<(std::ostream& stream, const std::string* string_pointer)
-    OSTREAM_STRING_POINTER_USAGE_WARNING {
+{
   return stream << static_cast<const void*>(string_pointer);
 }
 #pragma clang diagnostic pop
