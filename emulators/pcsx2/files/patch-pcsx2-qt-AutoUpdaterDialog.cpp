--- pcsx2-qt/AutoUpdaterDialog.cpp.orig	2025-06-11 12:23:15 UTC
+++ pcsx2-qt/AutoUpdaterDialog.cpp
@@ -53,6 +53,8 @@ static constexpr u32 HTTP_POLL_INTERVAL = 10;
 #define UPDATE_PLATFORM_STR "Linux"
 #elif defined(__APPLE__)
 #define UPDATE_PLATFORM_STR "MacOS"
+#elif defined(__FreeBSD__)
+#define UPDATE_PLATFORM_STR "FreeBSD"
 #endif
 
 #ifdef MULTI_ISA_SHARED_COMPILATION
