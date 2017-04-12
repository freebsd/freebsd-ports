--- src/VBox/Runtime/r0drv/freebsd/mp-r0drv-freebsd.c.orig	2017-03-15 19:18:08 UTC
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
@@ -155,7 +164,7 @@ RTDECL(int) RTMpOnAll(PFNRTMPWORKER pfnW
     Args.pvUser2 = pvUser2;
     Args.idCpu = NIL_RTCPUID;
     Args.cHits = 0;
-    smp_rendezvous(NULL, rtmpOnAllFreeBSDWrapper, smp_no_rendevous_barrier, &Args);
+    smp_rendezvous(NULL, rtmpOnAllFreeBSDWrapper, smp_no_rendezvous_barrier, &Args);
     return VINF_SUCCESS;
 }
 
@@ -180,10 +189,8 @@ RTDECL(int) RTMpOnOthers(PFNRTMPWORKER p
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
 
@@ -193,13 +200,9 @@ RTDECL(int) RTMpOnOthers(PFNRTMPWORKER p
         Args.idCpu = RTMpCpuId();
         Args.cHits = 0;
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
@@ -228,10 +231,8 @@ static void rtmpOnSpecificFreeBSDWrapper
 
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
 
@@ -245,12 +246,8 @@ RTDECL(int) RTMpOnSpecific(RTCPUID idCpu
     Args.idCpu = idCpu;
     Args.cHits = 0;
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
@@ -273,22 +270,14 @@ static void rtmpFreeBSDPokeCallback(void
 
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
+    CPU_SETOF(idCpu, &Cpus);
+    smp_rendezvous_cpus(Cpus, NULL, rtmpFreeBSDPokeCallback, smp_no_rendezvous_barrier, NULL);
 
     return VINF_SUCCESS;
 }
