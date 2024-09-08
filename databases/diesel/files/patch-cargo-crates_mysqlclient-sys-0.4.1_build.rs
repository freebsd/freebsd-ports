--- cargo-crates/mysqlclient-sys-0.4.1/build.rs.orig	2024-07-05 21:55:33 UTC
+++ cargo-crates/mysqlclient-sys-0.4.1/build.rs
@@ -198,6 +198,7 @@ fn parse_version(version_str: &str) {
         }
         (Some(Mysql5), "x86_64" | "aarch64", "64", false) => "bindings_5_7_42_x86_64_linux.rs",
         (Some(Mysql80), "x86_64" | "aarch64", "64", false) => "bindings_8_0_36_x86_64_linux.rs",
+        (Some(Mysql80), "powerpc64", "64", false) => "bindings_8_0_35_powerpc64_freebsd.rs",
         (Some(Mysql80), "x86" | "arm", "32", false) => "bindings_8_0_37_i686_linux.rs",
         (Some(Mysql80), "x86_64", "64", true) => "bindings_8_0_36_x86_64_windows.rs",
         (Some(Mysql80), "x86", "32", true) => "bindings_8_0_36_i686_windows.rs",
