--- fastboot/fastboot.cpp.orig	2019-08-13 02:10:58 UTC
+++ fastboot/fastboot.cpp
@@ -58,9 +58,20 @@
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
-#include <liblp/liblp.h>
 #include <platform_tools_version.h>
+#endif
+#include <liblp/liblp.h>
 #include <sparse/sparse.h>
 #include <ziparchive/zip_archive.h>
 
