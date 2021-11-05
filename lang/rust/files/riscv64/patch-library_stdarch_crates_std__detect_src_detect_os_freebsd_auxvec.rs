--- library/stdarch/crates/std_detect/src/detect/os/freebsd/auxvec.rs.orig	2021-10-18 09:52:55 UTC
+++ library/stdarch/crates/std_detect/src/detect/os/freebsd/auxvec.rs
@@ -3,7 +3,8 @@
     any(
         target_arch = "aarch64",
         target_arch = "arm",
-        target_arch = "powerpc64"
+        target_arch = "powerpc64",
+        target_arch = "riscv64"
     ),
     allow(dead_code)
 )]
