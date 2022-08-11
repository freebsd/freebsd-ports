--- third_party/abseil-cpp/absl/base/config.h.orig	2022-05-11 07:16:54 UTC
+++ third_party/abseil-cpp/absl/base/config.h
@@ -414,7 +414,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMESPACE_STR[0] !=
     defined(_AIX) || defined(__ros__) || defined(__native_client__) ||    \
     defined(__asmjs__) || defined(__wasm__) || defined(__Fuchsia__) ||    \
     defined(__sun) || defined(__ASYLO__) || defined(__myriad2__) ||       \
-    defined(__HAIKU__)
+    defined(__HAIKU__) || defined(__OpenBSD__)
 #define ABSL_HAVE_MMAP 1
 #endif
 
@@ -425,7 +425,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMESPACE_STR[0] !=
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
-    defined(_AIX) || defined(__ros__)
+    defined(_AIX) || defined(__ros__) || defined(__OpenBSD__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
 #endif
 
@@ -444,7 +444,8 @@ static_assert(ABSL_INTERNAL_INLINE_NAMESPACE_STR[0] !=
 // POSIX.1-2001.
 #ifdef ABSL_HAVE_SCHED_YIELD
 #error ABSL_HAVE_SCHED_YIELD cannot be directly set
-#elif defined(__linux__) || defined(__ros__) || defined(__native_client__)
+#elif defined(__linux__) || defined(__ros__) || defined(__native_client__) || \
+    defined(__OpenBSD__) || defined(__FreeBSD__)
 #define ABSL_HAVE_SCHED_YIELD 1
 #endif
 
@@ -459,7 +460,8 @@ static_assert(ABSL_INTERNAL_INLINE_NAMESPACE_STR[0] !=
 // platforms.
 #ifdef ABSL_HAVE_SEMAPHORE_H
 #error ABSL_HAVE_SEMAPHORE_H cannot be directly set
-#elif defined(__linux__) || defined(__ros__)
+#elif defined(__linux__) || defined(__ros__) || defined(__OpenBSD__) || \
+    defined(__FreeBSD__)
 #define ABSL_HAVE_SEMAPHORE_H 1
 #endif
 
