--- cargo-crates/minidump-writer-0.12.0/src/process_reader.rs.orig	2026-09-15 04:07:57 UTC
+++ cargo-crates/minidump-writer-0.12.0/src/process_reader.rs
@@ -7,6 +7,9 @@ pub use crate::mac::process_reader::*;
 #[cfg(target_os = "macos")]
 pub use crate::mac::process_reader::*;
 
+#[cfg(target_os = "freebsd")]
+pub use crate::freebsd::process_reader::*;
+
 use std::{ffi::CString, mem::MaybeUninit};
 
 impl ProcessReader {
