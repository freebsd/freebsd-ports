--- src/foundation/system_info.c.orig	2026-06-17 01:27:28 UTC
+++ src/foundation/system_info.c
@@ -95,7 +95,7 @@ static cbm_system_info_t detect_system_bsd(void) {
     info.total_cores = nprocs > 0 ? (int)nprocs : 1;
     info.perf_cores = info.total_cores;
 
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
     int mib[2] = {CTL_HW, HW_PHYSMEM};
 #else
     int mib[2] = {CTL_HW, HW_PHYSMEM64};
