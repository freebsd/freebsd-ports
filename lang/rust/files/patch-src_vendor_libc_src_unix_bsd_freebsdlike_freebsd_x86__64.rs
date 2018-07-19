--- src/vendor/libc/src/unix/bsd/freebsdlike/freebsd/x86_64.rs.orig	2018-06-19 05:52:22 UTC
+++ src/vendor/libc/src/unix/bsd/freebsdlike/freebsd/x86_64.rs
@@ -1,3 +1,4 @@
+pub type c_char = i8;
 pub type c_long = i64;
 pub type c_ulong = u64;
 pub type time_t = i64;
