--- cargo-crates/rust-htslib-0.44.1/src/bam/record.rs.orig	2024-12-26 16:34:58 UTC
+++ cargo-crates/rust-htslib-0.44.1/src/bam/record.rs
@@ -2216,7 +2216,7 @@ pub struct BaseModificationMetadata {
 pub struct BaseModificationMetadata {
     pub strand: i32,
     pub implicit: i32,
-    pub canonical: i8,
+    pub canonical: c_char,
 }
 
 /// struct containing the internal state required to access
@@ -2314,7 +2314,7 @@ impl BaseModificationState<'_> {
         unsafe {
             let mut strand: i32 = 0;
             let mut implicit: i32 = 0;
-            let mut canonical: i8 = 0;
+            let mut canonical: c_char = 0;
 
             let ret = hts_sys::bam_mods_query_type(
                 self.state,
