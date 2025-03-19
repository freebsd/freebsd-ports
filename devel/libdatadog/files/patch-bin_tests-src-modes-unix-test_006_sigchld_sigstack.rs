--- bin_tests/src/modes/unix/test_006_sigchld_sigstack.rs.orig	2024-11-07 05:44:42 UTC
+++ bin_tests/src/modes/unix/test_006_sigchld_sigstack.rs
@@ -120,8 +120,6 @@ pub fn setup(output_dir: &Path) -> anyhow::Result<()> 
         sa_sigaction: sigchld_handler as usize,
         sa_mask: sigset,
         sa_flags: libc::SA_RESTART | libc::SA_SIGINFO,
-        #[cfg(not(target_os = "macos"))]
-        sa_restorer: None,
     };
 
     // Register the handler for SIGCHLD
