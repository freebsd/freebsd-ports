--- src/cbang/os/SystemUtilities.cpp.orig	2021-08-10 22:46:49 UTC
+++ src/cbang/os/SystemUtilities.cpp
@@ -388,7 +388,7 @@ namespace cb {
       size_t len = PATH_MAX;
       path[0] = path[PATH_MAX] = 0;
 
-      if (sysctl(mib, 4, path, &len, 0, 0) || *path)
+      if (sysctl(mib, 4, path, &len, NULL, 0))
         THROW("Failed to get executable path: " <<  SysError());
 
       return (char *)path;
