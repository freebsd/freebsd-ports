--- vendor/nix-0.28.0/src/sys/signal.rs.orig	2024-06-14 14:06:00 UTC
+++ vendor/nix-0.28.0/src/sys/signal.rs
@@ -1099,7 +1099,7 @@ pub type type_of_thread_id = libc::lwpid_t;
 #[cfg(target_os = "freebsd")]
 pub type type_of_thread_id = libc::lwpid_t;
 /// Identifies a thread for [`SigevNotify::SigevThreadId`]
-#[cfg(all(not(target_os = "hurd"), any(target_env = "gnu", target_env = "uclibc")))]
+#[cfg(all(not(any(target_os = "freebsd", target_os = "hurd")), any(target_env = "gnu", target_env = "uclibc")))]
 pub type type_of_thread_id = libc::pid_t;
 
 /// Specifies the notification method used by a [`SigEvent`]
@@ -1349,7 +1349,7 @@ mod sigevent {
                     sev.sigev_value.sival_ptr = si_value as *mut libc::c_void;
                     sev._sigev_un._threadid = thread_id;
                 }
-                #[cfg(any(target_env = "gnu", target_env = "uclibc"))]
+                #[cfg(all(not(target_os = "freebsd"), any(target_env = "gnu", target_env = "uclibc")))]
                 SigevNotify::SigevThreadId{signal, thread_id, si_value} => {
                     sev.sigev_notify = libc::SIGEV_THREAD_ID;
                     sev.sigev_signo = signal as libc::c_int;
