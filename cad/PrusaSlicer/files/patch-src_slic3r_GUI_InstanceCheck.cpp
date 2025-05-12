--- src/slic3r/GUI/InstanceCheck.cpp.orig	2025-04-10 11:26:51 UTC
+++ src/slic3r/GUI/InstanceCheck.cpp
@@ -31,7 +31,7 @@
 #include <strsafe.h>
 #endif //WIN32
 
-#if __linux__
+#if defined(__linux__) || defined (__FreeBSD__)
 #include <dbus/dbus.h> /* Pull in all of D-Bus headers. */
 #endif //__linux__
 
@@ -316,7 +316,7 @@ namespace instance_check_internal
 		return false;
 	}
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined (__FreeBSD__)
 
 	static void list_matching_objects(const std::string& pattern, std::vector<std::string>& result) 
 	{
@@ -561,7 +561,7 @@ bool instance_check(int argc, char** argv, bool app_co
 	hashed_path = std::hash<std::string>{}(boost::filesystem::system_complete(argv[0]).string());
 #else
 	boost::system::error_code ec;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	// If executed by an AppImage, start the AppImage, not the main process.
 	// see https://docs.appimage.org/packaging-guide/environment-variables.html#id2
 	const char *appimage_env = std::getenv("APPIMAGE");
