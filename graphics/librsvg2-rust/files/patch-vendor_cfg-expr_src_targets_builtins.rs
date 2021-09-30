--- vendor/cfg-expr/src/targets/builtins.rs.orig	2021-09-30 14:33:28 UTC
+++ vendor/cfg-expr/src/targets/builtins.rs
@@ -1004,6 +1004,16 @@ pub const ALL_BUILTINS: &[TargetInfo<'static>] = &[
         endian: Endian::big,
     },
     TargetInfo {
+        triple: "powerpc64le-unknown-freebsd",
+        os: Some(Os::freebsd),
+        arch: Arch::powerpc64,
+        env: None,
+        vendor: Some(Vendor::unknown),
+        family: Some(Family::unix),
+        pointer_width: 64,
+        endian: Endian::little,
+    },
+    TargetInfo {
         triple: "powerpc64le-unknown-linux-gnu",
         os: Some(Os::linux),
         arch: Arch::powerpc64,
