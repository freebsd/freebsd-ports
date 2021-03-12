--- cargo-crates/ring-0.16.15/src/cpu.rs.orig	2021-03-12 09:24:30 UTC
+++ cargo-crates/ring-0.16.15/src/cpu.rs
@@ -24,16 +24,20 @@ pub(crate) struct Features(());
 
 #[inline(always)]
 pub(crate) fn features() -> Features {
-    // We don't do runtime feature detection on iOS. instead some features are
-    // assumed to be present; see `arm::Feature`.
-    #[cfg(all(
-        any(
-            target_arch = "aarch64",
-            target_arch = "arm",
-            target_arch = "x86",
-            target_arch = "x86_64"
-        ),
-        not(target_os = "ios")
+    // We don't do runtime feature detection on aarch64-apple-* as all AAarch64
+    // features we use are available on every device since the first devices.
+    #[cfg(any(
+        target_arch = "x86",
+        target_arch = "x86_64",
+        all(
+            any(target_arch = "aarch64", target_arch = "arm"),
+            any(
+                target_os = "android",
+                target_os = "fuchsia",
+                target_os = "freebsd",
+                target_os = "linux"
+            )
+        )
     ))]
     {
         static INIT: spin::Once<()> = spin::Once::new();
@@ -49,17 +53,17 @@ pub(crate) fn features() -> Features {
             }
 
             #[cfg(all(
-                any(target_os = "android", target_os = "linux"),
-                any(target_arch = "aarch64", target_arch = "arm")
+                any(target_arch = "aarch64", target_arch = "arm"),
+                any(
+                    target_os = "android",
+                    target_os = "fuchsia",
+                    target_os = "freebsd",
+                    target_os = "linux"
+                )
             ))]
             {
-                arm::linux_setup();
+                arm::setup();
             }
-
-            #[cfg(all(target_os = "fuchsia", any(target_arch = "aarch64")))]
-            {
-                arm::fuchsia_setup();
-            }
         });
     }
 
@@ -68,28 +72,57 @@ pub(crate) fn features() -> Features {
 
 pub(crate) mod arm {
     #[cfg(all(
-        any(target_os = "android", target_os = "linux"),
+        any(target_os = "android", target_os = "freebsd", target_os = "linux"),
         any(target_arch = "aarch64", target_arch = "arm")
     ))]
-    pub fn linux_setup() {
+    pub fn setup() {
         use libc::c_ulong;
+        #[cfg(target_os = "freebsd")]
+        use libc::{c_int, c_void};
+        #[cfg(target_os = "freebsd")]
+        extern crate std;
 
         // XXX: The `libc` crate doesn't provide `libc::getauxval` consistently
         // across all Android/Linux targets, e.g. musl.
+        #[cfg(any(target_os = "android", target_os = "linux"))]
         extern "C" {
             fn getauxval(type_: c_ulong) -> c_ulong;
         }
 
+        #[cfg(target_os = "freebsd")]
+        extern "C" {
+            fn elf_aux_info(aux: c_int, buf: *mut c_void, buflen: c_int) -> c_int;
+        }
+
+        #[cfg(not(target_os = "freebsd"))]
         const AT_HWCAP: c_ulong = 16;
 
+        #[cfg(target_os = "freebsd")]
+        const AT_HWCAP: c_int = 25;
+
         #[cfg(target_arch = "aarch64")]
         const HWCAP_NEON: c_ulong = 1 << 1;
 
         #[cfg(target_arch = "arm")]
         const HWCAP_NEON: c_ulong = 1 << 12;
 
+        #[cfg(not(target_os = "freebsd"))]
         let caps = unsafe { getauxval(AT_HWCAP) };
 
+        #[cfg(target_os = "freebsd")]
+        let caps: c_ulong = 0;
+
+        #[cfg(target_os = "freebsd")]
+        {
+            let buffer: *mut c_void = {
+                let t: *const c_ulong = &caps;
+                t
+            } as *mut c_void;
+            unsafe {
+                let _ret = elf_aux_info(AT_HWCAP, buffer, std::mem::size_of_val(&caps) as i32);
+            }
+        }
+
         // We assume NEON is available on AARCH64 because it is a required
         // feature.
         #[cfg(target_arch = "aarch64")]
@@ -106,12 +139,26 @@ pub(crate) mod arm {
             #[cfg(target_arch = "arm")]
             const OFFSET: c_ulong = 0;
 
-            #[cfg(target_arch = "arm")]
+            #[cfg(target_os = "freebsd")]
+            let buffer: *mut c_void = {
+                let t: *const c_ulong = &caps;
+                t
+            } as *mut c_void;
+
+            #[cfg(not(target_os = "freebsd"))]
             let caps = {
                 const AT_HWCAP2: c_ulong = 26;
                 unsafe { getauxval(AT_HWCAP2) }
             };
 
+            #[cfg(target_os = "freebsd")]
+            {
+                const AT_HWCAP2: c_int = 26;
+                unsafe {
+                    let _ret = elf_aux_info(AT_HWCAP2, buffer, std::mem::size_of_val(&caps) as i32);
+                };
+            }
+
             const HWCAP_AES: c_ulong = 1 << 0 + OFFSET;
             const HWCAP_PMULL: c_ulong = 1 << 1 + OFFSET;
             const HWCAP_SHA2: c_ulong = 1 << 3 + OFFSET;
@@ -123,15 +170,15 @@ pub(crate) mod arm {
                 features |= PMULL.mask;
             }
             if caps & HWCAP_SHA2 == HWCAP_SHA2 {
-                features |= 1 << 4;
+                features |= SHA256.mask;
             }
 
             unsafe { GFp_armcap_P = features };
         }
     }
 
-    #[cfg(all(target_os = "fuchsia", any(target_arch = "aarch64")))]
-    pub fn fuchsia_setup() {
+    #[cfg(all(target_os = "fuchsia", target_arch = "aarch64"))]
+    pub fn setup() {
         type zx_status_t = i32;
 
         #[link(name = "zircon")]
@@ -168,82 +215,139 @@ pub(crate) mod arm {
         }
     }
 
-    #[cfg(not(target_arch = "wasm32"))]
+    macro_rules! features {
+        {
+            $(
+                $name:ident {
+                    mask: $mask:expr,
+
+                    /// Should we assume that the feature is always available
+                    /// for aarch64-apple-* targets? The first AArch64 iOS
+                    /// device used the Apple A7 chip.
+                    // TODO: When we can use `if` in const expressions:
+                    // ```
+                    // aarch64_apple: $aarch64_apple,
+                    // ```
+                    aarch64_apple: true,
+                }
+            ),+
+            , // trailing comma is required.
+        } => {
+            $(
+                #[allow(dead_code)]
+                pub(crate) const $name: Feature = Feature {
+                    mask: $mask,
+                };
+            )+
+
+            // TODO: When we can use `if` in const expressions, do this:
+            // ```
+            // const ARMCAP_STATIC: u32 = 0
+            //    $(
+            //        | ( if $aarch64_apple &&
+            //               cfg!(all(target_arch = "aarch64",
+            //                        target_vendor = "apple")) {
+            //                $name.mask
+            //            } else {
+            //                0
+            //            }
+            //          )
+            //    )+;
+            // ```
+            //
+            // TODO: Add static feature detection to other targets.
+            // TODO: Combine static feature detection with runtime feature
+            //       detection.
+            #[cfg(all(target_arch = "aarch64", target_vendor = "apple"))]
+            const ARMCAP_STATIC: u32 = 0
+                $(  | $name.mask
+                )+;
+            #[cfg(not(all(target_arch = "aarch64", target_vendor = "apple")))]
+            const ARMCAP_STATIC: u32 = 0;
+
+            #[cfg(all(target_arch = "aarch64", target_vendor = "apple"))]
+            #[test]
+            fn test_armcap_static_available() {
+                let features = crate::cpu::features();
+                $(
+                    assert!($name.available(features));
+                )+
+            }
+        }
+    }
+
+    #[allow(dead_code)]
     pub(crate) struct Feature {
-        #[cfg_attr(
-            any(
-                target_os = "ios",
-                not(any(target_arch = "arm", target_arch = "aarch64"))
-            ),
-            allow(dead_code)
-        )]
         mask: u32,
-
-        #[cfg_attr(not(target_os = "ios"), allow(dead_code))]
-        ios: bool,
     }
 
-    #[cfg(not(target_arch = "wasm32"))]
     impl Feature {
+        #[allow(dead_code)]
         #[inline(always)]
         pub fn available(&self, _: super::Features) -> bool {
-            #[cfg(all(target_os = "ios", any(target_arch = "arm", target_arch = "aarch64")))]
-            {
-                return self.ios;
+            if self.mask == self.mask & ARMCAP_STATIC {
+                return true;
             }
 
             #[cfg(all(
-                any(target_os = "android", target_os = "linux", target_os = "fuchsia"),
+                any(target_os = "android", target_os = "fuchsia", target_os = "linux"),
                 any(target_arch = "arm", target_arch = "aarch64")
             ))]
             {
-                return self.mask == self.mask & unsafe { GFp_armcap_P };
+                if self.mask == self.mask & unsafe { GFp_armcap_P } {
+                    return true;
+                }
             }
 
-            #[cfg(not(any(target_arch = "arm", target_arch = "aarch64")))]
-            {
-                return false;
-            }
+            false
         }
     }
 
-    // Keep in sync with `ARMV7_NEON`.
-    #[cfg(any(target_arch = "aarch64", target_arch = "arm"))]
-    pub(crate) const NEON: Feature = Feature {
-        mask: 1 << 0,
-        ios: true,
-    };
+    features! {
+        // Keep in sync with `ARMV7_NEON`.
+        NEON {
+            mask: 1 << 0,
+            aarch64_apple: true,
+        },
 
-    // Keep in sync with `ARMV8_AES`.
-    #[cfg(any(
-        target_arch = "aarch64",
-        target_arch = "arm",
-        target_arch = "x86",
-        target_arch = "x86_64"
-    ))]
-    pub(crate) const AES: Feature = Feature {
-        mask: 1 << 2,
-        ios: true,
-    };
+        // Keep in sync with `ARMV8_AES`.
+        AES {
+            mask: 1 << 2,
+            aarch64_apple: true,
+        },
 
-    // Keep in sync with `ARMV8_PMULL`.
-    #[cfg(any(
-        target_arch = "aarch64",
-        target_arch = "arm",
-        target_arch = "x86",
-        target_arch = "x86_64"
-    ))]
-    pub(crate) const PMULL: Feature = Feature {
-        mask: 1 << 5,
-        ios: true,
-    };
+        // Keep in sync with `ARMV8_SHA256`.
+        SHA256 {
+            mask: 1 << 4,
+            aarch64_apple: true,
+        },
 
+        // Keep in sync with `ARMV8_PMULL`.
+        PMULL {
+            mask: 1 << 5,
+            aarch64_apple: true,
+        },
+    }
+
+    // Some non-Rust code still checks this even when it is statically known
+    // the given feature is available, so we have to ensure that this is
+    // initialized properly. Keep this in sync with the initialization in
+    // BoringSSL's crypto.c.
+    //
+    // TODO: This should have "hidden" visibility but we don't have a way of
+    // controlling that yet: https://github.com/rust-lang/rust/issues/73958.
+    #[cfg(any(target_arch = "arm", target_arch = "aarch64"))]
+    #[no_mangle]
+    static mut GFp_armcap_P: u32 = ARMCAP_STATIC;
+
     #[cfg(all(
-        any(target_os = "android", target_os = "linux", target_os = "fuchsia"),
-        any(target_arch = "arm", target_arch = "aarch64")
+        any(target_arch = "arm", target_arch = "aarch64"),
+        target_vendor = "apple"
     ))]
-    extern "C" {
-        static mut GFp_armcap_P: u32;
+    #[test]
+    fn test_armcap_static_matches_armcap_dynamic() {
+        assert_eq!(ARMCAP_STATIC, 1 | 4 | 16 | 32);
+        assert_eq!(ARMCAP_STATIC, unsafe { GFp_armcap_P });
     }
 }
 
@@ -258,6 +362,7 @@ pub(crate) mod intel {
     }
 
     impl Feature {
+        #[allow(clippy::needless_return)]
         #[inline(always)]
         pub fn available(&self, _: super::Features) -> bool {
             #[cfg(any(target_arch = "x86", target_arch = "x86_64"))]
