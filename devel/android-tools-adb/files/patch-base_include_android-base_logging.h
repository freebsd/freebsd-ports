--- base/include/android-base/logging.h.orig	2015-09-29 18:07:07 UTC
+++ base/include/android-base/logging.h
@@ -25,6 +25,8 @@
 #endif
 #endif
 
+#include <errno.h>
+
 #include <functional>
 #include <memory>
 #include <ostream>
@@ -321,7 +321,7 @@ struct LogAbortAfterFullExpr {
 // DCHECKs are debug variants of CHECKs only enabled in debug builds. Generally
 // CHECK should be used unless profiling identifies a CHECK as being in
 // performance critical code.
-#if defined(NDEBUG) && !defined(__clang_analyzer__)
+#if defined(NDEBUG) && !defined(__clang_analyzer__) || !defined(__ANDROID__)
 static constexpr bool kEnableDChecks = false;
 #else
 static constexpr bool kEnableDChecks = true;
