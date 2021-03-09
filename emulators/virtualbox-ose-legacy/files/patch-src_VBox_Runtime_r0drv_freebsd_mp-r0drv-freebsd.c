--- src/VBox/Runtime/r0drv/freebsd/mp-r0drv-freebsd.c.orig	2018-10-15 14:31:31 UTC
+++ src/VBox/Runtime/r0drv/freebsd/mp-r0drv-freebsd.c
@@ -36,6 +36,15 @@
 #include <iprt/cpuset.h>
 #include "r0drv/mp-r0drv.h"
 
+#if __FreeBSD_version >= 700000 && __FreeBSD_version < 900000
+#define cpuset_t            cpumask_t
+#define all_cpus            (~(cpumask_t)0)
+#define CPU_CLR(n, p)       do { *(p) &= ~((cpumask_t)1 << (n)); } while (0)
+#define CPU_SETOF(n, p)     do { *(p) = (cpumask_t)1 << (n); } while (0)
+#endif
+#if __FreeBSD_version < 1200028
+#define smp_no_rendezvous_barrier   smp_no_rendevous_barrier
+#endif
 
 RTDECL(RTCPUID) RTMpCpuId(void)
 {
@@ -143,7 +152,9 @@ RTDECL(RTCPUID) RTMpGetOnlineCount(void)
 static void rtmpOnAllFreeBSDWrapper(void *pvArg)
 {
     PRTMPARGS pArgs = (PRTMPARGS)pvArg;
+    IPRT_FREEBSD_SAVE_EFL_AC();
     pArgs->pfnWorker(curcpu, pArgs->pvUser1, pArgs->pvUser2);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 }
 
 
@@ -155,7 +166,9 @@ RTDECL(int) RTMpOnAll(PFNRTMPWORKER pfnWorker, void *p
     Args.pvUser2 = pvUser2;
     Args.idCpu = NIL_RTCPUID;
     Args.cHits = 0;
-    smp_rendezvous(NULL, rtmpOnAllFreeBSDWrapper, smp_no_rendevous_barrier, &Args);
+    IPRT_FREEBSD_SAVE_EFL_AC();
+    smp_rendezvous(NULL, rtmpOnAllFreeBSDWrapper, smp_no_rendezvous_barrier, &Args);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return VINF_SUCCESS;
 }
 
@@ -171,7 +184,11 @@ static void rtmpOnOthersFreeBSDWrapper(void *pvArg)
     PRTMPARGS pArgs = (PRTMPARGS)pvArg;
     RTCPUID idCpu = curcpu;
     if (pArgs->idCpu != idCpu)
+    {
+        IPRT_FREEBSD_SAVE_EFL_AC();
         pArgs->pfnWorker(idCpu, pArgs->pvUser1, pArgs->pvUser2);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
+    }
 }
 
 
@@ -180,10 +197,8 @@ RTDECL(int) RTMpOnOthers(PFNRTMPWORKER pfnWorker, void
     /* Will panic if no rendezvousing cpus, so check up front. */
     if (RTMpGetOnlineCount() > 1)
     {
-#if __FreeBSD_version >= 900000
-        cpuset_t    Mask;
-#elif  __FreeBSD_version >= 700000
-        cpumask_t   Mask;
+#if __FreeBSD_version >= 700000
+        cpuset_t    Cpus;
 #endif
         RTMPARGS    Args;
 
@@ -192,17 +207,15 @@ RTDECL(int) RTMpOnOthers(PFNRTMPWORKER pfnWorker, void
         Args.pvUser2 = pvUser2;
         Args.idCpu = RTMpCpuId();
         Args.cHits = 0;
+        IPRT_FREEBSD_SAVE_EFL_AC();
 #if __FreeBSD_version >= 700000
-# if __FreeBSD_version >= 900000
-    Mask = all_cpus;
-    CPU_CLR(curcpu, &Mask);
-# else
-    Mask = ~(cpumask_t)curcpu;
-# endif
-        smp_rendezvous_cpus(Mask, NULL, rtmpOnOthersFreeBSDWrapper, smp_no_rendevous_barrier, &Args);
+        Cpus = all_cpus;
+        CPU_CLR(curcpu, &Cpus);
+        smp_rendezvous_cpus(Cpus, NULL, rtmpOnOthersFreeBSDWrapper, smp_no_rendezvous_barrier, &Args);
 #else
         smp_rendezvous(NULL, rtmpOnOthersFreeBSDWrapper, NULL, &Args);
 #endif
+        IPRT_FREEBSD_RESTORE_EFL_AC();
     }
     return VINF_SUCCESS;
 }
@@ -220,18 +233,18 @@ static void rtmpOnSpecificFreeBSDWrapper(void *pvArg)
     RTCPUID     idCpu = curcpu;
     if (pArgs->idCpu == idCpu)
     {
+        IPRT_FREEBSD_SAVE_EFL_AC();
         pArgs->pfnWorker(idCpu, pArgs->pvUser1, pArgs->pvUser2);
         ASMAtomicIncU32(&pArgs->cHits);
+        IPRT_FREEBSD_RESTORE_EFL_AC();
     }
 }
 
 
 RTDECL(int) RTMpOnSpecific(RTCPUID idCpu, PFNRTMPWORKER pfnWorker, void *pvUser1, void *pvUser2)
 {
-#if __FreeBSD_version >= 900000
-    cpuset_t    Mask;
-#elif  __FreeBSD_version >= 700000
-    cpumask_t   Mask;
+#if __FreeBSD_version >= 700000
+    cpuset_t    Cpus;
 #endif
     RTMPARGS    Args;
 
@@ -244,16 +257,14 @@ RTDECL(int) RTMpOnSpecific(RTCPUID idCpu, PFNRTMPWORKE
     Args.pvUser2 = pvUser2;
     Args.idCpu = idCpu;
     Args.cHits = 0;
+    IPRT_FREEBSD_SAVE_EFL_AC();
 #if __FreeBSD_version >= 700000
-# if __FreeBSD_version >= 900000
-    CPU_SETOF(idCpu, &Mask);
-# else
-    Mask = (cpumask_t)1 << idCpu;
-# endif
-    smp_rendezvous_cpus(Mask, NULL, rtmpOnSpecificFreeBSDWrapper, smp_no_rendevous_barrier, &Args);
+    CPU_SETOF(idCpu, &Cpus);
+    smp_rendezvous_cpus(Cpus, NULL, rtmpOnSpecificFreeBSDWrapper, smp_no_rendezvous_barrier, &Args);
 #else
     smp_rendezvous(NULL, rtmpOnSpecificFreeBSDWrapper, NULL, &Args);
 #endif
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return Args.cHits == 1
          ? VINF_SUCCESS
          : VERR_CPU_NOT_FOUND;
@@ -273,22 +284,16 @@ static void rtmpFreeBSDPokeCallback(void *pvArg)
 
 RTDECL(int) RTMpPokeCpu(RTCPUID idCpu)
 {
-#if __FreeBSD_version >= 900000
-    cpuset_t    Mask;
-#elif  __FreeBSD_version >= 700000
-    cpumask_t   Mask;
-#endif
+    cpuset_t    Cpus;
 
     /* Will panic if no rendezvousing cpus, so make sure the cpu is online. */
     if (!RTMpIsCpuOnline(idCpu))
         return VERR_CPU_NOT_FOUND;
 
-# if __FreeBSD_version >= 900000
-    CPU_SETOF(idCpu, &Mask);
-# else
-    Mask = (cpumask_t)1 << idCpu;
-# endif
-    smp_rendezvous_cpus(Mask, NULL, rtmpFreeBSDPokeCallback, smp_no_rendevous_barrier, NULL);
+    IPRT_FREEBSD_SAVE_EFL_AC();
+    CPU_SETOF(idCpu, &Cpus);
+    smp_rendezvous_cpus(Cpus, NULL, rtmpFreeBSDPokeCallback, smp_no_rendezvous_barrier, NULL);
+    IPRT_FREEBSD_RESTORE_EFL_AC();
 
     return VINF_SUCCESS;
 }
