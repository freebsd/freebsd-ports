--- src/overlay.cpp.orig	2023-04-13 17:40:23 UTC
+++ src/overlay.cpp
@@ -106,11 +106,11 @@ void update_hw_info(const struct overlay_params& param
    if (params.enabled[OVERLAY_PARAM_ENABLED_cpu_stats] || logger->is_active()) {
       cpuStats.UpdateCPUData();
 
-#ifdef __linux__
       if (params.enabled[OVERLAY_PARAM_ENABLED_core_load] || params.enabled[OVERLAY_PARAM_ENABLED_cpu_mhz])
          cpuStats.UpdateCoreMhz();
       if (params.enabled[OVERLAY_PARAM_ENABLED_cpu_temp] || logger->is_active() || params.enabled[OVERLAY_PARAM_ENABLED_graphs])
          cpuStats.UpdateCpuTemp();
+#ifdef __linux__
       if (params.enabled[OVERLAY_PARAM_ENABLED_cpu_power])
          cpuStats.UpdateCpuPower();
 #endif
@@ -928,6 +928,7 @@ std::string get_device_name(uint32_t vendorID, uint32_
 }
 
 void update_fan(){
+#ifdef __linux__
    // This just handles steam deck fan for now
    static bool init;
    string hwmon_path;
@@ -948,6 +949,7 @@ void update_fan(){
       fan_speed = stoi(read_line(hwmon_path));
    else
       fan_speed = -1;
+#endif
 }
 
 void next_hud_position(struct overlay_params& params){
