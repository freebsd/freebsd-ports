--- UI/NativeApp.cpp.orig	2015-02-26 20:05:06 UTC
+++ UI/NativeApp.cpp
@@ -291,7 +291,7 @@ void NativeInit(int argc, const char *ar
 #elif defined(BLACKBERRY) || defined(IOS)
 	// Packed assets are included in app
 	VFSRegister("", new DirectoryAssetReader(external_directory));
-#elif defined(__APPLE__) || (defined(__linux__) && !defined(ANDROID))
+#elif !defined(MOBILE_DEVICE) && !defined(_WIN32)
 	VFSRegister("", new DirectoryAssetReader((File::GetExeDirectory() + "assets/").c_str()));
 	VFSRegister("", new DirectoryAssetReader((File::GetExeDirectory()).c_str()));
 	VFSRegister("", new DirectoryAssetReader("/usr/share/ppsspp/assets/"));
