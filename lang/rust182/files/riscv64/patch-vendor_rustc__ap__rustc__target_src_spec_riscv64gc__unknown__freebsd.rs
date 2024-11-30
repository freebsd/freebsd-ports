--- vendor/rustc-ap-rustc_target/src/spec/riscv64gc_unknown_freebsd.rs.orig	2021-11-04 11:22:10 UTC
+++ vendor/rustc-ap-rustc_target/src/spec/riscv64gc_unknown_freebsd.rs
@@ -0,0 +1,18 @@
+use crate::spec::{CodeModel, Target, TargetOptions};
+
+pub fn target() -> Target {
+    Target {
+        llvm_target: "riscv64-unknown-freebsd".to_string(),
+        pointer_width: 64,
+        data_layout: "e-m:e-p:64:64-i64:64-i128:128-n64-S128".to_string(),
+        arch: "riscv64".to_string(),
+        options: TargetOptions {
+            code_model: Some(CodeModel::Medium),
+            cpu: "generic-rv64".to_string(),
+            features: "+m,+a,+f,+d,+c".to_string(),
+            llvm_abiname: "lp64d".to_string(),
+            max_atomic_width: Some(64),
+            ..super::freebsd_base::opts()
+        },
+    }
+}
