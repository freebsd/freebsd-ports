--- flow/ThreadPrimitives.h.orig	2021-01-03 22:45:20 UTC
+++ flow/ThreadPrimitives.h
@@ -47,9 +47,9 @@
 
 // TODO: We should make this dependent on the CPU. Maybe cmake
 // can set this variable properly?
-constexpr size_t CACHE_LINE_SIZE = 64;
+constexpr size_t MAX_CACHE_LINE_SIZE = 64;
 
-class alignas(CACHE_LINE_SIZE) ThreadSpinLock {
+class alignas(MAX_CACHE_LINE_SIZE) ThreadSpinLock {
 public:
 // #ifdef _WIN32
 	ThreadSpinLock() {
@@ -90,7 +90,7 @@ class alignas(CACHE_LINE_SIZE) ThreadSpinLock { (priva
 	std::atomic_flag isLocked = ATOMIC_FLAG_INIT;
 	// We want a spin lock to occupy a cache line in order to
 	// prevent false sharing.
-	std::array<uint8_t, CACHE_LINE_SIZE - sizeof(isLocked)> padding;
+	std::array<uint8_t, MAX_CACHE_LINE_SIZE - sizeof(isLocked)> padding;
 };
 
 class ThreadSpinLockHolder {
