--- builder/src/arch/freebsd.rs.orig	2025-03-17 18:38:16 UTC
+++ builder/src/arch/freebsd.rs
@@ -0,0 +1,18 @@
+use std::process::Command;
+
+pub const NATIVE_LIBS: &str = " -lc -ldl -lm -lpthread -lrt -lutil";
+pub const REMOVE_RPATH: bool = false;
+pub const RUSTFLAGS: [&str; 2] = ["-C", "relocation-model=pic"];
+
+pub fn fix_rpath(lib_path: &str) {
+    if REMOVE_RPATH {
+        let mut patchelf = Command::new("patchelf")
+            .arg("--remove-rpath")
+            .arg(lib_path)
+            .spawn()
+            .expect("failed to spawn patchelf");
+
+        patchelf.wait().expect("failed to remove rpath");
+    }
+}
+
