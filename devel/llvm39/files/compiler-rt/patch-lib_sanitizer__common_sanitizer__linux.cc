--- lib/sanitizer_common/sanitizer_linux.cc.orig	2017-01-06 20:57:47.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux.cc	2018-04-19 17:03:38.293789000 +0100
@@ -63,7 +63,6 @@
 #include <sys/exec.h>
 #include <sys/sysctl.h>
 #include <vm/vm_param.h>
-#include <vm/pmap.h>
 #include <machine/atomic.h>
 extern "C" {
 // <sys/umtx.h> must be included after <errno.h> and <sys/types.h> on
@@ -223,7 +222,8 @@ static void kernel_stat_to_stat(struct k
 
 uptr internal_stat(const char *path, void *buf) {
 #if SANITIZER_FREEBSD
-  return internal_syscall(SYSCALL(stat), path, buf);
+  return internal_syscall(SYSCALL(fstatat), AT_FDCWD, (uptr)path,
+                          (uptr)buf, 0);
 #elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(newfstatat), AT_FDCWD, (uptr)path,
                           (uptr)buf, 0);
@@ -247,7 +247,8 @@ uptr internal_stat(const char *path, voi
 
 uptr internal_lstat(const char *path, void *buf) {
 #if SANITIZER_FREEBSD
-  return internal_syscall(SYSCALL(lstat), path, buf);
+  return internal_syscall(SYSCALL(fstatat), AT_FDCWD, (uptr)path,
+                         (uptr)buf, AT_SYMLINK_NOFOLLOW);
 #elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(newfstatat), AT_FDCWD, (uptr)path,
                          (uptr)buf, AT_SYMLINK_NOFOLLOW);
@@ -590,7 +591,9 @@ uptr internal_getppid() {
 }
 
 uptr internal_getdents(fd_t fd, struct linux_dirent *dirp, unsigned int count) {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
+#if SANITIZER_FREEBSD
+  return internal_syscall(SYSCALL(getdirentries), fd, (uptr)dirp, count, NULL);
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(getdents64), fd, (uptr)dirp, count);
 #else
   return internal_syscall(SYSCALL(getdents), fd, (uptr)dirp, count);
