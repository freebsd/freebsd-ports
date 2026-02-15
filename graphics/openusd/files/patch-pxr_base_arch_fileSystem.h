--- pxr/base/arch/fileSystem.h.orig	2025-10-24 16:21:56 UTC
+++ pxr/base/arch/fileSystem.h
@@ -28,6 +28,9 @@
 #include <unistd.h>
 #include <sys/statfs.h>
 #include <glob.h>
+#elif defined(ARCH_OS_FREEBSD)
+#include <unistd.h>
+#include <glob.h>
 #elif defined(ARCH_OS_DARWIN)
 #include <unistd.h>
 #include <sys/mount.h>
