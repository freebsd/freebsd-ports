--- kid3/oggfile.cpp.orig	Sat Jan 28 02:15:27 2006
+++ kid3/oggfile.cpp	Mon Aug  7 16:13:25 2006
@@ -143,7 +143,7 @@
 			bool setUtime = false;
 			struct utimbuf times;
 			if (preserve) {
-				int fd = ::fileno(fpIn);
+				int fd = fileno(fpIn);
 				if (fd >= 0) {
 					struct stat fileStat;
 					if (::fstat(fd, &fileStat) == 0) {
