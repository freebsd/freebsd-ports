--- lib/unix.c.orig	2015-08-18 19:55:43 UTC
+++ lib/unix.c
@@ -83,7 +83,7 @@ qb_sys_mmap_file_open(char *path, const 
 #if defined(QB_LINUX) || defined(QB_CYGWIN)
 		snprintf(path, PATH_MAX, "/dev/shm/%s", file);
 #else
-		snprintf(path, PATH_MAX, LOCALSTATEDIR "/run/%s", file);
+		snprintf(path, PATH_MAX, "%s/%s", SOCKETDIR, file);
 		is_absolute = path;
 #endif
 	}
@@ -91,7 +91,7 @@ qb_sys_mmap_file_open(char *path, const 
 	if (fd < 0 && !is_absolute) {
 		qb_util_perror(LOG_ERR, "couldn't open file %s", path);
 
-		snprintf(path, PATH_MAX, LOCALSTATEDIR "/run/%s", file);
+		snprintf(path, PATH_MAX, "%s/%s", SOCKETDIR, file);
 		fd = open_mmap_file(path, file_flags);
 		if (fd < 0) {
 			res = -errno;
