--- lib/libimhex/source/helpers/fs.cpp.orig	2022-05-04 11:21:53 UTC
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
 
 namespace hex::fs {
