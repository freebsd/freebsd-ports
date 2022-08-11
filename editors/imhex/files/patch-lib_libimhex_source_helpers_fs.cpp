--- lib/libimhex/source/helpers/fs.cpp.orig	2022-08-05 10:52:34 UTC
+++ lib/libimhex/source/helpers/fs.cpp
@@ -14,10 +14,15 @@
     #include <shlobj.h>
 #elif defined(OS_LINUX)
     #include <xdg.hpp>
+# if defined(__FreeBSD__)
+    #include <sys/syslimits.h>
+# else
     #include <linux/limits.h>
+# endif
 #endif
 
 #include <algorithm>
+#include <array>
 #include <filesystem>
 
 namespace hex::fs {
@@ -179,7 +184,7 @@ namespace hex::fs {
         #endif
     }
 
-    constexpr std::vector<std::fs::path> appendPath(std::vector<std::fs::path> paths, const std::fs::path &folder) {
+    std::vector<std::fs::path> appendPath(std::vector<std::fs::path> paths, const std::fs::path &folder) {
         for (auto &path : paths)
             path = path / folder;
 
