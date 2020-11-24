--- /dev/null	2020-09-30 18:09:21.093949000 -0500
+++ src/librustc_target/spec/powerpc64le_unknown_freebsd.rs	2020-09-30 18:08:47.737833000 -0500
@@ -0,0 +1,22 @@
+use crate::spec::{LinkerFlavor, Target, TargetOptions, TargetResult};
+
+pub fn target() -> TargetResult {
+    let mut base = super::freebsd_base::opts();
+    base.cpu = "ppc64le".to_string();
+    base.pre_link_args.get_mut(&LinkerFlavor::Gcc).unwrap().push("-m64".to_string());
+    base.max_atomic_width = Some(64);
+
+    Ok(Target {
+        llvm_target: "powerpc64le-unknown-freebsd".to_string(),
+        target_endian: "little".to_string(),
+        target_pointer_width: "64".to_string(),
+        target_c_int_width: "32".to_string(),
+        data_layout: "e-m:e-i64:64-n32:64".to_string(),
+        arch: "powerpc64".to_string(),
+        target_os: "freebsd".to_string(),
+        target_env: String::new(),
+        target_vendor: "unknown".to_string(),
+        linker_flavor: LinkerFlavor::Gcc,
+        options: TargetOptions { target_mcount: "_mcount".to_string(), ..base },
+    })
+}
