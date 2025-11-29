--- builder/src/arch/freebsd.rs.orig    2025-11-26 08:32:19 UTC
+++ builder/src/arch/freebsd.rs
@@ -0,0 +1,37 @@
+use std::ffi::OsStr;
+
+use std::process::Command;
+
+pub const NATIVE_LIBS: &str = " -lc -ldl -lm -lpthread -lrt -lutil";
+pub const PROF_DYNAMIC_LIB: &str = "libdatadog_profiling.so";
+pub const PROF_STATIC_LIB: &str = "libdatadog_profiling.a";
+pub const PROF_DYNAMIC_LIB_FFI: &str = "libdatadog_profiling_ffi.so";
+pub const PROF_STATIC_LIB_FFI: &str = "libdatadog_profiling_ffi.a";
+pub const REMOVE_RPATH: bool = false;
+pub const BUILD_CRASHTRACKER: bool = true;
+// pub const RUSTFLAGS: [&str; 4] = ["-C", "relocation-model=pic"];
+pub const RUSTFLAGS: [&str; 4] = ["-C", "relocation-model=pic", "-C", "link-arg=-Wl,-soname,libdatadog_profiling.so"];
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
+pub fn strip_libraries(lib_path: &str) {
+    let mut strip = Command::new("strip")
+        .arg("-S")
+        .arg(lib_path.to_owned() + "/libdatadog_profiling.so")
+        .spawn()
+        .expect("Failed to spawn strip");
+
+    strip.wait().expect("Failed to strip library");
+}
+
+pub fn add_additional_files(_lib_path: &str, _target_path: &OsStr) {}
