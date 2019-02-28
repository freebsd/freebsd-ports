error: `[7:4]` cannot be resolved, ignoring it...
 --> src/libstd/../stdsimd/stdsimd/arch/detect/os/aarch64.rs:9:27
  |
9 | //! when ID_AA64ISAR0_EL1[7:4] is >= 1, AES is supported; when it's >= 2, PMULL is supported.
  |                           ^^^ cannot be resolved, ignoring
  |
note: lint level defined here
 --> src/libstd/lib.rs:215:9
  |
21| #![deny(intra_doc_link_resolution_failure)]
  |         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  = help: to escape `[` and `]` characters, just add '\' before them like `\[` or `\]`

--- src/stdsimd/stdsimd/arch/detect/os/aarch64.rs.orig	2019-02-25 09:19:48 UTC
+++ src/stdsimd/stdsimd/arch/detect/os/aarch64.rs
@@ -6,7 +6,7 @@
 //! AArch64 system registers ID_AA64ISAR0_EL1, ID_AA64PFR0_EL1, ID_AA64ISAR1_EL1
 //! have bits dedicated to features like AdvSIMD, CRC32, AES, atomics (LSE), etc.
 //! Each part of the register indicates the level of support for a certain feature, e.g.
-//! when ID_AA64ISAR0_EL1[7:4] is >= 1, AES is supported; when it's >= 2, PMULL is supported.
+//! when ID_AA64ISAR0_EL1\[7:4\] is >= 1, AES is supported; when it's >= 2, PMULL is supported.
 //!
 //! For proper support of [SoCs where different cores have different capabilities](https://medium.com/@jadr2ddude/a-big-little-problem-a-tale-of-big-little-gone-wrong-e7778ce744bb),
 //! the OS has to always report only the features supported by all cores, like [FreeBSD does](https://reviews.freebsd.org/D17137#393947).
