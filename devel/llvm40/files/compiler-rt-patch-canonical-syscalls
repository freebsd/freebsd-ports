diff --git lib/sanitizer_common/sanitizer_linux.cc lib/sanitizer_common/sanitizer_linux.cc
index 7328a5c0ac1..4b59a39ee27 100644
--- lib/sanitizer_common/sanitizer_linux.cc
+++ lib/sanitizer_common/sanitizer_linux.cc
@@ -223,7 +223,8 @@ static void kernel_stat_to_stat(struct kernel_stat *in, struct stat *out) {
 
 uptr internal_stat(const char *path, void *buf) {
 #if SANITIZER_FREEBSD
-  return internal_syscall(SYSCALL(stat), path, buf);
+  return internal_syscall(SYSCALL(fstatat), AT_FDCWD, (uptr)path,
+                          (uptr)buf, 0);
 #elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(newfstatat), AT_FDCWD, (uptr)path,
                           (uptr)buf, 0);
@@ -247,7 +248,8 @@ uptr internal_stat(const char *path, void *buf) {
 
 uptr internal_lstat(const char *path, void *buf) {
 #if SANITIZER_FREEBSD
-  return internal_syscall(SYSCALL(lstat), path, buf);
+  return internal_syscall(SYSCALL(fstatat), AT_FDCWD, (uptr)path,
+                         (uptr)buf, AT_SYMLINK_NOFOLLOW);
 #elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(newfstatat), AT_FDCWD, (uptr)path,
                          (uptr)buf, AT_SYMLINK_NOFOLLOW);
@@ -590,7 +592,9 @@ uptr internal_getppid() {
 }
 
 uptr internal_getdents(fd_t fd, struct linux_dirent *dirp, unsigned int count) {
-#if SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
+#if SANITIZER_FREEBSD
+  return internal_syscall(SYSCALL(getdirentries), fd, (uptr)dirp, count, NULL);
+#elif SANITIZER_USES_CANONICAL_LINUX_SYSCALLS
   return internal_syscall(SYSCALL(getdents64), fd, (uptr)dirp, count);
 #else
   return internal_syscall(SYSCALL(getdents), fd, (uptr)dirp, count);
