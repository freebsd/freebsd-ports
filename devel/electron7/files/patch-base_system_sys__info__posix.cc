--- base/system/sys_info_posix.cc.orig	2019-12-12 12:38:59 UTC
+++ base/system/sys_info_posix.cc
@@ -220,6 +220,8 @@ std::string SysInfo::OperatingSystemArchitecture() {
     arch = "x86";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (std::string(info.sysname) == "AIX") {
     arch = "ppc64";
   }
