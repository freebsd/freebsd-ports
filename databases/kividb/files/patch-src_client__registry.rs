--- src/client_registry.rs.orig	2026-11-02 17:38:14 UTC
+++ src/client_registry.rs
@@ -693,7 +693,8 @@ pub fn clients_that_fit(max: usize) -> std::io::Result
     // whatever the hard limit says.
     let (mut soft, mut high) = (limit.rlim_cur, wanted.min(limit.rlim_max));
     while soft < high {
-        let next = soft + (high - soft).div_ceil(2);
+        let gap = high - soft;
+        let next = soft + gap / 2 + gap % 2;
         let raised = libc::rlimit {
             rlim_cur: next,
             rlim_max: limit.rlim_max,
