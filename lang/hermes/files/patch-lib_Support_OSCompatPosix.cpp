--- lib/Support/OSCompatPosix.cpp.orig	2020-08-03 19:19:06 UTC
+++ lib/Support/OSCompatPosix.cpp
@@ -23,6 +23,11 @@
 #endif
 #endif // __linux__
 
+#if defined(__FreeBSD__)
+#include <pthread.h>
+#include <pthread_np.h>
+#endif
+
 #include <sys/types.h>
 #include <unistd.h>
 
@@ -213,7 +218,7 @@ void vm_unused(void *p, size_t sz) {
 /// the process's physical footprint.
 #define MADV_UNUSED MADV_FREE
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
 /// On linux, telling the OS that we \p MADV_DONTNEED some pages will cause it
 /// to immediately deduct their size from the process's resident set.
@@ -414,6 +419,12 @@ uint64_t thread_id() {
   return syscall(__NR_gettid);
 }
 
+#elif defined(__FreeBSD__)
+
+uint64_t thread_id() {
+  return reinterpret_cast<uint64_t>(pthread_self());
+}
+
 #else
 #error "Thread ID not supported on this platform"
 #endif
@@ -443,7 +454,7 @@ std::chrono::microseconds thread_cpu_time() {
   return microseconds(total);
 }
 
-#elif defined(__linux__) // !(__APPLE__ && __MACH__)
+#elif defined(__linux__) || defined(__FreeBSD__) // !(__APPLE__ && __MACH__)
 
 std::chrono::microseconds thread_cpu_time() {
   using namespace std::chrono;
@@ -480,7 +491,7 @@ bool thread_page_fault_count(int64_t *outMinorFaults, 
   return kr == KERN_SUCCESS;
 }
 
-#elif defined(__linux__) // !(__APPLE__ && __MACH__)
+#elif defined(__linux__) || defined(__FreeBSD__) // !(__APPLE__ && __MACH__)
 
 bool thread_page_fault_count(int64_t *outMinorFaults, int64_t *outMajorFaults) {
   struct rusage stats = {};
