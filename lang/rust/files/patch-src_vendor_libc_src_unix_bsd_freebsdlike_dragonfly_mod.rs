--- src/vendor/libc/src/unix/bsd/freebsdlike/dragonfly/mod.rs.orig	2018-06-19 05:52:22 UTC
+++ src/vendor/libc/src/unix/bsd/freebsdlike/dragonfly/mod.rs
@@ -1,3 +1,4 @@
+pub type c_char = i8;
 pub type clock_t = u64;
 pub type ino_t = u64;
 pub type lwpid_t = i32;
