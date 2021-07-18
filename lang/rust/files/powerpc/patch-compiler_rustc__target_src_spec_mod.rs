--- compiler/rustc_target/src/spec/mod.rs.orig        2020-09-30 18:06:16.613040000 -0500
+++ compiler/rustc_target/src/spec/mod.rs     2021-04-23 18:06:47.040460000 -0500
@@ -765,6 +765,7 @@ fn $module() {
     ("armv6-unknown-freebsd", armv6_unknown_freebsd),
     ("armv7-unknown-freebsd", armv7_unknown_freebsd),
     ("i686-unknown-freebsd", i686_unknown_freebsd),
+    ("powerpc-unknown-freebsd", powerpc_unknown_freebsd),
     ("powerpc64-unknown-freebsd", powerpc64_unknown_freebsd),
     ("x86_64-unknown-freebsd", x86_64_unknown_freebsd),
 
