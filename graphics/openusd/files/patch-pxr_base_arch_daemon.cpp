--- pxr/base/arch/daemon.cpp.orig	2025-10-24 16:21:56 UTC
+++ pxr/base/arch/daemon.cpp
@@ -28,7 +28,7 @@ ArchCloseAllFiles(int nExcept, const int* exceptFds)
 int
 ArchCloseAllFiles(int nExcept, const int* exceptFds)
 {
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_DARWIN)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_DARWIN)
 
     int status, retStatus, retErrno;
     int i, j, maxfd, maxExcept = -1;
