--- lib/external/libwolv/libs/io/source/io/fs.cpp.orig	2023-04-08 15:52:49 UTC
+++ lib/external/libwolv/libs/io/source/io/fs.cpp
@@ -15,7 +15,7 @@
 #elif defined(OS_LINUX)
 
     #include <unistd.h>
-    #include <linux/limits.h>
+    #include <limits.h>
 
 #endif
 
