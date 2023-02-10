--- lib/libimhex/source/helpers/fs.cpp.orig	2023-01-05 08:53:49 UTC
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
