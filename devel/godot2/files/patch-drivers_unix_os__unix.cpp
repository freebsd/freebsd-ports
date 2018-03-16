--- drivers/unix/os_unix.cpp.orig	2017-08-28 01:55:12 UTC
+++ drivers/unix/os_unix.cpp
@@ -51,6 +51,7 @@
 
 #if defined(__FreeBSD__) || defined(__OpenBSD__)
 #include <sys/param.h>
+#include <sys/sysctl.h>
 #endif
 #include "globals.h"
 #include <assert.h>
@@ -375,17 +376,7 @@ Error OS_Unix::execute(const String &p_p
 			args.push_back((char *)cs[i].get_data()); // shitty C cast
 		args.push_back(0);
 
-#ifdef __FreeBSD__
-		if (p_path.find("/")) {
-			// exec name contains path so use it
-			execv(p_path.utf8().get_data(), &args[0]);
-		} else {
-			// use program name and search through PATH to find it
-			execvp(getprogname(), &args[0]);
-		}
-#else
 		execv(p_path.utf8().get_data(), &args[0]);
-#endif
 		// still alive? something failed..
 		fprintf(stderr, "**ERROR** OS_Unix::execute - Could not create child process while executing: %s\n", p_path.utf8().get_data());
 		abort();
@@ -499,12 +490,24 @@ String OS_Unix::get_executable_path() co
 		return OS::get_executable_path();
 	}
 	return b;
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__OpenBSD__)
 	char resolved_path[MAXPATHLEN];
 
 	realpath(OS::get_executable_path().utf8().get_data(), resolved_path);
 
 	return String(resolved_path);
+
+#elif defined(__FreeBSD__)
+	int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+	char buf[MAXPATHLEN];
+	size_t len = sizeof(buf);
+	if (sysctl(mib, 4, buf, &len, NULL, 0) != 0) {
+		WARN_PRINT("Couldn't get executable path from sysctl");
+		return OS::get_executable_path();
+	}
+	String b;
+	b.parse_utf8(buf);
+	return b;
 #elif defined(__APPLE__)
 	char temp_path[1];
 	uint32_t buff_size = 1;
