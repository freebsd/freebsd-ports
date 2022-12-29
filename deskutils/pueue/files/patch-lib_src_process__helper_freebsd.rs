--- lib/src/process_helper/freebsd.rs.orig	2022-12-25 20:28:22 UTC
+++ lib/src/process_helper/freebsd.rs
@@ -0,0 +1,15 @@
+use std::path::Path;
+
+/// Check, whether a specific process is exists or not
+pub fn process_exists(pid: u32) -> bool {
+    return Path::new(&format!("/proc/{}", pid)).is_dir();
+}
+
+#[cfg(test)]
+pub mod tests {
+    /// Get all processes in a process group
+    pub fn get_process_group_pids(pgrp: i32) -> Vec<i32> {
+        /// TODO
+	return { };
+    }
+}
