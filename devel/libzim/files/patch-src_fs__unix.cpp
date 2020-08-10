--- src/fs_unix.cpp.orig	2020-07-15 14:24:54 UTC
+++ src/fs_unix.cpp
@@ -34,7 +34,7 @@ namespace unix {
 
 zsize_t FD::readAt(char* dest, zsize_t size, offset_t offset) const
 {
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 # define PREAD pread
 #else
 # define PREAD pread64
