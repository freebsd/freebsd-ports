--- lib/src/process_helper/mod.rs.orig	2022-12-25 19:55:17 UTC
+++ lib/src/process_helper/mod.rs
@@ -23,6 +23,14 @@ pub use self::linux::process_exists;
 #[cfg(all(test, target_os = "linux"))]
 use self::linux::tests;
 
+// FreeBSD specific process support
+#[cfg(target_os = "freebsd")]
+mod freebsd;
+#[cfg(target_os = "freebsd")]
+pub use self::freebsd::process_exists;
+#[cfg(all(test, target_os = "freebsd"))]
+use self::freebsd::tests;
+
 // Apple specific process support
 #[cfg(target_vendor = "apple")]
 mod apple;
