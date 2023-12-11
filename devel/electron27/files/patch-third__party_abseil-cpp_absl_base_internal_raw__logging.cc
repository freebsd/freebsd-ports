--- third_party/abseil-cpp/absl/base/internal/raw_logging.cc.orig	2023-08-10 01:48:49 UTC
+++ third_party/abseil-cpp/absl/base/internal/raw_logging.cc
@@ -56,10 +56,12 @@
 // ABSL_HAVE_SYSCALL_WRITE is defined when the platform provides the syscall
 //   syscall(SYS_write, /*int*/ fd, /*char* */ buf, /*size_t*/ len);
 // for low level operations that want to avoid libc.
-#if (defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)) && \
+#if (defined(__linux__) || defined(__FreeBSD__)) && \
     !defined(__ANDROID__)
 #include <sys/syscall.h>
 #define ABSL_HAVE_SYSCALL_WRITE 1
+#define ABSL_LOW_LEVEL_WRITE_SUPPORTED 1
+#elif defined(__OpenBSD__)
 #define ABSL_LOW_LEVEL_WRITE_SUPPORTED 1
 #else
 #undef ABSL_HAVE_SYSCALL_WRITE
