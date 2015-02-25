--- src/google/protobuf/stubs/atomicops.h.orig	2014-08-26 03:52:37.000000000 +0800
+++ src/google/protobuf/stubs/atomicops.h	2015-02-21 11:45:38.816841509 +0800
@@ -182,6 +182,8 @@
 #elif defined(__GNUC__)
 #if defined(GOOGLE_PROTOBUF_ARCH_IA32) || defined(GOOGLE_PROTOBUF_ARCH_X64)
 #include <google/protobuf/stubs/atomicops_internals_x86_gcc.h>
+#elif defined(GOOGLE_PROTOBUF_ARCH_ARM) && defined(__FreeBSD__)
+#include <google/protobuf/stubs/atomicops_internals_generic_gcc.h>
 #elif defined(GOOGLE_PROTOBUF_ARCH_ARM) && defined(__linux__)
 #include <google/protobuf/stubs/atomicops_internals_arm_gcc.h>
 #elif defined(GOOGLE_PROTOBUF_ARCH_AARCH64)
