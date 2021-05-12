--- base/profiler/thread_delegate_posix.cc.orig	2021-01-07 00:36:18 UTC
+++ base/profiler/thread_delegate_posix.cc
@@ -12,6 +12,9 @@
 #include "base/profiler/thread_delegate_posix.h"
 #include "base/stl_util.h"
 #include "build/build_config.h"
+#if defined(OS_FREEBSD)
+#include <pthread_np.h>
+#endif
 
 #if defined(OS_ANDROID)
 #include "base/files/file_util.h"
@@ -43,7 +46,12 @@ base::Optional<uintptr_t> GetAndroidMainThreadStackBas
 uintptr_t GetThreadStackBaseAddressImpl(
     SamplingProfilerThreadToken thread_token) {
   pthread_attr_t attr;
+#if defined(OS_FREEBSD)
+  pthread_attr_init(&attr);
+  pthread_attr_get_np(thread_token.pthread_id, &attr);
+#elif defined(OS_LINUX)
   pthread_getattr_np(thread_token.pthread_id, &attr);
+#endif
   // See crbug.com/617730 for limitations of this approach on Linux.
   void* address;
   size_t size;
@@ -130,16 +138,33 @@ std::vector<uintptr_t*> ThreadDelegatePosix::GetRegist
   return {
       // Return the set of callee-save registers per the i386 System V ABI
       // section 2.2.3, plus the stack pointer.
+#if defined(OS_FREEBSD)
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_ebx),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_ebp),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_esi),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_edi),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_esp),
+#else
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_EBX]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_EBP]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_ESI]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_EDI]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_ESP]),
+#endif
   };
 #elif defined(ARCH_CPU_X86_FAMILY) && defined(ARCH_CPU_64_BITS)
   return {
       // Return the set of callee-save registers per the x86-64 System V ABI
       // section 3.2.1, plus the stack pointer.
+#if defined(OS_FREEBSD)
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_rbp),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_rbx),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_r12),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_r13),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_r14),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_r15),
+      reinterpret_cast<uintptr_t*>(&thread_context->mc_rsp),
+#else
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_RBP]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_RBX]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_R12]),
@@ -147,6 +172,7 @@ std::vector<uintptr_t*> ThreadDelegatePosix::GetRegist
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_R14]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_R15]),
       reinterpret_cast<uintptr_t*>(&thread_context->gregs[REG_RSP]),
+#endif
   };
 #else  // #if defined(ARCH_CPU_ARM_FAMILY) && defined(ARCH_CPU_32_BITS)
   // Unimplemented for other architectures.
