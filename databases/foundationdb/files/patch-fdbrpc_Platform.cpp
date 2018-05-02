--- fdbrpc/Platform.cpp.orig	2018-04-19 02:55:50 UTC
+++ fdbrpc/Platform.cpp
@@ -87,7 +87,7 @@ int eraseDirectoryRecursive(std::string 
 	__eraseDirectoryRecurseiveCount = 0;
 #ifdef _WIN32
 	system( ("rd /s /q \"" + dir + "\"").c_str() );
-#elif defined(__linux__) || defined(__APPLE__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 	int error =
 		nftw(dir.c_str(),
 			[](const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf) -> int {
@@ -122,8 +122,8 @@ std::string getDefaultConfigPath() {
 	return _filepath + "\\foundationdb";
 #elif defined(__linux__)
 	return "/etc/foundationdb";
-#elif defined(__APPLE__)
-	return "/usr/local/etc/foundationdb";
+#elif defined(__APPLE__) || defined(__FreeBSD__)
+	return CONFDIR;
 #else
 	#error Port me!
 #endif
