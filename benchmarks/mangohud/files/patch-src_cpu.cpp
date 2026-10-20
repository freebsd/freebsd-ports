--- src/cpu.cpp.orig	2023-04-13 17:40:23 UTC
+++ src/cpu.cpp
@@ -225,6 +225,7 @@ bool CPUStats::UpdateCPUData()
 
 bool CPUStats::UpdateCoreMhz() {
     m_coreMhz.clear();
+#if defined(__linux__)
     FILE *fp;
     for (auto& cpu : m_cpuData)
     {
@@ -237,6 +238,13 @@ bool CPUStats::UpdateCoreMhz() {
             fclose(fp);
         }
     }
+#elif defined(__FreeBSD__)
+    char sysctl_name[32];
+    for (int i = 0; i < m_cpuData.size(); i++) {
+        snprintf(sysctl_name, sizeof(sysctl_name), "dev.cpu.%d.freq", i);
+        m_cpuData[i].mhz = read_sysctl<int>(sysctl_name);
+    }
+#endif
 
     m_cpuDataTotal.cpu_mhz = 0;
     for (auto data : m_cpuData)
@@ -259,6 +267,7 @@ bool CPUStats::ReadcpuTempFile(int& temp) {
 }
 
 bool CPUStats::UpdateCpuTemp() {
+#if defined(__linux__)
 	if (cpu_type == "APU"){
         m_cpuDataTotal.temp = gpu_info.apu_cpu_temp;
         return true;
@@ -269,6 +278,23 @@ bool CPUStats::UpdateCpuTemp() {
 
         return ret;
     }
+#elif defined(__FreeBSD__)
+    char sysctl_name[32];
+    int dK, i, temp;
+    for (temp = i = 0; i < m_cpuData.size(); i++) {
+        snprintf(sysctl_name, sizeof(sysctl_name), "dev.cpu.%d.temperature", i);
+        dK = read_sysctl<int>(sysctl_name);
+        if (dK < 0) {
+            // If we could not read some core's temperature, store
+            // the last read (bogus) value and return false early.
+            m_cpuDataTotal.temp = dK;
+            return false;
+        }
+        temp += dK - 2731;
+    }
+    m_cpuDataTotal.temp = temp / (10 * m_cpuData.size());
+    return m_cpuDataTotal.temp > 0;
+#endif
 }
 
 static bool get_cpu_power_k10temp(CPUPowerData* cpuPowerData, float& power) {
@@ -426,6 +452,7 @@ static bool find_fallback_input(const std::string& pat
     return false;
 }
 
+#ifdef __linux__
 bool CPUStats::GetCpuFile() {
     if (m_cpuTempFile)
         return true;
@@ -466,6 +493,7 @@ bool CPUStats::GetCpuFile() {
     }
     return true;
 }
+#endif
 
 static CPUPowerData_k10temp* init_cpu_power_data_k10temp(const std::string path) {
     auto powerData = std::make_unique<CPUPowerData_k10temp>();
