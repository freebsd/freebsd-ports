--- src/VBox/Runtime/r0drv/freebsd/memuserkernel-r0drv-freebsd.c.orig	2018-10-15 14:31:31 UTC
+++ src/VBox/Runtime/r0drv/freebsd/memuserkernel-r0drv-freebsd.c
@@ -36,7 +36,9 @@
 
 RTR0DECL(int) RTR0MemUserCopyFrom(void *pvDst, RTR3PTR R3PtrSrc, size_t cb)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     int rc = copyin((const void *)R3PtrSrc, pvDst, cb);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     if (RT_LIKELY(rc == 0))
         return VINF_SUCCESS;
     return VERR_ACCESS_DENIED;
@@ -45,7 +47,9 @@ RTR0DECL(int) RTR0MemUserCopyFrom(void *pvDst, RTR3PTR
 
 RTR0DECL(int) RTR0MemUserCopyTo(RTR3PTR R3PtrDst, void const *pvSrc, size_t cb)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     int rc = copyout(pvSrc, (void *)R3PtrDst, cb);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     if (RT_LIKELY(rc == 0))
         return VINF_SUCCESS;
     return VERR_ACCESS_DENIED;
