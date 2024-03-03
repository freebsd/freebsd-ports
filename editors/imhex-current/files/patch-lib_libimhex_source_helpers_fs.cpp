--- lib/libimhex/source/helpers/fs.cpp.orig	2024-03-02 15:44:54 UTC
+++ lib/libimhex/source/helpers/fs.cpp
@@ -13,7 +13,11 @@
     #include <shellapi.h>
 #elif defined(OS_LINUX) || defined(OS_WEB)
     #include <xdg.hpp>
+# if defined(__FreeBSD__)
+    #include <sys/syslimits.h>
+# else
     #include <limits.h>
+# endif
 #endif
 
 #if defined(OS_WEB)
