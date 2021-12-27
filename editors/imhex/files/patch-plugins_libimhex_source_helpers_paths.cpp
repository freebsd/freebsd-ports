--- plugins/libimhex/source/helpers/paths.cpp.orig	2021-12-16 17:57:41 UTC
+++ plugins/libimhex/source/helpers/paths.cpp
@@ -8,10 +8,15 @@
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
 #include <string>
 #include <vector>
