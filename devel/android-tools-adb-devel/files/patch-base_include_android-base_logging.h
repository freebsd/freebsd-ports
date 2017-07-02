--- base/include/android-base/logging.h.orig	2017-07-02 22:55:50 UTC
+++ base/include/android-base/logging.h
@@ -321,7 +321,7 @@ struct LogAbortAfterFullExpr {
 // DCHECKs are debug variants of CHECKs only enabled in debug builds. Generally
 // CHECK should be used unless profiling identifies a CHECK as being in
 // performance critical code.
-#if defined(NDEBUG) && !defined(__clang_analyzer__)
+#if defined(NDEBUG) && !defined(__clang_analyzer__) || !defined(__ANDROID__)
 static constexpr bool kEnableDChecks = false;
 #else
 static constexpr bool kEnableDChecks = true;
