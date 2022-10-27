--- common/Linux/LnxMisc.cpp.orig	2022-10-20 13:57:30 UTC
+++ common/Linux/LnxMisc.cpp
@@ -72,6 +72,8 @@ std::string GetOSVersionString()
 
 static bool SetScreensaverInhibitX11(const WindowInfo& wi, bool inhibit)
 {
+	extern char **environ;
+
 	const char* command = "xdg-screensaver";
 	const char* operation = inhibit ? "suspend" : "resume";
 	std::string id = fmt::format("0x{:X}", static_cast<u64>(reinterpret_cast<uintptr_t>(wi.window_handle)));
