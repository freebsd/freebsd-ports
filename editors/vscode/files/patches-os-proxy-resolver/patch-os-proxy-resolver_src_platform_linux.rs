--- os-proxy-resolver/src/platform/linux.rs.orig	2026-08-25 07:52:37 UTC
+++ os-proxy-resolver/src/platform/linux.rs
@@ -216,9 +216,23 @@ fn configure_watcher_command(command: &mut Command) {
     // operations only invoke async-signal-safe Linux system calls.
     unsafe {
         command.pre_exec(move || {
+            #[cfg(target_os = "linux")]
             if libc::prctl(libc::PR_SET_PDEATHSIG, libc::SIGKILL) == -1 {
                 return Err(std::io::Error::last_os_error());
             }
+            #[cfg(target_os = "freebsd")]
+            {
+                let mut sig = libc::SIGKILL;
+                let ret = libc::procctl(
+                    libc::P_PID,
+                    0,
+                    libc::PROC_PDEATHSIG_CTL,
+                    &mut sig as *mut libc::c_int as *mut libc::c_void,
+                );
+                if ret == -1 {
+                    return Err(std::io::Error::last_os_error());
+                }
+            }
             // The parent may have exited between fork and PR_SET_PDEATHSIG.
             if libc::getppid() != expected_parent {
                 libc::_exit(1);
@@ -248,12 +262,21 @@ fn mark_file_descriptors_close_on_exec(
     // watcher program.
     // SAFETY: close_range operates on the calling process's descriptor table.
     loop {
+        #[cfg(target_os = "linux")]
         let result = unsafe {
             libc::syscall(
                 libc::SYS_close_range,
                 3 as libc::c_uint,
                 libc::c_uint::MAX,
                 libc::CLOSE_RANGE_CLOEXEC,
+            ) as libc::c_int
+        };
+        #[cfg(target_os = "freebsd")]
+        let result = unsafe {
+            libc::close_range(
+                3 as libc::c_uint,
+                libc::c_uint::MAX,
+                libc::CLOSE_RANGE_CLOEXEC as libc::c_int,
             )
         };
         if result == 0 {
