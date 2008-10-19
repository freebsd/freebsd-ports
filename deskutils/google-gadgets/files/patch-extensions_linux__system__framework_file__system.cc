
$FreeBSD$

--- extensions/linux_system_framework/file_system.cc.orig
+++ extensions/linux_system_framework/file_system.cc
@@ -463,8 +463,8 @@
   if (stat(path, &stat_value))
     return Date(0);
 
-  return Date(stat_value.st_mtim.tv_sec * 1000
-              + stat_value.st_mtim.tv_nsec / 1000000);
+  return Date(statbuf.st_mtimespec.tv_sec * 1000
+              + statbuf.st_mtimespec.tv_nsec / 1000000);
 }
 
 static Date GetDateLastAccessed(const char *path) {
@@ -476,8 +476,8 @@
   if (stat(path, &stat_value))
     return Date(0);
 
-  return Date(stat_value.st_atim.tv_sec * 1000
-              + stat_value.st_atim.tv_nsec / 1000000);
+  return Date(statbuf.st_atimespec.tv_sec * 1000
+              + statbuf.st_atimespec.tv_nsec / 1000000);
 }
 
 class Drive : public DriveInterface {
