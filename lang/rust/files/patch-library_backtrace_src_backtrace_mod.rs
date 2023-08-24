--- library/backtrace/src/backtrace/mod.rs.orig	2021-11-29 19:27:28 UTC
+++ library/backtrace/src/backtrace/mod.rs
@@ -139,6 +139,7 @@ cfg_if::cfg_if! {
                 not(target_os = "emscripten"),
                 not(all(target_os = "ios", target_arch = "arm")),
                 not(all(target_os = "nto", target_env = "nto70")),
+                not(all(target_os = "freebsd", target_arch = "riscv64")),
             ),
             all(
                 target_env = "sgx",
