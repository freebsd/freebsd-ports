--- folly/lang/UncaughtExceptions.h.orig	2019-06-16 07:37:04 UTC
+++ folly/lang/UncaughtExceptions.h
@@ -24,7 +24,9 @@ namespace __cxxabiv1 {
 // forward declaration (originally defined in unwind-cxx.h from from libstdc++)
 struct __cxa_eh_globals;
 // declared in cxxabi.h from libstdc++-v3
-extern "C" __cxa_eh_globals* __cxa_get_globals() noexcept;
+extern "C" {
+__cxa_eh_globals *__cxa_get_globals(void);
+};
 } // namespace __cxxabiv1
 #elif defined(FOLLY_FORCE_EXCEPTION_COUNT_USE_STD) || defined(_MSC_VER)
 #define FOLLY_EXCEPTION_COUNT_USE_STD
