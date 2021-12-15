--- src/vulkan.cpp.orig	2021-07-08 06:23:59 UTC
+++ src/vulkan.cpp
@@ -33,7 +33,7 @@
 #include <vector>
 #include <list>
 #include <array>
-#ifdef __gnu_linux__
+#ifndef _WIN32
 #include <libgen.h>
 #include <unistd.h>
 #endif
@@ -464,10 +464,10 @@ struct overlay_draw *get_overlay_draw(struct swapchain
 
 void init_cpu_stats(overlay_params& params)
 {
-#ifdef __gnu_linux__
    auto& enabled = params.enabled;
    enabled[OVERLAY_PARAM_ENABLED_cpu_stats] = cpuStats.Init()
                            && enabled[OVERLAY_PARAM_ENABLED_cpu_stats];
+#ifdef __gnu_linux__
    enabled[OVERLAY_PARAM_ENABLED_cpu_temp] = cpuStats.GetCpuFile()
                            && enabled[OVERLAY_PARAM_ENABLED_cpu_temp];
    enabled[OVERLAY_PARAM_ENABLED_cpu_power] = cpuStats.InitCpuPowerData()
@@ -600,21 +600,21 @@ void init_gpu_stats(uint32_t& vendorID, overlay_params
 }
 
 void init_system_info(){
-   #ifdef __gnu_linux__
       const char* ld_preload = getenv("LD_PRELOAD");
       if (ld_preload)
          unsetenv("LD_PRELOAD");
 
-      ram =  exec("cat /proc/meminfo | grep 'MemTotal' | awk '{print $2}'");
-      trim(ram);
-      cpu =  exec("cat /proc/cpuinfo | grep 'model name' | tail -n1 | sed 's/^.*: //' | sed 's/([^)]*)/()/g' | tr -d '(/)'");
-      trim(cpu);
-      kernel = exec("uname -r");
-      trim(kernel);
-      os = exec("cat /etc/*-release | grep 'PRETTY_NAME' | cut -d '=' -f 2-");
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
@@ -669,6 +669,8 @@ void init_system_info(){
       else {
            wineVersion = "";
       }
+
+#ifdef __gnu_linux__
       // check for gamemode and vkbasalt
       stringstream ss;
       string line;
@@ -686,6 +688,7 @@ void init_system_info(){
          if (HUDElements.gamemode_bol && HUDElements.vkbasalt_bol)
             break;
       }
+#endif
 
       if (ld_preload)
          setenv("LD_PRELOAD", ld_preload, 1);
@@ -697,7 +700,6 @@ void init_system_info(){
                 << "Gpu:" << gpu << "\n"
                 << "Driver:" << driver << "\n"
                 << "CPU Scheduler:" << cpusched << std::endl;
-#endif
 #endif
 }
 
