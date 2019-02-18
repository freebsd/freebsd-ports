--- vendor/libc/src/unix/bsd/freebsdlike/mod.rs.orig	2019-01-16 11:06:08 UTC
+++ vendor/libc/src/unix/bsd/freebsdlike/mod.rs
@@ -1,4 +1,3 @@
-pub type c_char = i8;
 pub type dev_t = u32;
 pub type mode_t = u16;
 pub type pthread_attr_t = *mut ::c_void;
@@ -83,8 +82,7 @@ s! {
     }
 
     pub struct stack_t {
-        // In FreeBSD 11 and later, ss_sp is actually a void*
-        pub ss_sp: *mut ::c_char,
+        pub ss_sp: *mut ::c_void,
         pub ss_size: ::size_t,
         pub ss_flags: ::c_int,
     }
