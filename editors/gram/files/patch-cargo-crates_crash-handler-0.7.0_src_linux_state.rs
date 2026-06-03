--- cargo-crates/crash-handler-0.7.0/src/linux/state.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/crash-handler-0.7.0/src/linux/state.rs
@@ -385,14 +385,22 @@ unsafe extern "C" fn signal_handler(
             // In order to retrigger it, we have to queue a new signal by calling
             // kill() ourselves.  The special case (si_pid == 0 && sig == SIGABRT) is
             // due to the kernel sending a SIGABRT from a user request via SysRQ.
-            let tid = libc::syscall(libc::SYS_gettid) as i32;
-            if libc::syscall(libc::SYS_tgkill, std::process::id(), tid, sig) < 0 {
-                // If we failed to kill ourselves (e.g. because a sandbox disallows us
-                // to do so), we instead resort to terminating our process. This will
-                // result in an incorrect exit code.
-                libc::_exit(1);
+            #[cfg(any(target_os = "linux", target_os = "android"))]
+            {
+                let tid = libc::syscall(libc::SYS_gettid) as i32;
+                if libc::syscall(libc::SYS_tgkill, std::process::id(), tid, sig) < 0 {
+                    // If we failed to kill ourselves (e.g. because a sandbox disallows us
+                    // to do so), we instead resort to terminating our process. This will
+                    // result in an incorrect exit code.
+                    libc::_exit(1);
+                }
             }
-        } else {
+            #[cfg(target_os = "freebsd")]
+            {
+                if libc::pthread_kill(libc::pthread_self(), sig as i32) != 0 {
+                    libc::_exit(1);
+                }
+            }
             // This was a synchronous signal triggered by a hard fault (e.g. SIGSEGV).
             // No need to reissue the signal. It will automatically trigger again,
             // when we return from the signal handler.
@@ -428,7 +436,10 @@ impl HandlerInner {
             // The siginfo_t in libc is lowest common denominator, but this code is
             // specifically targeting linux/android, which contains the si_pid field
             // that we require
+            #[cfg(any(target_os = "linux", target_os = "android"))]
             let nix_info = &*((info as *const libc::siginfo_t).cast::<libc::signalfd_siginfo>());
+            #[cfg(target_os = "freebsd")]
+            let nix_info = &*info;
 
             debug_print!("acquired siginfo");
 
@@ -450,6 +461,7 @@ impl HandlerInner {
                 ptr::copy_nonoverlapping(uc_ptr, &mut cc.context, 1);
                 debug_print!("copied context");
 
+                #[cfg(not(target_os = "freebsd"))]
                 cfg_if::cfg_if! {
                     if #[cfg(target_arch = "aarch64")] {
                         let fp_ptr = uc_ptr.uc_mcontext.__reserved.as_ptr().cast::<crash_context::fpsimd_context>();
@@ -467,7 +479,10 @@ impl HandlerInner {
                 }
 
                 cc.pid = std::process::id() as i32;
-                cc.tid = libc::syscall(libc::SYS_gettid) as i32;
+                #[cfg(any(target_os = "linux", target_os = "android"))]
+                { cc.tid = libc::syscall(libc::SYS_gettid) as i32; }
+                #[cfg(target_os = "freebsd")]
+                { cc.tid = libc::getpid(); }
             }
 
             self.handler.on_crash(&cc)
@@ -477,9 +492,13 @@ impl HandlerInner {
 
 /// We define these constans ourselves rather than use libc as they are missing
 /// from eg. Android
+#[cfg(any(target_os = "linux", target_os = "android"))]
 const PR_GET_DUMPABLE: i32 = 3;
+#[cfg(any(target_os = "linux", target_os = "android"))]
 const PR_SET_DUMPABLE: i32 = 4;
+#[cfg(any(target_os = "linux", target_os = "android"))]
 const PR_SET_PTRACER: i32 = 0x59616d61;
+#[cfg(any(target_os = "linux", target_os = "android"))]
 const PR_SET_PTRACER_ANY: i32 = -1;
 
 /// Helper that sets the process as dumpable if it is not, and when dropped
@@ -490,33 +509,41 @@ impl SetDumpable {
 
 impl SetDumpable {
     unsafe fn new(dump_process: Option<u32>) -> Self {
-        unsafe {
-            let is_dumpable = libc::syscall(libc::SYS_prctl, PR_GET_DUMPABLE, 0, 0, 0, 0);
-            let was_dumpable = is_dumpable > 0;
+        cfg_if::cfg_if! {
+            if #[cfg(any(target_os = "linux", target_os = "android"))] {
+                unsafe {
+                    let is_dumpable = libc::syscall(libc::SYS_prctl, PR_GET_DUMPABLE, 0, 0, 0, 0);
+                    let was_dumpable = is_dumpable > 0;
 
-            if !was_dumpable {
-                libc::syscall(libc::SYS_prctl, PR_SET_DUMPABLE, 1, 0, 0, 0);
-            }
+                    if !was_dumpable {
+                        libc::syscall(libc::SYS_prctl, PR_SET_DUMPABLE, 1, 0, 0, 0);
+                    }
 
-            // Set the process that is allowed to do ptrace operations on this process,
-            // we either set it to the process that the user specified, or allow
-            // any process, which _somewhat_ defeats the purpose of the yama security
-            // that this call is needed for
-            let ptracer = dump_process.map_or(PR_SET_PTRACER_ANY, |dp| dp as i32);
+                    // Set the process that is allowed to do ptrace operations on this process,
+                    // we either set it to the process that the user specified, or allow
+                    // any process, which _somewhat_ defeats the purpose of the yama security
+                    // that this call is needed for
+                    let ptracer = dump_process.map_or(PR_SET_PTRACER_ANY, |dp| dp as i32);
 
-            // Note that this will fail with EINVAL if the pid does not exist, but
-            // that would be on the user. We only need to do this if
-            // `/proc/sys/kernel/yama/ptrace_scope` = 1, but should not have a negative
-            // impact if it is in any other mode
-            libc::syscall(libc::SYS_prctl, PR_SET_PTRACER, ptracer, 0, 0, 0);
+                    // Note that this will fail with EINVAL if the pid does not exist, but
+                    // that would be on the user. We only need to do this if
+                    // `/proc/sys/kernel/yama/ptrace_scope` = 1, but should not have a negative
+                    // impact if it is in any other mode
+                    libc::syscall(libc::SYS_prctl, PR_SET_PTRACER, ptracer, 0, 0, 0);
 
-            Self { was_dumpable }
+                    Self { was_dumpable }
+                }
+            } else {
+                let _ = dump_process;
+                Self { was_dumpable: true }
+            }
         }
     }
 }
 
 impl Drop for SetDumpable {
     fn drop(&mut self) {
+        #[cfg(any(target_os = "linux", target_os = "android"))]
         unsafe {
             libc::syscall(libc::SYS_prctl, PR_SET_PTRACER, 0, 0, 0, 0);
 
