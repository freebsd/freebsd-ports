--- src/VBox/Runtime/r0drv/freebsd/thread2-r0drv-freebsd.c.orig	2025-08-13 19:51:51 UTC
+++ src/VBox/Runtime/r0drv/freebsd/thread2-r0drv-freebsd.c
@@ -104,6 +104,8 @@ DECLHIDDEN(int) rtThreadNativeSetPriority(PRTTHREADINT
             return VERR_INVALID_PARAMETER;
     }
 
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
 #if __FreeBSD_version < 700000
     /* Do like they're doing in subr_ntoskrnl.c... */
     mtx_lock_spin(&sched_lock);
@@ -120,6 +122,7 @@ DECLHIDDEN(int) rtThreadNativeSetPriority(PRTTHREADINT
     thread_unlock(curthread);
 #endif
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -169,6 +172,7 @@ DECLHIDDEN(int) rtThreadNativeCreate(PRTTHREADINT pThr
 
 DECLHIDDEN(int) rtThreadNativeCreate(PRTTHREADINT pThreadInt, PRTNATIVETHREAD pNativeThread)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     int rc;
     struct proc *pProc;
 
@@ -184,6 +188,7 @@ DECLHIDDEN(int) rtThreadNativeCreate(PRTTHREADINT pThr
     }
     else
         rc = RTErrConvertFromErrno(rc);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return rc;
 }
 
