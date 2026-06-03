- CLOCK_MONOTONIC_RAW is not available on FreeBSD

--- src/Rack/src/system.cpp.orig	2025-06-22 11:39:38 UTC
+++ src/Rack/src/system.cpp
@@ -770,7 +770,11 @@ static void initTime() {
 #endif
 #if defined ARCH_LIN
 	struct timespec ts;
+#ifdef __FreeBSD__
+	clock_gettime(CLOCK_MONOTONIC_PRECISE, &ts);
+#else
 	clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
+#endif
 	startTime = int64_t(ts.tv_sec) * 1000000000LL + ts.tv_nsec;
 #endif
 #if defined ARCH_MAC
@@ -790,7 +794,11 @@ double getTime() {
 	return (counter.QuadPart - startCounter) * counterTime;
 #elif defined ARCH_LIN
 	struct timespec ts;
+#ifdef __FreeBSD__
+	clock_gettime(CLOCK_MONOTONIC_PRECISE, &ts);
+#else
 	clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
+#endif
 	int64_t time = int64_t(ts.tv_sec) * 1000000000LL + ts.tv_nsec;
 	return (time - startTime) / 1e9;
 #elif defined ARCH_MAC
