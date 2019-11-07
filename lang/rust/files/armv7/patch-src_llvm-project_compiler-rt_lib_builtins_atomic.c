https://reviews.llvm.org/D68045

--- src/llvm-project/compiler-rt/lib/builtins/atomic.c.orig	2019-09-09 18:30:53 UTC
+++ src/llvm-project/compiler-rt/lib/builtins/atomic.c
@@ -51,9 +51,11 @@ static const long SPINLOCK_MASK = SPINLOCK_COUNT - 1;
 ////////////////////////////////////////////////////////////////////////////////
 #ifdef __FreeBSD__
 #include <errno.h>
-#include <machine/atomic.h>
+// clang-format off
 #include <sys/types.h>
+#include <machine/atomic.h>
 #include <sys/umtx.h>
+// clang-format on
 typedef struct _usem Lock;
 __inline static void unlock(Lock *l) {
   __c11_atomic_store((_Atomic(uint32_t) *)&l->_count, 1, __ATOMIC_RELEASE);
--- src/llvm-project/compiler-rt/lib/builtins/clear_cache.c.orig	2019-09-09 18:30:53 UTC
+++ src/llvm-project/compiler-rt/lib/builtins/clear_cache.c
@@ -23,8 +23,10 @@ uintptr_t GetCurrentProcess(void);
 #endif
 
 #if defined(__FreeBSD__) && defined(__arm__)
-#include <machine/sysarch.h>
+// clang-format off
 #include <sys/types.h>
+#include <machine/sysarch.h>
+// clang-format on
 #endif
 
 #if defined(__NetBSD__) && defined(__arm__)
@@ -32,8 +34,10 @@ uintptr_t GetCurrentProcess(void);
 #endif
 
 #if defined(__OpenBSD__) && defined(__mips__)
-#include <machine/sysarch.h>
+// clang-format off
 #include <sys/types.h>
+#include <machine/sysarch.h>
+// clang-format on
 #endif
 
 #if defined(__linux__) && defined(__mips__)
