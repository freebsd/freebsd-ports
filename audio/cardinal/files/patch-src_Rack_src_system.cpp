- CLOCK_MONOTONIC_RAW is not available on FreeBSD

--- src/Rack/src/system.cpp.orig	2022-02-06 00:32:17 UTC
+++ src/Rack/src/system.cpp
@@ -742,7 +742,11 @@ static void initTime() {
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
@@ -763,7 +767,11 @@ double getTime() {
 #endif
 #if defined ARCH_LIN
 	struct timespec ts;
+#ifdef __FreeBSD__
+	clock_gettime(CLOCK_MONOTONIC_PRECISE, &ts);
+#else
 	clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
+#endif
 	int64_t time = int64_t(ts.tv_sec) * 1000000000LL + ts.tv_nsec;
 	return (time - startTime) / 1e9;
 #endif
