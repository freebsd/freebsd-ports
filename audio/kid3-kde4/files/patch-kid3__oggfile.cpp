--- ./kid3/oggfile.cpp.orig	Fri Jan 27 21:15:27 2006
+++ ./kid3/oggfile.cpp	Sat Sep 23 01:27:49 2006
@@ -143,7 +143,7 @@
 			bool setUtime = false;
 			struct utimbuf times;
 			if (preserve) {
-				int fd = ::fileno(fpIn);
+				int fd = fileno(fpIn);
 				if (fd >= 0) {
 					struct stat fileStat;
 					if (::fstat(fd, &fileStat) == 0) {
