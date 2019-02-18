--- src/liblibc/src/unix/bsd/freebsdlike/freebsd/arm.rs.orig	2019-02-15 13:41:07 UTC
+++ src/liblibc/src/unix/bsd/freebsdlike/freebsd/arm.rs
@@ -0,0 +1,37 @@
+pub type c_char = u8;
+pub type c_long = i32;
+pub type c_ulong = u32;
+pub type time_t = i64;
+pub type suseconds_t = i32;
+
+s! {
+    pub struct stat {
+        pub st_dev: ::dev_t,
+        pub st_ino: ::ino_t,
+        pub st_mode: ::mode_t,
+        pub st_nlink: ::nlink_t,
+        pub st_uid: ::uid_t,
+        pub st_gid: ::gid_t,
+        pub st_rdev: ::dev_t,
+        pub st_atime: ::time_t,
+        pub st_atime_nsec: ::c_long,
+        pub st_atime_pad: ::c_long,
+        pub st_mtime: ::time_t,
+        pub st_mtime_nsec: ::c_long,
+        pub st_mtime_pad: ::c_long,
+        pub st_ctime: ::time_t,
+        pub st_ctime_nsec: ::c_long,
+        pub st_ctime_pad: ::c_long,
+        pub st_size: ::off_t,
+        pub st_blocks: ::blkcnt_t,
+        pub st_blksize: ::blksize_t,
+        pub st_flags: ::fflags_t,
+        pub st_gen: ::uint32_t,
+        pub st_lspare: ::int32_t,
+        pub st_birthtime: ::time_t,
+        pub st_birthtime_nsec: ::c_long,
+        pub st_birthtime_pad: ::c_long,
+    }
+}
+
+pub const MAP_32BIT: ::c_int = 0x00080000;
