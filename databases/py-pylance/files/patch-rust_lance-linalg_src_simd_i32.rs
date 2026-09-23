-- Build on architectures without SIMD kernels (e.g. powerpc64le).
-- https://github.com/lance-format/lance/pull/9446

--- ../rust/lance-linalg/src/simd/i32.rs.orig	2026-08-30 19:56:29 UTC
+++ ../rust/lance-linalg/src/simd/i32.rs
@@ -38,6 +38,11 @@ pub struct i32x8(v8i32);
 #[derive(Clone, Copy)]
 pub struct i32x8(v8i32);
 
+#[allow(non_camel_case_types)]
+#[cfg(simd_fallback)]
+#[derive(Clone, Copy)]
+pub struct i32x8([i32; 8]);
+
 impl std::fmt::Debug for i32x8 {
     fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
         let mut arr = [0; 8];
@@ -80,6 +85,10 @@ impl SIMD<i32, 8> for i32x8 {
         unsafe {
             Self(lasx_xvreplgr2vr_w(val))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self([val; 8])
+        }
     }
 
     #[inline]
@@ -96,6 +105,10 @@ impl SIMD<i32, 8> for i32x8 {
         {
             Self::splat(0)
         }
+        #[cfg(simd_fallback)]
+        {
+            Self::splat(0)
+        }
     }
 
     #[inline]
@@ -112,6 +125,10 @@ impl SIMD<i32, 8> for i32x8 {
         {
             Self(transmute(lasx_xvld::<0>(transmute(ptr))))
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { Self::load_unaligned(ptr) }
+        }
     }
 
     #[inline]
@@ -128,6 +145,10 @@ impl SIMD<i32, 8> for i32x8 {
         {
             Self(transmute(lasx_xvld::<0>(transmute(ptr))))
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { Self(std::ptr::read_unaligned(ptr as *const [i32; 8])) }
+        }
     }
 
     #[inline]
@@ -148,6 +169,10 @@ impl SIMD<i32, 8> for i32x8 {
         unsafe {
             lasx_xvst::<0>(transmute(self.0), transmute(ptr))
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { std::ptr::write_unaligned(ptr as *mut [i32; 8], self.0) }
+        }
     }
 
     fn reduce_sum(&self) -> i32 {
@@ -164,6 +189,10 @@ impl SIMD<i32, 8> for i32x8 {
         {
             self.as_array().iter().sum()
         }
+        #[cfg(simd_fallback)]
+        {
+            self.0.iter().sum()
+        }
     }
 
     fn reduce_min(&self) -> i32 {
@@ -186,6 +215,10 @@ impl SIMD<i32, 8> for i32x8 {
         unsafe {
             Self(lasx_xvmin_w(self.0, rhs.0))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i].min(rhs.0[i])))
+        }
     }
 
     fn find(&self, val: i32) -> Option<i32> {
@@ -219,6 +252,12 @@ impl SIMD<i32, 8> for i32x8 {
                 }
             }
         }
+        #[cfg(simd_fallback)]
+        {
+            if let Some(i) = self.0.iter().position(|&v| v == val) {
+                return Some(i as i32);
+            }
+        }
         None
     }
 }
@@ -243,6 +282,10 @@ impl Add for i32x8 {
         unsafe {
             Self(lasx_xvadd_w(self.0, rhs.0))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i].wrapping_add(rhs.0[i])))
+        }
     }
 }
 
@@ -262,6 +305,12 @@ impl AddAssign for i32x8 {
         unsafe {
             self.0 = lasx_xvadd_w(self.0, rhs.0);
         }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..8 {
+                self.0[i] = self.0[i].wrapping_add(rhs.0[i]);
+            }
+        }
     }
 }
 
@@ -285,6 +334,10 @@ impl Sub for i32x8 {
         unsafe {
             Self(lasx_xvsub_w(self.0, rhs.0))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i].wrapping_sub(rhs.0[i])))
+        }
     }
 }
 
@@ -304,6 +357,12 @@ impl SubAssign for i32x8 {
         unsafe {
             self.0 = lasx_xvsub_w(self.0, rhs.0);
         }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..8 {
+                self.0[i] = self.0[i].wrapping_sub(rhs.0[i]);
+            }
+        }
     }
 }
 
@@ -313,11 +372,11 @@ impl Mul for i32x8 {
     /// Lane-wise product, keeping the low 32 bits of each result.
     ///
     /// `mul` wraps on overflow rather than panicking the way scalar `i32 * i32`
-    /// does in a debug build, and all three arms agree on that: `vpmulld`,
-    /// `vmulq_s32` and `lasx_xvmul_w` each discard the high half. This is a
-    /// statement about `mul` alone — `reduce_sum` sums in scalar `i32` on x86_64
-    /// and loongarch64 (so it panics on overflow in a debug build) but reduces
-    /// in-register on aarch64, where it wraps.
+    /// does in a debug build, and every arm agrees on that: `vpmulld`,
+    /// `vmulq_s32`, `lasx_xvmul_w` and `wrapping_mul` each discard the high
+    /// half. This is a statement about `mul` alone — `reduce_sum` sums in scalar
+    /// `i32` outside aarch64 (so it panics on overflow in a debug build) but
+    /// reduces in-register on aarch64, where it wraps.
     ///
     /// Picking a widening variant here is a silent wrong answer, not a compile
     /// error: `_mm256_mul_epi32` (`vpmuldq`) multiplies only the even 32-bit
@@ -340,6 +399,10 @@ impl Mul for i32x8 {
         unsafe {
             Self(lasx_xvmul_w(self.0, rhs.0))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i].wrapping_mul(rhs.0[i])))
+        }
     }
 }
 
@@ -353,7 +416,7 @@ mod tests {
         assert!(std::panic::catch_unwind(|| i32x8::from(&[0; 7][..])).is_err());
     }
 
-    /// Lane-wise, low-32-bits multiplication is what all three arms promise, so
+    /// Lane-wise, low-32-bits multiplication is what every arm promises, so
     /// this runs everywhere: only the x86 feature check is arch-gated, matching
     /// `f32.rs`'s and `f64.rs`'s test modules.
     ///
