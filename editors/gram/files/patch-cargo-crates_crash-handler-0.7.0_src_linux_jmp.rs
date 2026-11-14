--- cargo-crates/crash-handler-0.7.0/src/linux/jmp.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/crash-handler-0.7.0/src/linux/jmp.rs
@@ -55,6 +55,11 @@ cfg_if::cfg_if! {
             __gregs: [u64; 10],
             __fpregs: [f64; 8],
         }
+    } else if #[cfg(target_arch = "powerpc64")] {
+        #[repr(C)]
+        #[doc(hidden)]
+        #[allow(non_camel_case_types)]
+        pub struct __jmp_buf([u64; 101]);
     }
 }
 
