--- tests/zfs-tests/cmd/mmap_seek.c.orig	2025-12-30 21:33:04 UTC
+++ tests/zfs-tests/cmd/mmap_seek.c
@@ -55,7 +55,7 @@ seek_expect(int fd, off_t offset, int whence, off_t ex
 		return;
 
 	int err = errno;
-	fprintf(stderr, "lseek(fd, %ld, SEEK_%s) = %ld (expected %ld)",
+	fprintf(stderr, "lseek(fd, %jd, SEEK_%s) = %jd (expected %jd)",
 	    offset, (whence == SEEK_DATA ? "DATA" : "HOLE"),
 	    seek_offset, expect_offset);
 	if (err != 0)
