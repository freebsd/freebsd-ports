$FreeBSD$

--- ../../hotspot1.3.1/src/os_cpu/linux_i486/vm/os_linux_i486.cpp	11 Apr 2002 10:30:45 -0000	1.3
+++ ../../hotspot1.3.1/src/os_cpu/linux_i486/vm/os_linux_i486.cpp	28 Jul 2002 23:18:37 -0000	1.4
@@ -15,7 +15,6 @@
 # include "incls/_os_linux_i486.cpp.incl"
 # include "incls/_os_pd.hpp.incl"
 
-extern "C" {
 // put OS-includes here
 # include <sys/types.h>
 # include <sys/mman.h>
@@ -34,14 +33,13 @@
 # include <pwd.h>
 # include <poll.h>
 
-
 #include <setjmp.h>
 
-#define HACK
-#include </usr/src/lib/libc_r/uthread/pthread_private.h>
-//--billh
+#undef pthread_attr_default
+#undef pthread_mutexattr_default
+#undef pthread_condattr_default
 
-}
+#include <uthread/pthread_private.h>
 
 #define MAX_PATH (2 * K)
 #define INTERRUPT_SIGNAL SIGUSR1
@@ -188,10 +186,11 @@
   // fastlane always uses callback for safepoints
   assert(!GetThreadState || Arguments::has_profile(), "just checking");
     
-// The register UESP doensn't exist in the ucontext_t under FreeBSD. I
+// The register UESP doesn't exist in the ucontext_t under FreeBSD. I
 // suspect that it's a kind of pseudo-register that's created by the glibc
 // runtime in Linux and other OSes to differentiate the stack pointers
-// during an exception verses normal execution, much like the old 68k CPU.
+// during exception time verses normal execution. It's much like the old 68k
+// CPU's stack handling.
 //
 //  _sp   = (jint*)uc->uc_mcontext.gregs[UESP];	
 //
@@ -790,7 +789,6 @@
 // JVMPI code
 bool os::thread_is_running(JavaThread* tp) {
 #if 0
-#endif
   pthread_t   tid = tp->osthread()->thread_id();
   ucontext_t  *uc = (ucontext_t *) &tid->ctx.uc;
   sumObject_t *so = (sumObject_t*) uc;
@@ -824,6 +822,8 @@
     tp->set_last_sum(sum);
     return true;
   }
+#endif
+  return true;
 }
 
 
