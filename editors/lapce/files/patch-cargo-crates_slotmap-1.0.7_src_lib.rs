--- cargo-crates/slotmap-1.0.7/src/lib.rs.orig	2024-05-08 07:30:16 UTC
+++ cargo-crates/slotmap-1.0.7/src/lib.rs
@@ -10,7 +10,7 @@
     unused_lifetimes,
     unused_import_braces
 )]
-#![deny(missing_docs, unaligned_references)]
+#![deny(missing_docs)]
 #![cfg_attr(feature = "cargo-clippy", allow(renamed_and_removed_lints))]
 #![cfg_attr(feature = "cargo-clippy", deny(clippy, clippy_pedantic))]
 #![cfg_attr(
