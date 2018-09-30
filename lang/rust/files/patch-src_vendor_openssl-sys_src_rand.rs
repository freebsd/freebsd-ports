--- src/vendor/openssl-sys/src/rand.rs.orig	2018-09-16 20:29:19 UTC
+++ src/vendor/openssl-sys/src/rand.rs
@@ -0,0 +1,6 @@
+use libc::*;
+
+extern "C" {
+    pub fn RAND_bytes(buf: *mut u8, num: c_int) -> c_int;
+    pub fn RAND_status() -> c_int;
+}
