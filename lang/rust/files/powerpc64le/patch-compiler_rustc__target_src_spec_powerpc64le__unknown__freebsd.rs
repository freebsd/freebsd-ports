--- compiler/rustc_target/src/spec/powerpc64le_unknown_freebsd.rs.orig	2021-01-07 03:05:53 UTC
+++ compiler/rustc_target/src/spec/powerpc64le_unknown_freebsd.rs
@@ -0,0 +1,16 @@
+use crate::spec::{LinkerFlavor, Target, TargetOptions};
+
+pub fn target() -> Target {
+    let mut base = super::freebsd_base::opts();
+    base.cpu = "ppc64le".to_string();
+    base.pre_link_args.get_mut(&LinkerFlavor::Gcc).unwrap().push("-m64".to_string());
+    base.max_atomic_width = Some(64);
+
+    Target {
+        llvm_target: "powerpc64le-unknown-freebsd".to_string(),
+	pointer_width: 64,
+        data_layout: "e-m:e-i64:64-n32:64".to_string(),
+        arch: "powerpc64".to_string(),
+        options: TargetOptions { endian: "little".to_string(), mcount: "_mcount".to_string(), ..base },
+    }
+}
