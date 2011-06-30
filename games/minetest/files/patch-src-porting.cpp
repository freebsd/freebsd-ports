--- src/porting.cpp.orig	2011-06-18 23:31:24.000000000 +0400
+++ src/porting.cpp	2011-06-19 13:53:48.000000000 +0400
@@ -194,17 +194,10 @@
 	/*
 		Linux
 	*/
-	#elif defined(linux)
+	#elif defined(linux) || defined (__FreeBSD__)
 		#include <unistd.h>
 	
-	char buf[BUFSIZ];
-	memset(buf, 0, BUFSIZ);
-	// Get path to executable
-	assert(readlink("/proc/self/exe", buf, BUFSIZ-1) != -1);
-	
-	pathRemoveFile(buf, '/');
-
-	path_data = std::string(buf) + "/../share/" + APPNAME;
+	path_data = std::string("/usr/local/share/") + APPNAME;
 	//path_data = std::string(INSTALL_PREFIX) + "/share/" + APPNAME;
 	
 	path_userdata = std::string(getenv("HOME")) + "/." + APPNAME;
