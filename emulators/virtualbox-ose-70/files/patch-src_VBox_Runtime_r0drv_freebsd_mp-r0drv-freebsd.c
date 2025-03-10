--- src/VBox/Runtime/r0drv/freebsd/mp-r0drv-freebsd.c.orig	2019-04-16 10:17:21 UTC
+++ src/VBox/Runtime/r0drv/freebsd/mp-r0drv-freebsd.c
@@ -147,7 +147,9 @@ RTDECL(RTCPUID) RTMpGetOnlineCount(void)
 static void rtmpOnAllFreeBSDWrapper(void *pvArg)
 {
     PRTMPARGS pArgs = (PRTMPARGS)pvArg;
+    IPRT_FREEBSD_SAVE_EFL_AC();
     pArgs->pfnWorker(curcpu, pArgs->pvUser1, pArgs->pvUser2);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 }
 
 
@@ -159,7 +161,9 @@ RTDECL(int) RTMpOnAll(PFNRTMPWORKER pfnWorker, void *p
     Args.pvUser2 = pvUser2;
     Args.idCpu = NIL_RTCPUID;
     Args.cHits = 0;
+    IPRT_FREEBSD_SAVE_EFL_AC();
     smp_rendezvous(NULL, rtmpOnAllFreeBSDWrapper, smp_no_rendezvous_barrier, &Args);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -175,7 +179,11 @@ static void rtmpOnOthersFreeBSDWrapper(void *pvArg)
     PRTMPARGS pArgs = (PRTMPARGS)pvArg;
     RTCPUID idCpu = curcpu;
     if (pArgs->idCpu != idCpu)
+    {
+        IPRT_FREEBSD_SAVE_EFL_AC();
         pArgs->pfnWorker(idCpu, pArgs->pvUser1, pArgs->pvUser2);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
+    }
 }
 
 
@@ -196,6 +204,7 @@ RTDECL(int) RTMpOnOthers(PFNRTMPWORKER pfnWorker, void
         Args.pvUser2 = pvUser2;
         Args.idCpu = RTMpCpuId();
         Args.cHits = 0;
+        IPRT_FREEBSD_SAVE_EFL_AC();
 #if __FreeBSD_version >= 700000
 # if __FreeBSD_version >= 900000
         Mask = all_cpus;
@@ -207,6 +216,7 @@ RTDECL(int) RTMpOnOthers(PFNRTMPWORKER pfnWorker, void
 #else
         smp_rendezvous(NULL, rtmpOnOthersFreeBSDWrapper, NULL, &Args);
 #endif
+        IPRT_FREEBSD_RESTORE_EFL_AC();
     }
     return VINF_SUCCESS;
 }
@@ -224,8 +234,10 @@ static void rtmpOnSpecificFreeBSDWrapper(void *pvArg)
     RTCPUID     idCpu = curcpu;
     if (pArgs->idCpu == idCpu)
     {
+        IPRT_FREEBSD_SAVE_EFL_AC();
         pArgs->pfnWorker(idCpu, pArgs->pvUser1, pArgs->pvUser2);
         ASMAtomicIncU32(&pArgs->cHits);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
     }
 }
 
@@ -248,6 +260,7 @@ RTDECL(int) RTMpOnSpecific(RTCPUID idCpu, PFNRTMPWORKE
     Args.pvUser2 = pvUser2;
     Args.idCpu = idCpu;
     Args.cHits = 0;
+    IPRT_FREEBSD_SAVE_EFL_AC();
 #if __FreeBSD_version >= 700000
 # if __FreeBSD_version >= 900000
     CPU_SETOF(idCpu, &Mask);
@@ -258,6 +271,7 @@ RTDECL(int) RTMpOnSpecific(RTCPUID idCpu, PFNRTMPWORKE
 #else
     smp_rendezvous(NULL, rtmpOnSpecificFreeBSDWrapper, NULL, &Args);
 #endif
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return Args.cHits == 1
          ? VINF_SUCCESS
          : VERR_CPU_NOT_FOUND;
@@ -287,12 +301,14 @@ RTDECL(int) RTMpPokeCpu(RTCPUID idCpu)
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
