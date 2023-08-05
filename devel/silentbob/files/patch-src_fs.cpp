--- src/fs.cpp.orig	2023-08-03 02:03:35 UTC
+++ src/fs.cpp
@@ -110,7 +110,7 @@ __export int logToFile (char * fileName, char * fmt, .
 	return 0;
 }
 
-#ifdef __linux
+#if defined(__linux__) || defined(__FreeBSD__)
 int Dposix_fadvise (int fd, int offset, int len, int advice)
 {
 	return posix_fadvise (fd, offset, len, advice);
