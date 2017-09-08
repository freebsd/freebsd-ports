--- src/google/protobuf/stubs/atomicops.h.orig	2017-08-15 23:39:12 UTC
+++ src/google/protobuf/stubs/atomicops.h
@@ -198,6 +198,8 @@ Atomic64 Release_Load(volatile const Ato
 #elif defined(__GNUC__)
 #if defined(GOOGLE_PROTOBUF_ARCH_IA32) || defined(GOOGLE_PROTOBUF_ARCH_X64)
 #include <google/protobuf/stubs/atomicops_internals_x86_gcc.h>
+#elif defined(GOOGLE_PROTOBUF_ARCH_ARM) && defined(__FreeBSD__)
+#include <google/protobuf/stubs/atomicops_internals_generic_gcc.h>
 #elif defined(GOOGLE_PROTOBUF_ARCH_ARM) && defined(__linux__)
 #if (((__GNUC__ == 4) && (__GNUC_MINOR__ >= 7)) || (__GNUC__ > 4))
 #include <google/protobuf/stubs/atomicops_internals_generic_gcc.h>
