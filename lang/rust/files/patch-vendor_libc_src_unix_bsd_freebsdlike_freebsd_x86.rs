--- vendor/libc/src/unix/bsd/freebsdlike/freebsd/x86.rs.orig	2018-06-19 05:52:22 UTC
+++ vendor/libc/src/unix/bsd/freebsdlike/freebsd/x86.rs
@@ -1,3 +1,4 @@
+pub type c_char = i8;
 pub type c_long = i32;
 pub type c_ulong = u32;
 pub type time_t = i32;
