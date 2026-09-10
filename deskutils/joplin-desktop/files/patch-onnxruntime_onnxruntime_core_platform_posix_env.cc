--- onnxruntime/onnxruntime/core/platform/posix/env.cc.orig	2026-03-05 04:48:10 UTC
+++ onnxruntime/onnxruntime/core/platform/posix/env.cc
@@ -20,6 +20,7 @@ limitations under the License.
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <ftw.h>
+#include <pthread_np.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <stdio.h>
@@ -218,13 +219,13 @@ class PosixThread : public EnvThread {
         }
         auto ret = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
         if (0 == ret) {
-          LOGS_DEFAULT(VERBOSE) << "pthread_setaffinity_np succeed for thread: " << syscall(SYS_gettid)
+          LOGS_DEFAULT(VERBOSE) << "pthread_setaffinity_np succeed for thread: " << ::pthread_self()
                                 << ", index: " << p->index
                                 << ", mask: " << *p->affinity;
         } else {
           errno = ret;
           auto [err_no, err_msg] = GetErrnoInfo();
-          LOGS_DEFAULT(ERROR) << "pthread_setaffinity_np failed for thread: " << syscall(SYS_gettid)
+          LOGS_DEFAULT(ERROR) << "pthread_setaffinity_np failed for thread: " << ::pthread_self()
                               << ", index: " << p->index
                               << ", mask: " << *p->affinity
                               << ", error code: " << err_no << " error msg: " << err_msg
@@ -266,7 +267,7 @@ class PosixEnv : public Env {
 
   // Return the number of physical cores
   int GetNumPhysicalCpuCores() const override {
-#ifdef ORT_USE_CPUINFO
+#if defined(ORT_USE_CPUINFO) && !defined(__FreeBSD__)
     if (cpuinfo_available_) {
       return narrow<int>(cpuinfo_get_cores_count());
     }
@@ -276,7 +277,7 @@ class PosixEnv : public Env {
 
   std::vector<LogicalProcessors> GetDefaultThreadAffinities() const override {
     std::vector<LogicalProcessors> ret;
-#ifdef ORT_USE_CPUINFO
+#if defined(ORT_USE_CPUINFO) && !defined(__FreeBSD__)
     if (cpuinfo_available_) {
       auto num_phys_cores = cpuinfo_get_cores_count();
       ret.reserve(num_phys_cores);
@@ -614,7 +615,7 @@ class PosixEnv : public Env {
 
  private:
   Telemetry telemetry_provider_;
-#ifdef ORT_USE_CPUINFO
+#if defined(ORT_USE_CPUINFO) && !defined(__FreeBSD__)
   PosixEnv() {
     cpuinfo_available_ = cpuinfo_initialize();
     if (!cpuinfo_available_) {
