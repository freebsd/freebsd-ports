--- src/appleseed/foundation/platform/path.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed/foundation/platform/path.cpp
@@ -49,6 +49,8 @@
 #include <mach-o/dyld.h>
 #elif defined __linux__
 #include <unistd.h>
+#elif defined __FreeBSD__
+#include <sys/sysctl.h>
 #endif
 
 using namespace boost;
@@ -88,6 +90,17 @@ const char* get_executable_path()
         assert(result > 0);
         path[result] = '\0';
 
+// FreeBSD.
+#elif defined __FreeBSD__
+
+#if __FreeBSD_version > 900009
+        const
+#endif
+        int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+        size_t len = sizeof(path);
+        const int result = sysctl(mib, 4, path, &len, 0x0, 0);
+        assert(result == 0);
+
 // Other platforms.
 #else
 
