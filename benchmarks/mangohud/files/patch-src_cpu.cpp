--- src/cpu.cpp.orig	2021-07-08 06:23:59 UTC
+++ src/cpu.cpp
@@ -227,6 +227,7 @@ bool CPUStats::UpdateCPUData()
 
 bool CPUStats::UpdateCoreMhz() {
     m_coreMhz.clear();
+#if defined(__linux__)
     std::ifstream cpuInfo(PROCCPUINFOFILE);
     std::string row;
     size_t i = 0;
@@ -238,6 +239,13 @@ bool CPUStats::UpdateCoreMhz() {
             i++;
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
         m_cpuDataTotal.cpu_mhz += data.mhz;
@@ -246,6 +254,7 @@ bool CPUStats::UpdateCoreMhz() {
 }
 
 bool CPUStats::UpdateCpuTemp() {
+#if defined(__linux__)
     if (!m_cpuTempFile)
         return false;
 
@@ -256,6 +265,23 @@ bool CPUStats::UpdateCpuTemp() {
     m_cpuDataTotal.temp = temp / 1000;
 
     return ret;
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
 
 static bool get_cpu_power_k10temp(CPUPowerData* cpuPowerData, int& power) {
@@ -407,6 +433,7 @@ static bool find_fallback_temp_input(const std::string
     return false;
 }
 
+#ifdef __linux__
 bool CPUStats::GetCpuFile() {
     if (m_cpuTempFile)
         return true;
@@ -447,6 +474,7 @@ bool CPUStats::GetCpuFile() {
     }
     return true;
 }
+#endif
 
 static bool find_input(const std::string& path, const char* input_prefix, std::string& input, const std::string& name)
 {
