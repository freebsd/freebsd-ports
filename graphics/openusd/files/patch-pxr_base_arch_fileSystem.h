--- pxr/base/arch/fileSystem.h.orig	2026-04-24 18:55:54 UTC
+++ pxr/base/arch/fileSystem.h
@@ -29,6 +29,9 @@
 #include <unistd.h>
 #include <sys/statfs.h>
 #include <glob.h>
+#elif defined(ARCH_OS_FREEBSD)
+#include <unistd.h>
+#include <glob.h>
 #elif defined(ARCH_OS_DARWIN)
 #include <unistd.h>
 #include <sys/mount.h>
