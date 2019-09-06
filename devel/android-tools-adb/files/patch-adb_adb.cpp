--- adb/adb.cpp.orig	2019-07-17 19:54:09 UTC
+++ adb/adb.cpp
@@ -44,8 +44,19 @@
 #include <android-base/parsenetaddress.h>
 #include <android-base/stringprintf.h>
 #include <android-base/strings.h>
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
 #include <platform_tools_version.h>
+#endif
 
 #include "adb_auth.h"
 #include "adb_io.h"
