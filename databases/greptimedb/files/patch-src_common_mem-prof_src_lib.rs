--- src/common/mem-prof/src/lib.rs.orig	2026-04-08 15:15:27 UTC
+++ src/common/mem-prof/src/lib.rs
@@ -14,55 +14,55 @@ pub mod error;
 
 pub mod error;
 
-#[cfg(not(windows))]
+#[cfg(not(any(windows, target_os = "freebsd")))]
 mod jemalloc;
-#[cfg(not(windows))]
+#[cfg(not(any(windows, target_os = "freebsd")))]
 pub use jemalloc::{
     activate_heap_profile, deactivate_heap_profile, dump_flamegraph, dump_pprof, dump_profile,
     is_gdump_active, is_heap_profile_active, set_gdump_active, symbolicate_jeheap,
 };
 
-#[cfg(windows)]
+#[cfg(any(windows, target_os = "freebsd"))]
 pub async fn dump_profile() -> error::Result<Vec<u8>> {
     error::ProfilingNotSupportedSnafu.fail()
 }
 
-#[cfg(windows)]
+#[cfg(any(windows, target_os = "freebsd"))]
 pub async fn dump_pprof() -> error::Result<Vec<u8>> {
     error::ProfilingNotSupportedSnafu.fail()
 }
 
-#[cfg(windows)]
+#[cfg(any(windows, target_os = "freebsd"))]
 pub async fn dump_flamegraph() -> error::Result<Vec<u8>> {
     error::ProfilingNotSupportedSnafu.fail()
 }
 
-#[cfg(windows)]
+#[cfg(any(windows, target_os = "freebsd"))]
 pub fn activate_heap_profile() -> error::Result<()> {
     error::ProfilingNotSupportedSnafu.fail()
 }
 
-#[cfg(windows)]
+#[cfg(any(windows, target_os = "freebsd"))]
 pub fn deactivate_heap_profile() -> error::Result<()> {
     error::ProfilingNotSupportedSnafu.fail()
 }
 
-#[cfg(windows)]
+#[cfg(any(windows, target_os = "freebsd"))]
 pub fn is_heap_profile_active() -> error::Result<bool> {
     error::ProfilingNotSupportedSnafu.fail()
 }
 
-#[cfg(windows)]
+#[cfg(any(windows, target_os = "freebsd"))]
 pub fn is_gdump_active() -> error::Result<bool> {
     error::ProfilingNotSupportedSnafu.fail()
 }
 
-#[cfg(windows)]
+#[cfg(any(windows, target_os = "freebsd"))]
 pub fn set_gdump_active(_: bool) -> error::Result<()> {
     error::ProfilingNotSupportedSnafu.fail()
 }
 
-#[cfg(windows)]
+#[cfg(any(windows, target_os = "freebsd"))]
 pub fn symbolicate_jeheap(_dump_content: &[u8]) -> error::Result<Vec<u8>> {
     error::ProfilingNotSupportedSnafu.fail()
 }
