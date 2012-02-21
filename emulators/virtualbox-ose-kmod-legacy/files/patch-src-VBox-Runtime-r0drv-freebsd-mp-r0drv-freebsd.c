--- src/VBox/Runtime/r0drv/freebsd/mp-r0drv-freebsd.c.orig	2011-05-16 12:33:52.000000000 -0400
+++ src/VBox/Runtime/r0drv/freebsd/mp-r0drv-freebsd.c	2011-06-24 13:57:31.000000000 -0400
@@ -163,17 +163,26 @@ RTDECL(int) RTMpOnOthers(PFNRTMPWORKER p
     /* Will panic if no rendezvousing cpus, so check up front. */
     if (RTMpGetOnlineCount() > 1)
     {
-#if  __FreeBSD_version >= 700000
-        cpumask_t   Mask = ~(cpumask_t)curcpu;
+#if __FreeBSD_version >= 900000
+        cpuset_t    Mask;
+#elif __FreeBSD_version >= 700000
+        cpumask_t   Mask;
 #endif
+        RTCPUID     idCpu = curcpu;
         RTMPARGS    Args;
 
         Args.pfnWorker = pfnWorker;
         Args.pvUser1 = pvUser1;
         Args.pvUser2 = pvUser2;
-        Args.idCpu = RTMpCpuId();
+        Args.idCpu = idCpu;
         Args.cHits = 0;
 #if __FreeBSD_version >= 700000
+        Mask = all_cpus;
+#if __FreeBSD_version >= 900000
+        CPU_CLR(idCpu, &Mask);
+#else
+        Mask &= ~((cpumask_t)1 << idCpu);
+#endif
         smp_rendezvous_cpus(Mask, NULL, rtmpOnOthersFreeBSDWrapper, smp_no_rendevous_barrier, &Args);
 #else
         smp_rendezvous(NULL, rtmpOnOthersFreeBSDWrapper, NULL, &Args);
@@ -203,8 +212,10 @@ static void rtmpOnSpecificFreeBSDWrapper
 
 RTDECL(int) RTMpOnSpecific(RTCPUID idCpu, PFNRTMPWORKER pfnWorker, void *pvUser1, void *pvUser2)
 {
-#if  __FreeBSD_version >= 700000
-    cpumask_t   Mask = 1 << idCpu;
+#if __FreeBSD_version >= 900000
+    cpuset_t    Mask;
+#elif __FreeBSD_version >= 700000
+    cpumask_t   Mask;
 #endif
     RTMPARGS    Args;
 
@@ -218,7 +229,11 @@ RTDECL(int) RTMpOnSpecific(RTCPUID idCpu
     Args.idCpu = idCpu;
     Args.cHits = 0;
 #if __FreeBSD_version >= 700000
+#if __FreeBSD_version >= 900000
+    CPU_SETOF(idCpu, &Mask);
+#else
     Mask = (cpumask_t)1 << idCpu;
+#endif
     smp_rendezvous_cpus(Mask, NULL, rtmpOnSpecificFreeBSDWrapper, smp_no_rendevous_barrier, &Args);
 #else
     smp_rendezvous(NULL, rtmpOnSpecificFreeBSDWrapper, NULL, &Args);
@@ -242,13 +257,21 @@ static void rtmpFreeBSDPokeCallback(void
 
 RTDECL(int) RTMpPokeCpu(RTCPUID idCpu)
 {
+#if __FreeBSD_version >= 900000
+    cpuset_t    Mask;
+#else
     cpumask_t   Mask;
+#endif
 
     /* Will panic if no rendezvousing cpus, so make sure the cpu is online. */
     if (!RTMpIsCpuOnline(idCpu))
         return VERR_CPU_NOT_FOUND;
 
+#if __FreeBSD_version >= 900000
+    CPU_SETOF(idCpu, &Mask);
+#else
     Mask = (cpumask_t)1 << idCpu;
+#endif
     smp_rendezvous_cpus(Mask, NULL, rtmpFreeBSDPokeCallback, smp_no_rendevous_barrier, NULL);
 
     return VINF_SUCCESS;
