--- src/VBox/Runtime/r0drv/freebsd/mp-r0drv-freebsd.c.orig	2025-08-13 19:51:51 UTC
+++ src/VBox/Runtime/r0drv/freebsd/mp-r0drv-freebsd.c
@@ -157,7 +157,9 @@ static void rtmpOnAllFreeBSDWrapper(void *pvArg)
 static void rtmpOnAllFreeBSDWrapper(void *pvArg)
 {
     PRTMPARGS pArgs = (PRTMPARGS)pvArg;
+    IPRT_FREEBSD_SAVE_EFL_AC();
     pArgs->pfnWorker(curcpu, pArgs->pvUser1, pArgs->pvUser2);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 }
 
 
@@ -169,7 +171,9 @@ RTDECL(int) RTMpOnAll(PFNRTMPWORKER pfnWorker, void *p
     Args.pvUser2 = pvUser2;
     Args.idCpu = NIL_RTCPUID;
     Args.cHits = 0;
+    IPRT_FREEBSD_SAVE_EFL_AC();
     smp_rendezvous(NULL, rtmpOnAllFreeBSDWrapper, smp_no_rendezvous_barrier, &Args);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -185,7 +189,11 @@ static void rtmpOnOthersFreeBSDWrapper(void *pvArg)
     PRTMPARGS pArgs = (PRTMPARGS)pvArg;
     RTCPUID idCpu = curcpu;
     if (pArgs->idCpu != idCpu)
+    {
+        IPRT_FREEBSD_SAVE_EFL_AC();
         pArgs->pfnWorker(idCpu, pArgs->pvUser1, pArgs->pvUser2);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
+    }
 }
 
 
@@ -206,6 +214,7 @@ RTDECL(int) RTMpOnOthers(PFNRTMPWORKER pfnWorker, void
         Args.pvUser2 = pvUser2;
         Args.idCpu = RTMpCpuId();
         Args.cHits = 0;
+        IPRT_FREEBSD_SAVE_EFL_AC();
 #if __FreeBSD_version >= 700000
 # if __FreeBSD_version >= 900000
         Mask = all_cpus;
@@ -217,6 +226,7 @@ RTDECL(int) RTMpOnOthers(PFNRTMPWORKER pfnWorker, void
 #else
         smp_rendezvous(NULL, rtmpOnOthersFreeBSDWrapper, NULL, &Args);
 #endif
+        IPRT_FREEBSD_RESTORE_EFL_AC();
     }
     return VINF_SUCCESS;
 }
@@ -234,8 +244,10 @@ static void rtmpOnSpecificFreeBSDWrapper(void *pvArg)
     RTCPUID     idCpu = curcpu;
     if (pArgs->idCpu == idCpu)
     {
+        IPRT_FREEBSD_SAVE_EFL_AC();
         pArgs->pfnWorker(idCpu, pArgs->pvUser1, pArgs->pvUser2);
         ASMAtomicIncU32(&pArgs->cHits);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
     }
 }
 
@@ -258,6 +270,7 @@ RTDECL(int) RTMpOnSpecific(RTCPUID idCpu, PFNRTMPWORKE
     Args.pvUser2 = pvUser2;
     Args.idCpu = idCpu;
     Args.cHits = 0;
+    IPRT_FREEBSD_SAVE_EFL_AC();
 #if __FreeBSD_version >= 700000
 # if __FreeBSD_version >= 900000
     CPU_SETOF(idCpu, &Mask);
@@ -268,6 +281,7 @@ RTDECL(int) RTMpOnSpecific(RTCPUID idCpu, PFNRTMPWORKE
 #else
     smp_rendezvous(NULL, rtmpOnSpecificFreeBSDWrapper, NULL, &Args);
 #endif
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return Args.cHits == 1
          ? VINF_SUCCESS
          : VERR_CPU_NOT_FOUND;
@@ -297,12 +311,14 @@ RTDECL(int) RTMpPokeCpu(RTCPUID idCpu)
     if (!RTMpIsCpuOnline(idCpu))
         return VERR_CPU_NOT_FOUND;
 
+    IPRT_FREEBSD_SAVE_EFL_AC();
 # if __FreeBSD_version >= 900000
     CPU_SETOF(idCpu, &Mask);
 # else
     Mask = (cpumask_t)1 << idCpu;
 # endif
     smp_rendezvous_cpus(Mask, NULL, rtmpFreeBSDPokeCallback, smp_no_rendezvous_barrier, NULL);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 
     return VINF_SUCCESS;
 }
