--- lib/bpf/src/libbpf_internal.h.orig	2025-10-27 20:52:10 UTC
+++ lib/bpf/src/libbpf_internal.h
@@ -15,6 +15,7 @@
 #include <errno.h>
 #include <linux/err.h>
 #include <fcntl.h>
+#include <sys/mman.h>
 #include <unistd.h>
 #include <sys/syscall.h>
 #include <libelf.h>
@@ -664,7 +665,7 @@ static inline int sys_dup3(int oldfd, int newfd, int f
 
 static inline int sys_dup3(int oldfd, int newfd, int flags)
 {
-	return syscall(__NR_dup3, oldfd, newfd, flags);
+	return dup3(oldfd, newfd, flags);
 }
 
 /* Some versions of Android don't provide memfd_create() in their libc
@@ -673,7 +674,7 @@ static inline int sys_memfd_create(const char *name, u
  */
 static inline int sys_memfd_create(const char *name, unsigned flags)
 {
-	return syscall(__NR_memfd_create, name, flags);
+	return memfd_create(name, flags);
 }
 
 /* Point *fixed_fd* to the same file that *tmp_fd* points to.
