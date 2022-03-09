https://github.com/rust-lang/stdarch/pull/1290/commits/4557e223d895067d5c5a627c26929de060868c22

--- library/stdarch/crates/std_detect/src/detect/os/aarch64.rs.orig     2022-03-08 09:13:53 UTC
+++ library/stdarch/crates/std_detect/src/detect/os/aarch64.rs
@@ -16,6 +16,7 @@
 //! - [Zircon implementation](https://fuchsia.googlesource.com/zircon/+/master/kernel/arch/arm64/feature.cpp)
 //! - [Linux documentation](https://www.kernel.org/doc/Documentation/arm64/cpu-feature-registers.txt)
 
+use core::arch::asm;
 use crate::detect::{cache, Feature};
 
 /// Try to read the features from the system registers.

