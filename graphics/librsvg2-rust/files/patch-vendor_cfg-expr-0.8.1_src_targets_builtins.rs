https://github.com/EmbarkStudios/cfg-expr/commit/f8c59a8dccd0

--- vendor/cfg-expr-0.8.1/src/targets/builtins.rs.orig	2021-09-16 01:15:26 UTC
+++ vendor/cfg-expr-0.8.1/src/targets/builtins.rs
@@ -894,6 +894,16 @@ pub const ALL_BUILTINS: &[TargetInfo<'static>] = &[
         endian: Endian::little,
     },
     TargetInfo {
+        triple: "powerpc-unknown-freebsd",
+        os: Some(Os::freebsd),
+        arch: Arch::powerpc,
+        env: None,
+        vendor: Some(Vendor::unknown),
+        family: Some(Family::unix),
+        pointer_width: 32,
+        endian: Endian::big,
+    },
+    TargetInfo {
         triple: "powerpc-unknown-linux-gnu",
         os: Some(Os::linux),
         arch: Arch::powerpc,
@@ -1002,6 +1012,16 @@ pub const ALL_BUILTINS: &[TargetInfo<'static>] = &[
         family: Some(Family::unix),
         pointer_width: 64,
         endian: Endian::big,
+    },
+    TargetInfo {
+        triple: "powerpc64le-unknown-freebsd",
+        os: Some(Os::freebsd),
+        arch: Arch::powerpc64,
+        env: None,
+        vendor: Some(Vendor::unknown),
+        family: Some(Family::unix),
+        pointer_width: 64,
+        endian: Endian::little,
     },
     TargetInfo {
         triple: "powerpc64le-unknown-linux-gnu",
