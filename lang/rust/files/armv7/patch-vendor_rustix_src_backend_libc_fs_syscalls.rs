gnueabihf was changed to gnu in this commit and it breaks rustix
https://github.com/rust-lang/rust/commit/93ec0e6299e31e6857e8ad741750034f35762b11


--- vendor/rustix-0.38.28/src/backend/libc/fs/syscalls.rs.orig	2024-05-06 16:29:17.182875000 +0200
+++ vendor/rustix-0.38.28/src/backend/libc/fs/syscalls.rs	2024-05-06 16:29:48.897744000 +0200
@@ -140,7 +140,7 @@ pub(crate) fn open(path: &CStr, oflags: OFlags, mode: 
 pub(crate) fn open(path: &CStr, oflags: OFlags, mode: Mode) -> io::Result<OwnedFd> {
     // Work around <https://sourceware.org/bugzilla/show_bug.cgi?id=17523>.
     // glibc versions before 2.25 don't handle `O_TMPFILE` correctly.
-    #[cfg(all(unix, target_env = "gnu", not(target_os = "hurd")))]
+    #[cfg(all(unix, target_env = "gnu", not(any(target_os = "freebsd", target_os = "hurd"))))]
     if oflags.contains(OFlags::TMPFILE) && crate::backend::if_glibc_is_less_than_2_25() {
         return open_via_syscall(path, oflags, mode);
     }
@@ -203,7 +203,7 @@ pub(crate) fn openat(
 ) -> io::Result<OwnedFd> {
     // Work around <https://sourceware.org/bugzilla/show_bug.cgi?id=17523>.
     // glibc versions before 2.25 don't handle `O_TMPFILE` correctly.
-    #[cfg(all(unix, target_env = "gnu", not(target_os = "hurd")))]
+    #[cfg(all(unix, target_env = "gnu", not(any(target_os = "freebsd", target_os = "hurd"))))]
     if oflags.contains(OFlags::TMPFILE) && crate::backend::if_glibc_is_less_than_2_25() {
         return openat_via_syscall(dirfd, path, oflags, mode);
     }
