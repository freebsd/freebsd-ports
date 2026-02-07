--- library/backtrace/src/backtrace/mod.rs.orig	2024-10-02 09:23:54.876659000 +0200
+++ library/backtrace/src/backtrace/mod.rs	2024-10-02 09:23:44.139133000 +0200
@@ -176,6 +176,7 @@ cfg_if::cfg_if! {
                 unix,
                 not(target_os = "emscripten"),
                 not(all(target_os = "ios", target_arch = "arm")),
+                not(all(target_os = "freebsd", target_arch = "riscv64")),
             ),
             all(
                 target_env = "sgx",
