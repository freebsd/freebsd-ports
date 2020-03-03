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
