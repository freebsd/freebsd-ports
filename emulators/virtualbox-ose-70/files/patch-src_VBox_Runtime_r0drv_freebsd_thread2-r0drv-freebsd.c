--- src/VBox/Runtime/r0drv/freebsd/thread2-r0drv-freebsd.c.orig	2021-01-07 15:42:09 UTC
+++ src/VBox/Runtime/r0drv/freebsd/thread2-r0drv-freebsd.c
@@ -94,6 +94,8 @@ DECLHIDDEN(int) rtThreadNativeSetPriority(PRTTHREADINT
             return VERR_INVALID_PARAMETER;
     }
 
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
 #if __FreeBSD_version < 700000
     /* Do like they're doing in subr_ntoskrnl.c... */
     mtx_lock_spin(&sched_lock);
@@ -110,6 +112,7 @@ DECLHIDDEN(int) rtThreadNativeSetPriority(PRTTHREADINT
     thread_unlock(curthread);
 #endif
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -159,6 +162,7 @@ static void rtThreadNativeMain(void *pvThreadInt)
 
 DECLHIDDEN(int) rtThreadNativeCreate(PRTTHREADINT pThreadInt, PRTNATIVETHREAD pNativeThread)
 {
+    IPRT_FREEBSD_SAVE_EFL_AC();
     int rc;
     struct proc *pProc;
 
@@ -174,6 +178,7 @@ DECLHIDDEN(int) rtThreadNativeCreate(PRTTHREADINT pThr
     }
     else
         rc = RTErrConvertFromErrno(rc);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return rc;
 }
 
