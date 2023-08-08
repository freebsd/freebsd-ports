--- tests/common/systemtime.cpp.orig	2023-06-28 01:31:14 UTC
+++ tests/common/systemtime.cpp
@@ -118,7 +118,7 @@ SystemTime getSystemTime()
 {
 	timespec t;
 	CompilerMemBar();
-	if (clock_gettime(CLOCK_MONOTONIC_RAW, &t) != 0) {
+	if (clock_gettime(CLOCK_MONOTONIC, &t) != 0) {
 		t.tv_sec = (time_t)-1;
 		t.tv_nsec = -1;
 	}
@@ -131,7 +131,7 @@ double getTimeDelta(SystemTime start)
 {
 	timespec t;
 	CompilerMemBar();
-	if ((start.tv_sec == (time_t)-1 && start.tv_nsec == -1) || clock_gettime(CLOCK_MONOTONIC_RAW, &t) != 0) {
+	if ((start.tv_sec == (time_t)-1 && start.tv_nsec == -1) || clock_gettime(CLOCK_MONOTONIC, &t) != 0) {
 		return -1;
 	}
 	CompilerMemBar();
