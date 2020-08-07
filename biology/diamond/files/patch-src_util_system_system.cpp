--- src/util/system/system.cpp.orig	2020-08-05 17:04:09 UTC
+++ src/util/system/system.cpp
@@ -6,14 +6,19 @@
 #include "../log_stream.h"
 
 #ifdef _MSC_VER
-#include <windows.h>
+  #include <windows.h>
 #else
-#include <unistd.h>
-#include <sys/stat.h>
-#ifndef __APPLE__
-#include <sys/sysinfo.h>
+  #include <unistd.h>
+  #include <sys/stat.h>
+  #ifndef  __APPLE__
+    #ifdef __FreeBSD__
+      #include <sys/types.h>
+      #include <sys/sysctl.h>
+    #else
+      #include <sys/sysinfo.h>
+    #endif
+  #endif
 #endif
-#endif
 
 using std::string;
 using std::cout;
@@ -129,6 +134,16 @@ void reset_color(bool err) {
 double total_ram() {
 #if defined(WIN32) || defined(__APPLE__)
 	return 0.0;
+#elif defined(__FreeBSD__)
+	int mib[2] = { CTL_HW, HW_REALMEM };
+	u_int namelen = sizeof(mib) / sizeof(mib[0]);
+	uint64_t oldp;
+	size_t oldlenp = sizeof(oldp);
+
+	if (sysctl(mib, namelen, &oldp, &oldlenp, NULL, 0) < 0)
+		return 0.0;
+	else
+		return oldp / 1e9;
 #else
 	struct sysinfo info;
 	if (sysinfo(&info) != 0)
