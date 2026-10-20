--- src/overlay.cpp.orig	2023-04-13 17:40:23 UTC
+++ src/overlay.cpp
@@ -25,7 +25,7 @@
 #include "amdgpu.h"
 
 
-#ifdef __linux__
+#ifndef _WIN32
 #include <libgen.h>
 #include <unistd.h>
 #endif
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
@@ -646,10 +646,10 @@ void render_imgui(swapchain_stats& data, struct overla
 
 void init_cpu_stats(overlay_params& params)
 {
-#ifdef __linux__
    auto& enabled = params.enabled;
    enabled[OVERLAY_PARAM_ENABLED_cpu_stats] = cpuStats.Init()
                            && enabled[OVERLAY_PARAM_ENABLED_cpu_stats];
+#ifdef __linux__
    enabled[OVERLAY_PARAM_ENABLED_cpu_temp] = cpuStats.GetCpuFile()
                            && enabled[OVERLAY_PARAM_ENABLED_cpu_temp];
    enabled[OVERLAY_PARAM_ENABLED_cpu_power] = cpuStats.InitCpuPowerData()
@@ -809,21 +809,21 @@ void init_gpu_stats(uint32_t& vendorID, uint32_t repor
 }
 
 void init_system_info(){
-   #ifdef __linux__
       const char* ld_preload = getenv("LD_PRELOAD");
       if (ld_preload)
          unsetenv("LD_PRELOAD");
 
-      ram =  exec("sed -n 's/^MemTotal: *\\([0-9]*\\).*/\\1/p' /proc/meminfo");
-      trim(ram);
-      cpu =  exec("sed -n 's/^model name.*: \\(.*\\)/\\1/p' /proc/cpuinfo | sed 's/([^)]*)//g' | tail -n1");
-      trim(cpu);
-      kernel = exec("uname -r");
-      trim(kernel);
-      os = exec("sed -n 's/PRETTY_NAME=\\(.*\\)/\\1/p' /etc/*-release");
-      os.erase(remove(os.begin(), os.end(), '\"' ), os.end());
-      trim(os);
-      cpusched = read_line("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor");
+      ram = to_string(sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE)
+            / 1024 / 1024) + " MB";
+      cpu = read_sysctl<string>("hw.model");
+      kernel = to_string(read_sysctl<int>("kern.osreldate"));
+      os = read_sysctl<string>("kern.ostype") + " " +
+           read_sysctl<string>("kern.osrelease");
+      gpu = exec("pciconf -lv | grep -A2 ^vgapci0 | tail -1 | cut -d\\' -f2");
+      trim(gpu);
+      driver = exec("glxinfo -B | grep 'OpenGL version' | sed 's/^.*: //'");
+      trim(driver);
+      cpusched = read_sysctl<string>("kern.sched.name");
 
       const char* mangohud_recursion = getenv("MANGOHUD_RECURSION");
       if (!mangohud_recursion) {
@@ -882,6 +882,8 @@ void init_system_info(){
       else {
            wineVersion = "";
       }
+
+#ifdef __linux__
       // check for gamemode and vkbasalt
       fs::path path("/proc/self/map_files/");
       for (auto& p : fs::directory_iterator(path)) {
@@ -894,6 +896,7 @@ void init_system_info(){
          if (HUDElements.gamemode_bol && HUDElements.vkbasalt_bol)
             break;
       }
+#endif
 
       if (ld_preload)
          setenv("LD_PRELOAD", ld_preload, 1);
@@ -904,7 +907,6 @@ void init_system_info(){
       SPDLOG_DEBUG("Os:{}", os);
       SPDLOG_DEBUG("Driver:{}", driver);
       SPDLOG_DEBUG("CPU Scheduler:{}", cpusched);
-#endif
 }
 
 std::string get_device_name(uint32_t vendorID, uint32_t deviceID)
@@ -928,6 +930,7 @@ std::string get_device_name(uint32_t vendorID, uint32_
 }
 
 void update_fan(){
+#ifdef __linux__
    // This just handles steam deck fan for now
    static bool init;
    string hwmon_path;
@@ -948,6 +951,7 @@ void update_fan(){
       fan_speed = stoi(read_line(hwmon_path));
    else
       fan_speed = -1;
+#endif
 }
 
 void next_hud_position(struct overlay_params& params){
