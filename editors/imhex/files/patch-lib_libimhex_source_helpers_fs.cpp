--- lib/libimhex/source/helpers/fs.cpp.orig	2022-07-07 06:48:37 UTC
+++ lib/libimhex/source/helpers/fs.cpp
@@ -13,10 +13,15 @@
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
