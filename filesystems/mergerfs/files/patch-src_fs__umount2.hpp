--- src/fs_umount2.hpp.orig	2024-02-29 20:41:22 UTC
+++ src/fs_umount2.hpp
@@ -19,7 +19,14 @@
 #pragma once
 
 #include <errno.h>
+#ifdef __linux__
 #include <sys/mount.h>
+#else
+#include <sys/param.h>
+#include <sys/mount.h>
+#define umount2(target, flags) unmount(target, flags)
+#define MNT_DETACH 0
+#endif
 
 #include <string>
 
