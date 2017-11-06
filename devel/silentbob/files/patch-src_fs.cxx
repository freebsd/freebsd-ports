--- src/fs.cxx.orig	2013-11-27 15:00:47 UTC
+++ src/fs.cxx
@@ -110,7 +110,7 @@ __export int logToFile (char * fileName,
 	return 0;
 }
 
-#ifdef __linux
+#if defined(__linux__) || defined(__FreeBSD__)
 int Dposix_fadvise (int fd, int offset, int len, int advice)
 {
 	return posix_fadvise (fd, offset, len, advice);
