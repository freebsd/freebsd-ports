--- third_party/abseil-cpp/absl/base/internal/sysinfo.cc.orig	2023-11-29 21:40:09 UTC
+++ third_party/abseil-cpp/absl/base/internal/sysinfo.cc
@@ -30,7 +30,7 @@
 #include <sys/syscall.h>
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <sys/sysctl.h>
 #endif
 
@@ -194,6 +194,7 @@ static double GetNominalCPUFrequency() {
 
 #else
 
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 // Helper function for reading a long from a file. Returns true if successful
 // and the memory location pointed to by value is set to the value read.
 static bool ReadLongFromFile(const char *file, long *value) {
@@ -226,6 +227,7 @@ static bool ReadLongFromFile(const char *file, long *v
   }
   return ret;
 }
+#endif
 
 #if defined(ABSL_INTERNAL_UNSCALED_CYCLECLOCK_FREQUENCY_IS_CPU_FREQUENCY)
 
@@ -325,9 +327,11 @@ static double GetNominalCPUFrequency() {
   // a new mode (turbo mode). Essentially, those frequencies cannot
   // always be relied upon. The same reasons apply to /proc/cpuinfo as
   // well.
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) // pledge violation
   if (ReadLongFromFile("/sys/devices/system/cpu/cpu0/tsc_freq_khz", &freq)) {
     return freq * 1e3;  // Value is kHz.
   }
+#endif
 
 #if defined(ABSL_INTERNAL_UNSCALED_CYCLECLOCK_FREQUENCY_IS_CPU_FREQUENCY)
   // On these platforms, the TSC frequency is the nominal CPU
@@ -346,10 +350,12 @@ static double GetNominalCPUFrequency() {
   // If CPU scaling is in effect, we want to use the *maximum*
   // frequency, not whatever CPU speed some random processor happens
   // to be using now.
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) // pledge violation
   if (ReadLongFromFile("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq",
                        &freq)) {
     return freq * 1e3;  // Value is kHz.
   }
+#endif
 
   return 1.0;
 #endif  // !ABSL_INTERNAL_UNSCALED_CYCLECLOCK_FREQUENCY_IS_CPU_FREQUENCY
@@ -459,6 +465,12 @@ pid_t GetTID() {
   static_assert(sizeof(pid_t) == sizeof(thread),
                 "In NaCL int expected to be the same size as a pointer");
   return reinterpret_cast<pid_t>(thread);
+}
+
+#elif defined(__OpenBSD__)
+
+pid_t GetTID() {
+  return getthrid();
 }
 
 #else
