--- src/VBox/Runtime/r0drv/freebsd/mp-r0drv-freebsd.c.orig	2017-03-15 15:18:08 UTC
+++ src/VBox/Runtime/r0drv/freebsd/mp-r0drv-freebsd.c
@@ -36,6 +36,9 @@
 #include <iprt/cpuset.h>
 #include "r0drv/mp-r0drv.h"
 
+#if __FreeBSD_version < 1200028
+#define smp_no_rendezvous_barrier   smp_no_rendevous_barrier
+#endif
 
 RTDECL(RTCPUID) RTMpCpuId(void)
 {
@@ -155,7 +158,7 @@ RTDECL(int) RTMpOnAll(PFNRTMPWORKER pfnW
     Args.pvUser2 = pvUser2;
     Args.idCpu = NIL_RTCPUID;
     Args.cHits = 0;
-    smp_rendezvous(NULL, rtmpOnAllFreeBSDWrapper, smp_no_rendevous_barrier, &Args);
+    smp_rendezvous(NULL, rtmpOnAllFreeBSDWrapper, smp_no_rendezvous_barrier, &Args);
     return VINF_SUCCESS;
 }
 
@@ -199,7 +202,7 @@ RTDECL(int) RTMpOnOthers(PFNRTMPWORKER p
 # else
     Mask = ~(cpumask_t)curcpu;
 # endif
-        smp_rendezvous_cpus(Mask, NULL, rtmpOnOthersFreeBSDWrapper, smp_no_rendevous_barrier, &Args);
+        smp_rendezvous_cpus(Mask, NULL, rtmpOnOthersFreeBSDWrapper, smp_no_rendezvous_barrier, &Args);
 #else
         smp_rendezvous(NULL, rtmpOnOthersFreeBSDWrapper, NULL, &Args);
 #endif
@@ -250,7 +253,7 @@ RTDECL(int) RTMpOnSpecific(RTCPUID idCpu
 # else
     Mask = (cpumask_t)1 << idCpu;
 # endif
-    smp_rendezvous_cpus(Mask, NULL, rtmpOnSpecificFreeBSDWrapper, smp_no_rendevous_barrier, &Args);
+    smp_rendezvous_cpus(Mask, NULL, rtmpOnSpecificFreeBSDWrapper, smp_no_rendezvous_barrier, &Args);
 #else
     smp_rendezvous(NULL, rtmpOnSpecificFreeBSDWrapper, NULL, &Args);
 #endif
@@ -288,7 +291,7 @@ RTDECL(int) RTMpPokeCpu(RTCPUID idCpu)
 # else
     Mask = (cpumask_t)1 << idCpu;
 # endif
-    smp_rendezvous_cpus(Mask, NULL, rtmpFreeBSDPokeCallback, smp_no_rendevous_barrier, NULL);
+    smp_rendezvous_cpus(Mask, NULL, rtmpFreeBSDPokeCallback, smp_no_rendezvous_barrier, NULL);
 
     return VINF_SUCCESS;
 }
