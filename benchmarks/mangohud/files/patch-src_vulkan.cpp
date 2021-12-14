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
@@ -600,21 +600,24 @@ void init_gpu_stats(uint32_t& vendorID, overlay_params
 }
 
 void init_system_info(){
-   #ifdef __gnu_linux__
       const char* ld_preload = getenv("LD_PRELOAD");
       if (ld_preload)
          unsetenv("LD_PRELOAD");
 
-      ram =  exec("cat /proc/meminfo | grep 'MemTotal' | awk '{print $2}'");
+      ram = exec("grep MemTotal " PROCDIR "/meminfo | awk '{print $2}'");
       trim(ram);
-      cpu =  exec("cat /proc/cpuinfo | grep 'model name' | tail -n1 | sed 's/^.*: //' | sed 's/([^)]*)/()/g' | tr -d '(/)'");
+      cpu = exec("grep 'model name' " PROCDIR "/cpuinfo | tail -n1 | sed 's/^.*: //' | sed 's/([^)]*)/()/g' | tr -d '(/)'");
       trim(cpu);
       kernel = exec("uname -r");
       trim(kernel);
       os = exec("cat /etc/*-release | grep 'PRETTY_NAME' | cut -d '=' -f 2-");
       os.erase(remove(os.begin(), os.end(), '\"' ), os.end());
       trim(os);
-      cpusched = read_line("/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor");
+      gpu = exec("pciconf -lv | grep -A2 ^vgapci0 | tail -1 | cut -d\\' -f2");
+      trim(gpu);
+      driver = exec("glxinfo -B | grep 'OpenGL version' | sed 's/^.*: //'");
+      trim(driver);
+      cpusched = exec("sysctl -b kern.sched.name");
 
       const char* mangohud_recursion = getenv("MANGOHUD_RECURSION");
       if (!mangohud_recursion) {
@@ -669,6 +672,8 @@ void init_system_info(){
       else {
            wineVersion = "";
       }
+
+#ifdef __gnu_linux__
       // check for gamemode and vkbasalt
       stringstream ss;
       string line;
@@ -686,6 +691,7 @@ void init_system_info(){
          if (HUDElements.gamemode_bol && HUDElements.vkbasalt_bol)
             break;
       }
+#endif
 
       if (ld_preload)
          setenv("LD_PRELOAD", ld_preload, 1);
@@ -697,7 +703,6 @@ void init_system_info(){
                 << "Gpu:" << gpu << "\n"
                 << "Driver:" << driver << "\n"
                 << "CPU Scheduler:" << cpusched << std::endl;
-#endif
 #endif
 }
 
