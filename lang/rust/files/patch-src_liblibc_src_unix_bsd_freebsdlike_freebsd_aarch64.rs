--- src/liblibc/src/unix/bsd/freebsdlike/freebsd/aarch64.rs.orig	2018-06-19 04:36:14 UTC
+++ src/liblibc/src/unix/bsd/freebsdlike/freebsd/aarch64.rs
@@ -1,3 +1,4 @@
+pub type c_char = u8;
 pub type c_long = i64;
 pub type c_ulong = u64;
 pub type time_t = i64;
