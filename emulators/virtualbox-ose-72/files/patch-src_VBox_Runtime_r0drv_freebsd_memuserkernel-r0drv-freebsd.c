--- src/VBox/Runtime/r0drv/freebsd/memuserkernel-r0drv-freebsd.c.orig	2025-08-13 19:51:51 UTC
+++ src/VBox/Runtime/r0drv/freebsd/memuserkernel-r0drv-freebsd.c
@@ -46,7 +46,9 @@ RTR0DECL(int) RTR0MemUserCopyFrom(void *pvDst, RTR3PTR
 
 RTR0DECL(int) RTR0MemUserCopyFrom(void *pvDst, RTR3PTR R3PtrSrc, size_t cb)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     int rc = copyin((const void *)R3PtrSrc, pvDst, cb);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     if (RT_LIKELY(rc == 0))
         return VINF_SUCCESS;
     return VERR_ACCESS_DENIED;
@@ -55,7 +57,9 @@ RTR0DECL(int) RTR0MemUserCopyTo(RTR3PTR R3PtrDst, void
 
 RTR0DECL(int) RTR0MemUserCopyTo(RTR3PTR R3PtrDst, void const *pvSrc, size_t cb)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     int rc = copyout(pvSrc, (void *)R3PtrDst, cb);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     if (RT_LIKELY(rc == 0))
         return VINF_SUCCESS;
     return VERR_ACCESS_DENIED;
