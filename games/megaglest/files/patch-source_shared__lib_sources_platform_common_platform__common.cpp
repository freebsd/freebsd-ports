--- source/shared_lib/sources/platform/common/platform_common.cpp.orig	2016-04-02 12:36:57 UTC
+++ source/shared_lib/sources/platform/common/platform_common.cpp
@@ -124,7 +124,7 @@ tm threadsafe_localtime(const time_t &ti
 // extracting std::time_t from std:chrono for "now"
 time_t systemtime_now() {
 #if __cplusplus > 199711L
-	system_time_point system_now = std::chrono::system_clock::now();
+	auto system_now = std::chrono::system_clock::now();
 	return std::chrono::system_clock::to_time_t(system_now);
 #else
 	return time(NULL);
