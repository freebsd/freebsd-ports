--- file.c.orig	Thu Nov 13 23:32:27 2003
+++ file.c	Fri Jan  2 19:11:23 2004
@@ -1387,7 +1387,7 @@
 		statbuf.f_bsize, statbuf.f_blocks, statbuf.f_bfree);
 	tprintf("f_bavail=%u, f_files=%u, f_ffree=%u, f_fsid={%d, %d}, f_namelen=%u",
 		statbuf.f_bavail,statbuf.f_files, statbuf.f_ffree,
-		statbuf.f_fsid.__val[0], statbuf.f_fsid.__val[1],
+		statbuf.f_fsid.val[0], statbuf.f_fsid.val[1],
 		statbuf.f_namelen);
 #else /* !ALPHA */
 	tprintf("{f_type=%s, f_bsize=%lu, f_blocks=%lu, f_bfree=%lu, ",
@@ -1399,7 +1399,7 @@
 		(unsigned long)statbuf.f_bavail,
 		(unsigned long)statbuf.f_files,
 		(unsigned long)statbuf.f_ffree,
-		statbuf.f_fsid.__val[0], statbuf.f_fsid.__val[1]);
+		statbuf.f_fsid.val[0], statbuf.f_fsid.val[1]);
 #ifdef LINUX
 	tprintf(", f_namelen=%lu", (unsigned long)statbuf.f_namelen);
 #endif /* LINUX */
