ARM: Substitute Linux atomic ops with FreeBSD/NetBSD atomic ops

--- hotspot/src/os_cpu/bsd_zero/vm/orderAccess_bsd_zero.inline.hpp.orig	2015-06-03 15:49:41 UTC
+++ hotspot/src/os_cpu/bsd_zero/vm/orderAccess_bsd_zero.inline.hpp
@@ -37,8 +37,16 @@
  * and gcc __sync_synchronize(); implementation does not use the kernel
  * helper for all gcc versions so it is unreliable to use as well.
  */
+#if defined(__FreeBSD__)
+#include <machine/atomic.h>
+#define __kernel_dmb dmb
+#elif defined(__NetBSD__)
+#include <sys/atomic.h>
+#define __kernel_dmb membar_sync
+#else
 typedef void (__kernel_dmb_t) (void);
 #define __kernel_dmb (*(__kernel_dmb_t *) 0xffff0fa0)
+#endif
 
 #define FULL_MEM_BARRIER __kernel_dmb()
 #define READ_MEM_BARRIER __kernel_dmb()
