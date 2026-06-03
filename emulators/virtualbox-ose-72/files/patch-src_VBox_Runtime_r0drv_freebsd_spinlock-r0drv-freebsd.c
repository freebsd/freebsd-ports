--- src/VBox/Runtime/r0drv/freebsd/spinlock-r0drv-freebsd.c.orig	2025-08-13 19:51:51 UTC
+++ src/VBox/Runtime/r0drv/freebsd/spinlock-r0drv-freebsd.c
@@ -116,7 +116,9 @@ RTDECL(int)  RTSpinlockCreate(PRTSPINLOCK pSpinlock, u
      * Allocate.
      */
     AssertCompile(sizeof(RTSPINLOCKINTERNAL) > sizeof(void *));
+    IPRT_FREEBSD_SAVE_EFL_AC();
     PRTSPINLOCKINTERNAL pThis = (PRTSPINLOCKINTERNAL)RTMemAllocZ(sizeof(*pThis));
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     if (!pThis)
         return VERR_NO_MEMORY;
 
@@ -150,7 +152,9 @@ RTDECL(int)  RTSpinlockDestroy(RTSPINLOCK Spinlock)
      * Make the lock invalid and release the memory.
      */
     ASMAtomicIncU32(&pThis->u32Magic);
+    IPRT_FREEBSD_SAVE_EFL_AC();
     RTMemFree(pThis);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -176,6 +180,7 @@ RTDECL(void) RTSpinlockAcquire(RTSPINLOCK Spinlock)
                 {
                     RT_ASSERT_PREEMPT_CPUID_SPIN_ACQUIRED(pThis);
                     pThis->fIntSaved = fIntSaved;
+                    IPRT_FREEBSD_RESTORE_EFL_ONLY_AC_EX(fIntSaved);
                     return;
                 }
                 if (--c <= 0)
