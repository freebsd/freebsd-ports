Handle config path on FreeBSD

--- pcsx2/Frontend/CommonHost.cpp.orig	2023-02-10 03:43:10 UTC
+++ pcsx2/Frontend/CommonHost.cpp
@@ -160,7 +160,7 @@ void CommonHost::SetDataDirectory()
 			EmuFolders::DataRoot = Path::Combine(StringUtil::WideStringToUTF8String(documents_directory), "PCSX2");
 		CoTaskMemFree(documents_directory);
 	}
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 	// Use $XDG_CONFIG_HOME/PCSX2 if it exists.
 	const char* xdg_config_home = getenv("XDG_CONFIG_HOME");
 	if (xdg_config_home && Path::IsAbsolute(xdg_config_home))
