--- src/vendor/openssl-sys/src/dtls1.rs.orig	2018-09-16 20:29:19 UTC
+++ src/vendor/openssl-sys/src/dtls1.rs
@@ -0,0 +1,3 @@
+use libc::*;
+
+pub const DTLS1_COOKIE_LENGTH: c_uint = 256;
