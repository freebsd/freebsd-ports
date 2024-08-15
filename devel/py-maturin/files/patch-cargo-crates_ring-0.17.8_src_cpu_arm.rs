--- cargo-crates/ring-0.17.8/src/cpu/arm.rs.orig	1973-11-29 21:33:09 UTC
+++ cargo-crates/ring-0.17.8/src/cpu/arm.rs
@@ -45,29 +45,59 @@ mod abi_assumptions {
 // detection.
 
 #[cfg(all(
-    any(target_os = "android", target_os = "linux"),
+    any(target_os = "android", target_os = "freebsd", target_os = "linux"),
     any(target_arch = "aarch64", target_arch = "arm"),
     not(target_env = "uclibc")
 ))]
 fn detect_features() -> u32 {
     use libc::c_ulong;
+    #[cfg(target_os = "freebsd")]
+    use libc::{c_int, c_void};
+    #[cfg(target_os = "freebsd")]
+    extern crate std;
 
     // XXX: The `libc` crate doesn't provide `libc::getauxval` consistently
     // across all Android/Linux targets, e.g. musl.
+    #[cfg(any(target_os = "android", target_os = "linux"))]
     extern "C" {
         fn getauxval(type_: c_ulong) -> c_ulong;
     }
 
+    #[cfg(target_os = "freebsd")]
+    extern "C" {
+        fn elf_aux_info(aux: c_int, buf: *mut c_void, buflen: c_int) -> c_int;
+    }
+
+    #[cfg(not(target_os = "freebsd"))]
     const AT_HWCAP: c_ulong = 16;
 
+    #[cfg(target_os = "freebsd")]
+    const AT_HWCAP: c_int = 25;
+
     #[cfg(target_arch = "aarch64")]
     const HWCAP_NEON: c_ulong = 1 << 1;
 
     #[cfg(target_arch = "arm")]
     const HWCAP_NEON: c_ulong = 1 << 12;
 
+    #[cfg(not(target_os = "freebsd"))]
     let caps = unsafe { getauxval(AT_HWCAP) };
 
+    #[cfg(target_os = "freebsd")]
+    let caps: c_ulong = 0;
+
+    #[cfg(target_os = "freebsd")]
+    {
+        let buffer : *mut c_void = { let t: *const c_ulong = &caps; t} as *mut c_void;
+        unsafe {
+            let _ret = elf_aux_info(
+                AT_HWCAP,
+                buffer,
+                std::mem::size_of_val(&caps) as i32
+            );
+        }
+    }
+
     // We assume NEON is available on AARCH64 because it is a required
     // feature.
     #[cfg(target_arch = "aarch64")]
@@ -86,12 +116,27 @@ fn detect_features() -> u32 {
         #[cfg(target_arch = "arm")]
         const OFFSET: c_ulong = 0;
 
-        #[cfg(target_arch = "arm")]
+        #[cfg(target_os = "freebsd")]
+        let buffer : *mut c_void = { let t: *const c_ulong = &caps; t} as *mut c_void;
+
+        #[cfg(not(target_os = "freebsd"))]
         let caps = {
             const AT_HWCAP2: c_ulong = 26;
             unsafe { getauxval(AT_HWCAP2) }
         };
 
+        #[cfg(target_os = "freebsd")]
+        {
+            const AT_HWCAP2: c_int = 26;
+            unsafe {
+                let _ret = elf_aux_info(
+                    AT_HWCAP2,
+                    buffer,
+                    std::mem::size_of_val(&caps) as i32
+                );
+            };
+        }
+
         const HWCAP_AES: c_ulong = 1 << 0 + OFFSET;
         const HWCAP_PMULL: c_ulong = 1 << 1 + OFFSET;
         const HWCAP_SHA2: c_ulong = 1 << 3 + OFFSET;
@@ -175,6 +220,7 @@ fn detect_features() -> u32 {
 #[cfg(all(
     any(target_arch = "aarch64", target_arch = "arm"),
     not(any(
+        target_os = "freebsd",
         target_os = "android",
         target_os = "fuchsia",
         all(target_os = "linux", not(target_env = "uclibc")),
@@ -235,6 +281,7 @@ impl Feature {
 
         #[cfg(all(
             any(
+                target_os = "freebsd",
                 target_os = "android",
                 target_os = "fuchsia",
                 all(target_os = "linux", not(target_env = "uclibc")),
