--- ContentDownloader/SheepDownloader.cpp.orig	2018-05-31 14:38:12 UTC
+++ ContentDownloader/SheepDownloader.cpp
@@ -41,7 +41,10 @@
 #include <sys/param.h>
 #include <sys/mount.h>
 #endif
-#ifdef LINUX_GNU
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/mount.h>
+#elif defined(LINUX_GNU)
 #include <sys/statfs.h>
 #include <limits.h>
 #define MAX_PATH PATH_MAX
