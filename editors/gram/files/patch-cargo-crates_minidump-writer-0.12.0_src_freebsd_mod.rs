--- cargo-crates/minidump-writer-0.12.0/src/freebsd/mod.rs.orig	1970-01-01 00:00:00 UTC
+++ cargo-crates/minidump-writer-0.12.0/src/freebsd/mod.rs
@@ -0,0 +1,5 @@
+#![allow(clippy::result_large_err)]
+
+pub mod process_reader;
+
+pub type Pid = i32;
--- cargo-crates/minidump-writer-0.12.0/src/freebsd/process_reader.rs.orig	1970-01-01 00:00:00 UTC
+++ cargo-crates/minidump-writer-0.12.0/src/freebsd/process_reader.rs
@@ -0,0 +1,37 @@
+pub type ProcessHandle = libc::pid_t;
+
+#[derive(Debug, thiserror::Error, serde::Serialize)]
+#[error("Copy from process {child} failed (source {src}, offset: {offset}, length: {length}): {message}")]
+pub struct CopyFromProcessError {
+    pub child: super::Pid,
+    pub src: usize,
+    pub offset: usize,
+    pub length: usize,
+    message: String,
+}
+
+pub struct ProcessReader {
+    pid: libc::pid_t,
+}
+
+impl std::fmt::Debug for ProcessReader {
+    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
+        write!(f, "ProcessReader({})", self.pid)
+    }
+}
+
+impl ProcessReader {
+    pub fn new(pid: ProcessHandle) -> Self {
+        Self { pid }
+    }
+
+    pub fn read(&self, src: usize, dst: &mut [u8]) -> Result<usize, CopyFromProcessError> {
+        Err(CopyFromProcessError {
+            child: self.pid,
+            src,
+            offset: 0,
+            length: dst.len(),
+            message: "process reading is not supported on FreeBSD".to_string(),
+        })
+    }
+}
