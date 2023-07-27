--- src/slic3r/GUI/InstanceCheck.cpp.orig	2023-06-19 12:07:14 UTC
+++ src/slic3r/GUI/InstanceCheck.cpp
@@ -23,7 +23,7 @@
 #include <strsafe.h>
 #endif //WIN32
 
-#if __linux__
+#if defined(__linux__) || defined (__FreeBSD__)
 #include <dbus/dbus.h> /* Pull in all of D-Bus headers. */
 #endif //__linux__
 
@@ -222,7 +222,7 @@ namespace instance_check_internal
 		return false;
 	}
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined (__FreeBSD__)
 
 	static bool  send_message(const std::string &message_text, const std::string &version)
 	{
@@ -310,7 +310,7 @@ bool instance_check(int argc, char** argv, bool app_co
 	hashed_path = std::hash<std::string>{}(boost::filesystem::system_complete(argv[0]).string());
 #else
 	boost::system::error_code ec;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	// If executed by an AppImage, start the AppImage, not the main process.
 	// see https://docs.appimage.org/packaging-guide/environment-variables.html#id2
 	const char *appimage_env = std::getenv("APPIMAGE");
