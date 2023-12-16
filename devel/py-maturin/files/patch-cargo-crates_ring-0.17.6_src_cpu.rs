--- cargo-crates/ring-0.17.6/src/cpu.rs.orig	1973-11-29 21:33:09 UTC
+++ cargo-crates/ring-0.17.6/src/cpu.rs
@@ -34,6 +34,7 @@ pub(crate) fn features() -> Features {
             any(
                 target_os = "android",
                 target_os = "fuchsia",
+                target_os = "freebsd",
                 target_os = "linux",
                 target_os = "windows"
             )
