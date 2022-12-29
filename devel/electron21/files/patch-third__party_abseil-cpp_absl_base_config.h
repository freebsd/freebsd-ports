--- third_party/abseil-cpp/absl/base/config.h.orig	2022-09-24 10:57:32 UTC
+++ third_party/abseil-cpp/absl/base/config.h
@@ -458,7 +458,8 @@ static_assert(ABSL_INTERNAL_INLINE_NAMESPACE_STR[0] !=
 // POSIX.1-2001.
 #ifdef ABSL_HAVE_SCHED_YIELD
 #error ABSL_HAVE_SCHED_YIELD cannot be directly set
-#elif defined(__linux__) || defined(__ros__) || defined(__native_client__)
+#elif defined(__linux__) || defined(__ros__) || defined(__native_client__) || \
+    defined(__OpenBSD__) || defined(__FreeBSD__)
 #define ABSL_HAVE_SCHED_YIELD 1
 #endif
 
@@ -473,7 +474,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMESPACE_STR[0] !=
 // platforms.
 #ifdef ABSL_HAVE_SEMAPHORE_H
 #error ABSL_HAVE_SEMAPHORE_H cannot be directly set
-#elif defined(__linux__) || defined(__ros__)
+#elif defined(__linux__) || defined(__ros__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #define ABSL_HAVE_SEMAPHORE_H 1
 #endif
 
