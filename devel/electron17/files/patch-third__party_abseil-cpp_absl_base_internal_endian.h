--- third_party/abseil-cpp/absl/base/internal/endian.h.orig	2022-05-11 07:16:54 UTC
+++ third_party/abseil-cpp/absl/base/internal/endian.h
@@ -19,7 +19,7 @@
 // The following guarantees declaration of the byte swap functions
 #ifdef _MSC_VER
 #include <stdlib.h>  // NOLINT(build/include)
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <sys/endian.h>
 #elif defined(__GLIBC__)
 #include <byteswap.h>  // IWYU pragma: export
