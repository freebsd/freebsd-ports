--- src/common/os_posix.c.orig	2018-10-26 15:43:47 UTC
+++ src/common/os_posix.c
@@ -200,9 +200,8 @@ os_posix_fallocate(int fd, os_off_t offset, off_t len)
 		if (fstatfs(fd, &fsbuf) == -1 || fstat(fd, &fbuf) == -1)
 			return errno;
 
-		size_t reqd_blocks =
-			(((size_t)len + (fsbuf.f_bsize - 1)) / fsbuf.f_bsize)
-				- (size_t)fbuf.st_blocks;
+		size_t reqd_blocks = (((size_t)len + (fsbuf.f_bsize - 1)) / fsbuf.f_bsize);
+		reqd_blocks -= fbuf.st_blocks > reqd_blocks ? reqd_blocks : fbuf.st_blocks;
 		if (reqd_blocks > (size_t)fsbuf.f_bavail)
 			return ENOSPC;
 	}
