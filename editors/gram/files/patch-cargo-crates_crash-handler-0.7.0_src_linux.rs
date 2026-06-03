--- cargo-crates/crash-handler-0.7.0/src/linux.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/crash-handler-0.7.0/src/linux.rs
@@ -52,6 +52,7 @@ impl CrashHandler {
         state::detach();
     }
 
+    #[cfg(target_os = "linux")]
     /// Set the process that is allowed to perform `ptrace` operations on the
     /// current process.
     ///
@@ -88,10 +89,18 @@ impl CrashHandler {
         // uphold any guarantees on their end, so no real need to declare the
         // function itself unsafe.
         unsafe {
-            let mut siginfo: libc::signalfd_siginfo = std::mem::zeroed();
-            siginfo.ssi_signo = signal;
-            siginfo.ssi_code = state::SI_USER;
-            siginfo.ssi_pid = std::process::id();
+            cfg_if::cfg_if! {
+                if #[cfg(any(target_os = "linux", target_os = "android"))] {
+                    let mut siginfo: libc::signalfd_siginfo = std::mem::zeroed();
+                    siginfo.ssi_signo = signal;
+                    siginfo.ssi_code = state::SI_USER;
+                    siginfo.ssi_pid = std::process::id();
+                    let siginfo_ptr = &mut *(&mut siginfo as *mut libc::signalfd_siginfo).cast::<libc::siginfo_t>();
+                } else {
+                    let mut siginfo: libc::siginfo_t = std::mem::zeroed();
+                    let siginfo_ptr = &mut siginfo;
+                }
+            }
 
             let mut context = std::mem::zeroed();
             crash_context::crash_context_getcontext(&mut context);
@@ -99,7 +108,7 @@ impl CrashHandler {
             let lock = state::HANDLER.lock();
             if let Some(handler) = &*lock {
                 handler.handle_signal(
-                    &mut *(&mut siginfo as *mut libc::signalfd_siginfo).cast::<libc::siginfo_t>(),
+                    siginfo_ptr,
                     &mut *(&mut context as *mut crash_context::ucontext_t).cast::<libc::c_void>(),
                 )
             } else {
