--- lib/libimhex/source/helpers/fs.cpp.orig	2023-06-24 10:07:39 UTC
+++ lib/libimhex/source/helpers/fs.cpp
@@ -12,10 +12,15 @@
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
 
 #include <wolv/io/file.hpp>
@@ -120,7 +125,7 @@ namespace hex::fs {
                 result = NFD::PickFolder(outPath, defaultPath.empty() ? nullptr : defaultPath.c_str());
                 break;
             default:
-                std::unreachable();
+                __builtin_unreachable();
         }
 
         if (result == NFD_OKAY){
