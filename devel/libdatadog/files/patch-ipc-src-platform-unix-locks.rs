--- ipc/src/platform/unix/locks.rs.orig	2023-03-27 13:18:03 UTC
+++ ipc/src/platform/unix/locks.rs
@@ -77,6 +77,8 @@ impl FLock {
             l_start: 0,
             l_len: 0,
             l_pid: 0,
+            #[cfg(target_os = "freebsd")]
+            l_sysid: 0,
         };
 
         match nix::fcntl::fcntl(this.fd, FcntlArg::F_SETLK(&lock)) {
