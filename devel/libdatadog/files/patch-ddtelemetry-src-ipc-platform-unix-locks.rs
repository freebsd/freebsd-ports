--- ddtelemetry/src/ipc/platform/unix/locks.rs.orig	2022-12-12 17:34:51 UTC
+++ ddtelemetry/src/ipc/platform/unix/locks.rs
@@ -76,6 +76,8 @@ impl FLock {
             l_start: 0,
             l_len: 0,
             l_pid: 0,
+#[cfg(target_os = "freebsd")]
+            l_sysid: 0,
         };
 
         match nix::fcntl::fcntl(this.fd, FcntlArg::F_SETLK(&lock)) {
