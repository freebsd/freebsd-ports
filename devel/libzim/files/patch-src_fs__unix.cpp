--- src/fs_unix.cpp.orig	2018-12-04 23:56:33 UTC
+++ src/fs_unix.cpp
@@ -34,7 +34,7 @@ namespace unix {
 
 zsize_t FD::readAt(char* dest, zsize_t size, offset_t offset) const
 {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 # define PREAD pread
 #else
 # define PREAD pread64
