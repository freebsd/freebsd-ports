--- vendor/rustc-ap-rustc_target/spec/mod.rs.orig	2019-04-08 14:18:26 UTC
+++ vendor/rustc-ap-rustc_target/spec/mod.rs
@@ -368,6 +368,8 @@ supported_targets! {
     ("aarch64-linux-android", aarch64_linux_android),
 
     ("aarch64-unknown-freebsd", aarch64_unknown_freebsd),
+    ("armv6-unknown-freebsd", armv6_unknown_freebsd),
+    ("armv7-unknown-freebsd", armv7_unknown_freebsd),
     ("i686-unknown-freebsd", i686_unknown_freebsd),
     ("powerpc64-unknown-freebsd", powerpc64_unknown_freebsd),
     ("x86_64-unknown-freebsd", x86_64_unknown_freebsd),
