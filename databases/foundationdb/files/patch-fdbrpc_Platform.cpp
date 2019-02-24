--- fdbrpc/Platform.cpp.orig	2019-01-09 22:28:32 UTC
+++ fdbrpc/Platform.cpp
@@ -87,7 +87,7 @@ int eraseDirectoryRecursive(std::string const& dir) {
 	__eraseDirectoryRecurseiveCount = 0;
 #ifdef _WIN32
 	system( ("rd /s /q \"" + dir + "\"").c_str() );
-#elif defined(__linux__) || defined(__APPLE__)
+#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 	int error =
 		nftw(dir.c_str(),
 			[](const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf) -> int {
@@ -123,8 +123,8 @@ std::string getDefaultConfigPath() {
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
