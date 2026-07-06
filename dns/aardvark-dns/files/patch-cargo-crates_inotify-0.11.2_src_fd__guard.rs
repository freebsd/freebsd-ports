--- cargo-crates/inotify-0.11.2/src/fd_guard.rs.orig	2026-06-11 11:57:55 UTC
+++ cargo-crates/inotify-0.11.2/src/fd_guard.rs
@@ -89,20 +89,48 @@ impl PartialEq for FdGuard {
         // wrapper both owns a file descriptor for control purposes and spawns a
         // second thread that needs a separate unowned descriptor to use the `epoll-rs`
         // crate.
-        const KCMP_FILE: i32 = 0;
-        let current_process = std::process::id();
-        match util::libc_convert(unsafe {
-            libc::syscall(
-                libc::SYS_kcmp,
-                current_process,
-                current_process,
-                KCMP_FILE,
-                self.fd,
-                other.fd,
-            ) as i64
-        }) {
-            Err(_) => false,
-            Ok(cmp) => cmp == 0,
+        #[cfg(target_os = "linux")]
+        {
+            const KCMP_FILE: i32 = 0;
+            let current_process = std::process::id();
+            match util::libc_convert(unsafe {
+                libc::syscall(
+                    libc::SYS_kcmp,
+                    current_process,
+                    current_process,
+                    KCMP_FILE,
+                    self.fd,
+                    other.fd,
+                ) as i64
+            }) {
+                Err(_) => false,
+                Ok(cmp) => cmp == 0,
+            }
+        }
+        #[cfg(target_os = "freebsd")]
+        {
+            use std::mem::MaybeUninit;
+
+            unsafe {
+                let mut stat1 = MaybeUninit::<libc::stat>::uninit();
+                let mut stat2 = MaybeUninit::<libc::stat>::uninit();
+
+                if libc::fstat(self.fd, stat1.as_mut_ptr()) != 0 {
+                    return false;
+                }
+                if libc::fstat(other.fd, stat2.as_mut_ptr()) != 0 {
+                    return false;
+                }
+
+                let stat1 = stat1.assume_init();
+                let stat2 = stat2.assume_init();
+
+                stat1.st_dev == stat2.st_dev && stat1.st_ino == stat2.st_ino
+            }
+        }
+        #[cfg(not(any(target_os = "linux", target_os = "freebsd")))]
+        {
+            false
         }
     }
 }
