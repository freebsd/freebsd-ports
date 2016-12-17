--- src/google/protobuf/stubs/atomicops.h.orig	2016-09-24 02:12:45 UTC
+++ src/google/protobuf/stubs/atomicops.h
@@ -202,6 +202,8 @@ Atomic64 Release_Load(volatile const Ato
 #elif defined(__GNUC__)
 #if defined(GOOGLE_PROTOBUF_ARCH_IA32) || defined(GOOGLE_PROTOBUF_ARCH_X64)
 #include <google/protobuf/stubs/atomicops_internals_x86_gcc.h>
+#elif defined(GOOGLE_PROTOBUF_ARCH_ARM) && defined(__FreeBSD__)
+#include <google/protobuf/stubs/atomicops_internals_generic_gcc.h>
 #elif defined(GOOGLE_PROTOBUF_ARCH_ARM) && defined(__linux__)
 #include <google/protobuf/stubs/atomicops_internals_arm_gcc.h>
 #elif defined(GOOGLE_PROTOBUF_ARCH_AARCH64)
