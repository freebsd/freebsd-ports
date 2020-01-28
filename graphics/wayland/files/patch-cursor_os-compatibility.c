--- cursor/os-compatibility.c.orig	2019-03-21 00:55:25 UTC
+++ cursor/os-compatibility.c
@@ -23,6 +23,10 @@
  * SOFTWARE.
  */
 
+#ifdef __FreeBSD__
+#include <sys/mman.h>
+#endif
+
 #define _GNU_SOURCE
 
 #include <sys/types.h>
@@ -59,6 +63,7 @@ err:
 }
 #endif
 
+#ifndef __FreeBSD__
 static int
 create_tmpfile_cloexec(char *tmpname)
 {
@@ -78,6 +83,7 @@ create_tmpfile_cloexec(char *tmpname)
 
 	return fd;
 }
+#endif
 
 /*
  * Create a new, unique, anonymous file of the given size, and
@@ -103,11 +109,14 @@ create_tmpfile_cloexec(char *tmpname)
 int
 os_create_anonymous_file(off_t size)
 {
+	int fd;
+	int ret;
+#ifdef __FreeBSD__
+	fd = shm_open(SHM_ANON, O_CREAT | O_RDWR | O_CLOEXEC, 0600); // shm_open is always CLOEXEC
+#else
 	static const char template[] = "/wayland-cursor-shared-XXXXXX";
 	const char *path;
 	char *name;
-	int fd;
-	int ret;
 
 	path = getenv("XDG_RUNTIME_DIR");
 	if (!path) {
@@ -125,11 +134,12 @@ os_create_anonymous_file(off_t size)
 	fd = create_tmpfile_cloexec(name);
 
 	free(name);
+#endif /* __FreeBSD__ */
 
 	if (fd < 0)
 		return -1;
 
-#ifdef HAVE_POSIX_FALLOCATE
+#if defined(HAVE_POSIX_FALLOCATE) && !defined(__FreeBSD__)
 	ret = posix_fallocate(fd, 0, size);
 	if (ret != 0) {
 		close(fd);
