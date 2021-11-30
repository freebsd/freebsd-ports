--- library/backtrace/src/backtrace/mod.rs.orig	2021-11-10 18:42:11 UTC
+++ library/backtrace/src/backtrace/mod.rs
@@ -138,6 +138,7 @@ cfg_if::cfg_if! {
                 unix,
                 not(target_os = "emscripten"),
                 not(all(target_os = "ios", target_arch = "arm")),
+                not(all(target_os = "freebsd", target_arch = "arm")),
             ),
             all(
                 target_env = "sgx",
