https://github.com/EmbarkStudios/cfg-expr/commit/f8c59a8dccd0

--- vendor/cfg-expr/src/targets/builtins.rs.orig	2021-12-17 19:33:07 UTC
+++ vendor/cfg-expr/src/targets/builtins.rs
@@ -914,6 +914,16 @@ pub const ALL_BUILTINS: &[TargetInfo] = &[
         endian: Endian::little,
     },
     TargetInfo {
+        triple: Triple::new_const("powerpc-unknown-freebsd"),
+        os: Some(Os::freebsd),
+        arch: Arch::powerpc,
+        env: None,
+        vendor: Some(Vendor::unknown),
+        family: Some(Family::unix),
+        pointer_width: 32,
+        endian: Endian::big,
+    },
+    TargetInfo {
         triple: Triple::new_const("powerpc-unknown-linux-gnu"),
         os: Some(Os::linux),
         arch: Arch::powerpc,
@@ -1002,6 +1012,16 @@ pub const ALL_BUILTINS: &[TargetInfo] = &[
         family: Some(Family::unix),
         pointer_width: 64,
         endian: Endian::big,
+    },
+    TargetInfo {
+        triple: Triple::new_const("powerpc64le-unknown-freebsd"),
+        os: Some(Os::freebsd),
+        arch: Arch::powerpc64,
+        env: None,
+        vendor: Some(Vendor::unknown),
+        family: Some(Family::unix),
+        pointer_width: 64,
+        endian: Endian::little,
     },
     TargetInfo {
         triple: Triple::new_const("powerpc64-unknown-linux-musl"),
