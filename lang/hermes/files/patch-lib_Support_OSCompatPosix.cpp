--- lib/Support/OSCompatPosix.cpp.orig	2024-08-15 07:17:16 UTC
+++ lib/Support/OSCompatPosix.cpp
@@ -24,6 +24,11 @@
 #define RUSAGE_THREAD 1
 #endif
 #endif // __linux__
+ 
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#define pthread_getattr_np pthread_attr_get_np
+#endif
 
 #include <pthread.h>
 #include <sys/types.h>
@@ -221,7 +226,7 @@ static constexpr int kVMReserveFlags =
 
 static constexpr int kVMReserveProt = PROT_NONE;
 static constexpr int kVMReserveFlags =
-    MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE;
+    MAP_PRIVATE | MAP_ANONYMOUS;
 
 llvh::ErrorOr<void *>
 vm_reserve_aligned(size_t sz, size_t alignment, void *hint) {
@@ -269,7 +274,7 @@ void vm_unused(void *p, size_t sz) {
 /// the process's physical footprint.
 #define MADV_UNUSED MADV_FREE
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
 /// On linux, telling the OS that we \p MADV_DONTNEED some pages will cause it
 /// to immediately deduct their size from the process's resident set.
@@ -603,6 +608,12 @@ uint64_t global_thread_id() {
   return syscall(__NR_gettid);
 }
 
+#elif defined(__FreeBSD__)
+
+uint64_t global_thread_id() {
+  return reinterpret_cast<uint64_t>(pthread_self());
+}
+
 #else
 #error "Thread ID not supported on this platform"
 #endif
@@ -685,7 +696,7 @@ std::chrono::microseconds thread_cpu_time() {
   return microseconds(total);
 }
 
-#elif defined(__linux__) // !(__APPLE__ && __MACH__)
+#elif defined(__linux__) || defined(__FreeBSD__) // !(__APPLE__ && __MACH__)
 
 std::chrono::microseconds thread_cpu_time() {
   using namespace std::chrono;
@@ -722,7 +733,7 @@ bool thread_page_fault_count(int64_t *outMinorFaults, 
   return kr == KERN_SUCCESS;
 }
 
-#elif defined(__linux__) // !(__APPLE__ && __MACH__)
+#elif defined(__linux__) || defined(__FreeBSD__) // !(__APPLE__ && __MACH__)
 
 bool thread_page_fault_count(int64_t *outMinorFaults, int64_t *outMajorFaults) {
   struct rusage stats = {};
