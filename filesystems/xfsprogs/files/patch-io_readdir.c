--- io/readdir.c.orig	2015-07-24 04:28:04 UTC
+++ io/readdir.c
@@ -72,7 +72,7 @@ dump_dirent(
 	long long offset,
 	struct dirent *dirent)
 {
-	printf("%08llx: d_ino: 0x%08lx", offset, dirent->d_ino);
+	printf("%08llx: d_ino: 0x%08x", offset, dirent->d_ino);
 #ifdef _DIRENT_HAVE_D_OFF
 	printf(" d_off: 0x%08lx", dirent->d_off);
 #endif
@@ -109,7 +109,7 @@ read_directory(
 
 		if (dump) {
 			dump_dirent(offset, dirent);
-			offset = dirent->d_off;
+			offset = telldir(dir);
 		}
 	}
 
