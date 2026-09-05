--- src/cargo-crates/s2n-tls-0.3.42/src/init.rs.orig	2026-08-16 16:47:45 UTC
+++ src/cargo-crates/s2n-tls-0.3.42/src/init.rs
@@ -145,6 +145,13 @@ mod mem {
         // `max_align_t` is a type with the largest alignment of any scalar
         // type, so aligning to its requirement will produce an alignment
         // suitable to the C requirement for malloc.
+        #[cfg(all(target_os = "freebsd", target_arch = "aarch64"))]
+        // The `libc` crate does not expose `max_align_t` for
+        // aarch64-unknown-freebsd. On FreeBSD/aarch64, `max_align_t` is
+        // `long double` whose alignment is 16 bytes; `u128` has the same
+        // 16-byte alignment and is a stable substitute.
+        const ALIGNMENT: usize = align_of::<u128>();
+        #[cfg(not(all(target_os = "freebsd", target_arch = "aarch64")))]
         const ALIGNMENT: usize = align_of::<libc::max_align_t>();
 
         // * align must not be zero,
