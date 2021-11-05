--- library/std/src/os/raw/mod.rs.orig	2021-11-05 15:16:50 UTC
+++ library/std/src/os/raw/mod.rs
@@ -68,7 +68,8 @@ type_alias! { "char.md", c_char = u8, NonZero_c_char =
             target_arch = "aarch64",
             target_arch = "arm",
             target_arch = "powerpc",
-            target_arch = "powerpc64"
+            target_arch = "powerpc64",
+            target_arch = "riscv64"
         )
     ),
     all(
@@ -110,7 +111,8 @@ type_alias! { "char.md", c_char = i8, NonZero_c_char =
             target_arch = "aarch64",
             target_arch = "arm",
             target_arch = "powerpc",
-            target_arch = "powerpc64"
+            target_arch = "powerpc64",
+            target_arch = "riscv64"
         )
     ),
     all(
