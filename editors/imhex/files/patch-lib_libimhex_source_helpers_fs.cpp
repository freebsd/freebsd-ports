--- lib/libimhex/source/helpers/fs.cpp.orig	2023-04-04 10:04:22 UTC
+++ lib/libimhex/source/helpers/fs.cpp
@@ -11,10 +11,15 @@
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
@@ -54,7 +59,7 @@ namespace hex::fs {
                 result = NFD::PickFolder(outPath, defaultPath.empty() ? nullptr : defaultPath.c_str());
                 break;
             default:
-                std::unreachable();
+                __builtin_unreachable();
         }
 
         if (result == NFD_OKAY){
