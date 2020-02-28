--- cursor/os-compatibility.c.orig	2020-02-11 23:46:03 UTC
+++ cursor/os-compatibility.c
@@ -34,7 +34,7 @@
 #include <string.h>
 #include <stdlib.h>
 
-#ifdef HAVE_MEMFD_CREATE
+#if defined(HAVE_MEMFD_CREATE) || defined(__FreeBSD__)
 #include <sys/mman.h>
 #endif
 
@@ -131,6 +131,11 @@ os_create_anonymous_file(off_t size)
 		 */
 		fcntl(fd, F_ADD_SEALS, F_SEAL_SHRINK | F_SEAL_SEAL);
 	} else
+#elif defined(__FreeBSD__)
+/* posix_fallocate returns ENODEV before https://svnweb.freebsd.org/changeset/base/356512 */
+#undef HAVE_POSIX_FALLOCATE
+	fd = shm_open(SHM_ANON, O_CREAT | O_RDWR | O_CLOEXEC, 0600); // shm_open is always CLOEXEC
+	if (fd < 0)
 #endif
 	{
 		path = getenv("XDG_RUNTIME_DIR");
