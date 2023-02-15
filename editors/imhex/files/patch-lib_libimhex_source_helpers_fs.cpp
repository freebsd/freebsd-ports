--- lib/libimhex/source/helpers/fs.cpp.orig	2023-02-12 18:24:04 UTC
+++ lib/libimhex/source/helpers/fs.cpp
@@ -15,10 +15,15 @@
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
@@ -101,7 +106,7 @@ namespace hex::fs {
                 result = NFD::PickFolder(outPath, defaultPath.empty() ? nullptr : defaultPath.c_str());
                 break;
             default:
-                std::unreachable();
+                pl::hlp::unreachable();
         }
 
         if (result == NFD_OKAY){
