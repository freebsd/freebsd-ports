--- src/vendor/openssl-sys/src/ssl3.rs.orig	2018-09-16 20:29:19 UTC
+++ src/vendor/openssl-sys/src/ssl3.rs
@@ -0,0 +1,5 @@
+use libc::*;
+
+pub const SSL3_VERSION: c_int = 0x300;
+
+pub const SSL3_AD_ILLEGAL_PARAMETER: c_int = 47;
