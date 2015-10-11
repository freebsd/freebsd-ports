--- common/sys/sysinfo.cpp.orig	2015-09-17 06:11:18 UTC
+++ common/sys/sysinfo.cpp
@@ -414,6 +414,31 @@ namespace embree
 #endif
 
 ////////////////////////////////////////////////////////////////////////////////
+/// FreeBSD Platform
+////////////////////////////////////////////////////////////////////////////////
+
+#ifdef __FreeBSD__
+
+#include <sys/sysctl.h>
+
+namespace embree
+{
+  std::string getExecutableFileName() 
+  {
+#if __FreeBSD_version > 900009
+    const
+#endif
+    int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+    char buf[1024];
+    size_t len = sizeof(buf);
+    if (sysctl(mib, 4, buf, &len, 0x0, 0) == -1) *buf = '\0';
+    return std::string(buf);
+  }
+}
+
+#endif
+
+////////////////////////////////////////////////////////////////////////////////
 /// Mac OS X Platform
 ////////////////////////////////////////////////////////////////////////////////
 
