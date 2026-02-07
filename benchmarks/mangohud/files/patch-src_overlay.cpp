--- src/overlay.cpp.orig	2021-07-08 06:23:59 UTC
+++ src/overlay.cpp
@@ -28,12 +28,11 @@ void update_hw_info(struct swapchain_stats& sw_stats, 
     }
    if (params.enabled[OVERLAY_PARAM_ENABLED_cpu_stats] || logger->is_active()) {
       cpuStats.UpdateCPUData();
-#ifdef __gnu_linux__
-
       if (params.enabled[OVERLAY_PARAM_ENABLED_core_load] || params.enabled[OVERLAY_PARAM_ENABLED_cpu_mhz])
          cpuStats.UpdateCoreMhz();
       if (params.enabled[OVERLAY_PARAM_ENABLED_cpu_temp] || logger->is_active() || params.enabled[OVERLAY_PARAM_ENABLED_graphs])
          cpuStats.UpdateCpuTemp();
+#ifdef __gnu_linux__
       if (params.enabled[OVERLAY_PARAM_ENABLED_cpu_power])
          cpuStats.UpdateCpuPower();
 #endif
