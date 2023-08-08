--- pueue_lib/src/process_helper/mod.rs.orig	2023-03-31 21:59:47 UTC
+++ pueue_lib/src/process_helper/mod.rs
@@ -21,6 +21,14 @@ mod linux;
 #[cfg(target_os = "linux")]
 pub use self::linux::process_exists;
 
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
