--- src/VBox/Main/src-server/freebsd/PerformanceFreeBSD.cpp.orig	2025-08-13 19:51:28 UTC
+++ src/VBox/Main/src-server/freebsd/PerformanceFreeBSD.cpp
@@ -90,8 +90,10 @@ int CollectorFreeBSD::getHostMemoryUsage(ULONG *total,
     cbParameter = sizeof(cPagesMemInactive);
     if (!sysctlbyname("vm.stats.vm.v_inactive_count", &cPagesMemInactive, &cbParameter, NULL, 0))
         cProcessed++;
+#if __FreeBSD_version < 1200016
     cbParameter = sizeof(cPagesMemCached);
     if (!sysctlbyname("vm.stats.vm.v_cache_count", &cPagesMemCached, &cbParameter, NULL, 0))
+#endif
         cProcessed++;
     cbParameter = sizeof(cbPage);
     if (!sysctlbyname("hw.pagesize", &cbPage, &cbParameter, NULL, 0))
@@ -100,8 +102,8 @@ int CollectorFreeBSD::getHostMemoryUsage(ULONG *total,
     if (cProcessed == 6)
     {
         *total     = cbMemPhys / _1K;
-        *used      = cPagesMemUsed * (cbPage / _1K);
-        *available = (cPagesMemFree + cPagesMemInactive + cPagesMemCached ) * (cbPage / _1K);
+        *used      = (uint64_t)cPagesMemUsed * (cbPage / _1K);
+        *available = ((uint64_t)cPagesMemFree + cPagesMemInactive + cPagesMemCached) * (cbPage / _1K);
     }
     else
         vrc = VERR_NOT_SUPPORTED;
