https://github.com/Themaister/Granite/pull/135

--- ares/n64/vulkan/parallel-rdp/util/timer.cpp.orig	2024-07-28 10:49:58 UTC
+++ ares/n64/vulkan/parallel-rdp/util/timer.cpp
@@ -107,7 +107,7 @@ int64_t get_current_time_nsecs()
 	return int64_t(double(li.QuadPart) * static_qpc_freq.inv_freq);
 #else
 	struct timespec ts = {};
-#ifdef ANDROID
+#if defined(ANDROID) || defined(__FreeBSD__)
 	constexpr auto timebase = CLOCK_MONOTONIC;
 #else
 	constexpr auto timebase = CLOCK_MONOTONIC_RAW;
