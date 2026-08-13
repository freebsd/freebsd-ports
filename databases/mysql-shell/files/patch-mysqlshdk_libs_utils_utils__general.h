--- mysqlshdk/libs/utils/utils_general.h.orig	2026-01-26 17:09:34 UTC
+++ mysqlshdk/libs/utils/utils_general.h
@@ -172,7 +172,8 @@ enum class OperatingSystem {
   LINUX,
   WINDOWS_OS,  // WINDOWS conflicts with a zlib #define
   MACOS,
-  SOLARIS
+  SOLARIS,
+  FREEBSD
 };
 std::string SHCORE_PUBLIC to_string(OperatingSystem os_type);
 
