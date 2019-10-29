--- fastboot/fastboot.cpp.orig	2019-10-18 00:22:21 UTC
+++ fastboot/fastboot.cpp
@@ -59,10 +59,21 @@
 #include <android-base/stringprintf.h>
 #include <android-base/strings.h>
 #include <android-base/unique_fd.h>
+#ifdef PLATFORM_TOOLS_VERSION
+#include <sys/utsname.h>
+namespace android { namespace build {
+std::string GetBuildNumber() {
+  struct utsname uts;
+  if (uname(&uts) == -1)
+    return "unknown";
+  return uts.sysname;
+}}}
+#else
 #include <build/version.h>
+#include <platform_tools_version.h>
+#endif
 #include <libavb/libavb.h>
 #include <liblp/liblp.h>
-#include <platform_tools_version.h>
 #include <sparse/sparse.h>
 #include <ziparchive/zip_archive.h>
 
