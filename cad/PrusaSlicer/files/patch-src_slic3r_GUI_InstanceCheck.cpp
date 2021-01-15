--- src/slic3r/GUI/InstanceCheck.cpp.orig	2021-01-11 13:01:51 UTC
+++ src/slic3r/GUI/InstanceCheck.cpp
@@ -23,7 +23,7 @@
 #include <strsafe.h>
 #endif //WIN32
 
-#if __linux__
+#if defined(__linux__) || defined (__FreeBSD__)
 #include <dbus/dbus.h> /* Pull in all of D-Bus headers. */
 #endif //__linux__
 
@@ -169,7 +169,7 @@ namespace instance_check_internal
 		return false;
 	}
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined (__FreeBSD__)
 
 	static bool  send_message(const std::string &message_text, const std::string &version)
 	{
