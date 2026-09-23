-- Build on architectures without SIMD kernels (e.g. powerpc64le).
-- https://github.com/lance-format/lance/pull/9446

--- ../rust/lance-linalg/src/simd/f64.rs.orig	2026-08-30 19:56:29 UTC
+++ ../rust/lance-linalg/src/simd/f64.rs
@@ -33,6 +33,11 @@ pub struct f64x4(v4f64);
 #[derive(Clone, Copy)]
 pub struct f64x4(v4f64);
 
+#[allow(non_camel_case_types)]
+#[cfg(simd_fallback)]
+#[derive(Clone, Copy)]
+pub struct f64x4([f64; 4]);
+
 impl std::fmt::Debug for f64x4 {
     fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
         let mut arr = [0.0_f64; 4];
@@ -74,6 +79,10 @@ impl SIMD<f64, 4> for f64x4 {
         unsafe {
             Self(transmute(lasx_xvreplgr2vr_d(transmute(val))))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self([val; 4])
+        }
     }
 
     fn zeros() -> Self {
@@ -89,6 +98,10 @@ impl SIMD<f64, 4> for f64x4 {
         {
             Self::splat(0.0)
         }
+        #[cfg(simd_fallback)]
+        {
+            Self::splat(0.0)
+        }
     }
 
     #[inline]
@@ -105,6 +118,10 @@ impl SIMD<f64, 4> for f64x4 {
         {
             Self(transmute(lasx_xvld::<0>(transmute(ptr))))
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { Self::load_unaligned(ptr) }
+        }
     }
 
     #[inline]
@@ -121,6 +138,10 @@ impl SIMD<f64, 4> for f64x4 {
         {
             Self(transmute(lasx_xvld::<0>(transmute(ptr))))
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { Self(std::ptr::read_unaligned(ptr as *const [f64; 4])) }
+        }
     }
 
     unsafe fn store(&self, ptr: *mut f64) {
@@ -136,6 +157,10 @@ impl SIMD<f64, 4> for f64x4 {
         unsafe {
             lasx_xvst::<0>(transmute(self.0), transmute(ptr));
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { self.store_unaligned(ptr) }
+        }
     }
 
     unsafe fn store_unaligned(&self, ptr: *mut f64) {
@@ -151,6 +176,10 @@ impl SIMD<f64, 4> for f64x4 {
         unsafe {
             lasx_xvst::<0>(transmute(self.0), transmute(ptr));
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { std::ptr::write_unaligned(ptr as *mut [f64; 4], self.0) }
+        }
     }
 
     #[inline]
@@ -174,6 +203,10 @@ impl SIMD<f64, 4> for f64x4 {
         {
             self.as_array().iter().sum()
         }
+        #[cfg(simd_fallback)]
+        {
+            self.0.iter().sum()
+        }
     }
 
     fn reduce_min(&self) -> f64 {
@@ -199,6 +232,10 @@ impl SIMD<f64, 4> for f64x4 {
                 .copied()
                 .fold(f64::INFINITY, f64::min)
         }
+        #[cfg(simd_fallback)]
+        {
+            self.0.iter().copied().fold(f64::INFINITY, f64::min)
+        }
     }
 
     fn min(&self, rhs: &Self) -> Self {
@@ -217,6 +254,10 @@ impl SIMD<f64, 4> for f64x4 {
         unsafe {
             Self(lasx_xvfmin_d(self.0, rhs.0))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i].min(rhs.0[i])))
+        }
     }
 
     fn find(&self, val: f64) -> Option<i32> {
@@ -246,6 +287,12 @@ impl FloatSimd<f64, 4> for f64x4 {
         unsafe {
             self.0 = lasx_xvfmadd_d(a.0, b.0, self.0);
         }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..4 {
+                self.0[i] = a.0[i].mul_add(b.0[i], self.0[i]);
+            }
+        }
     }
 }
 
@@ -269,6 +316,10 @@ impl Add for f64x4 {
         unsafe {
             Self(lasx_xvfadd_d(self.0, rhs.0))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i] + rhs.0[i]))
+        }
     }
 }
 
@@ -288,6 +339,12 @@ impl AddAssign for f64x4 {
         unsafe {
             self.0 = lasx_xvfadd_d(self.0, rhs.0);
         }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..4 {
+                self.0[i] += rhs.0[i];
+            }
+        }
     }
 }
 
@@ -311,6 +368,10 @@ impl Sub for f64x4 {
         unsafe {
             Self(lasx_xvfsub_d(self.0, rhs.0))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i] - rhs.0[i]))
+        }
     }
 }
 
@@ -330,6 +391,12 @@ impl SubAssign for f64x4 {
         unsafe {
             self.0 = lasx_xvfsub_d(self.0, rhs.0);
         }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..4 {
+                self.0[i] -= rhs.0[i];
+            }
+        }
     }
 }
 
@@ -352,6 +419,10 @@ impl Mul for f64x4 {
         #[cfg(target_arch = "loongarch64")]
         unsafe {
             Self(lasx_xvfmul_d(self.0, rhs.0))
+        }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i] * rhs.0[i]))
         }
     }
 }
@@ -382,6 +453,11 @@ pub struct f64x8(v4f64, v4f64);
 #[derive(Clone, Copy)]
 pub struct f64x8(v4f64, v4f64);
 
+#[allow(non_camel_case_types)]
+#[cfg(simd_fallback)]
+#[derive(Clone, Copy)]
+pub struct f64x8([f64; 8]);
+
 impl std::fmt::Debug for f64x8 {
     fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
         let mut arr = [0.0_f64; 8];
@@ -426,6 +502,10 @@ impl SIMD<f64, 8> for f64x8 {
             let v = transmute(lasx_xvreplgr2vr_d(transmute(val)));
             Self(v, v)
         }
+        #[cfg(simd_fallback)]
+        {
+            Self([val; 8])
+        }
     }
 
     #[inline]
@@ -442,6 +522,10 @@ impl SIMD<f64, 8> for f64x8 {
         {
             Self::splat(0.0)
         }
+        #[cfg(simd_fallback)]
+        {
+            Self::splat(0.0)
+        }
     }
 
     #[inline]
@@ -461,6 +545,10 @@ impl SIMD<f64, 8> for f64x8 {
                 transmute(lasx_xvld::<32>(transmute(ptr))),
             )
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { Self::load_unaligned(ptr) }
+        }
     }
 
     #[inline]
@@ -480,6 +568,10 @@ impl SIMD<f64, 8> for f64x8 {
                 transmute(lasx_xvld::<32>(transmute(ptr))),
             )
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { Self(std::ptr::read_unaligned(ptr as *const [f64; 8])) }
+        }
     }
 
     #[inline]
@@ -499,6 +591,10 @@ impl SIMD<f64, 8> for f64x8 {
             lasx_xvst::<0>(transmute(self.0), transmute(ptr));
             lasx_xvst::<32>(transmute(self.1), transmute(ptr));
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { self.store_unaligned(ptr) }
+        }
     }
 
     #[inline]
@@ -518,6 +614,10 @@ impl SIMD<f64, 8> for f64x8 {
             lasx_xvst::<0>(transmute(self.0), transmute(ptr));
             lasx_xvst::<32>(transmute(self.1), transmute(ptr));
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { std::ptr::write_unaligned(ptr as *mut [f64; 8], self.0) }
+        }
     }
 
     #[inline]
@@ -541,6 +641,10 @@ impl SIMD<f64, 8> for f64x8 {
         {
             self.as_array().iter().sum()
         }
+        #[cfg(simd_fallback)]
+        {
+            self.0.iter().sum()
+        }
     }
 
     #[inline]
@@ -568,6 +672,10 @@ impl SIMD<f64, 8> for f64x8 {
                 .copied()
                 .fold(f64::INFINITY, f64::min)
         }
+        #[cfg(simd_fallback)]
+        {
+            self.0.iter().copied().fold(f64::INFINITY, f64::min)
+        }
     }
 
     #[inline]
@@ -587,6 +695,10 @@ impl SIMD<f64, 8> for f64x8 {
         unsafe {
             Self(lasx_xvfmin_d(self.0, rhs.0), lasx_xvfmin_d(self.1, rhs.1))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i].min(rhs.0[i])))
+        }
     }
 
     #[inline]
@@ -622,6 +734,12 @@ impl FloatSimd<f64, 8> for f64x8 {
             self.0 = lasx_xvfmadd_d(a.0, b.0, self.0);
             self.1 = lasx_xvfmadd_d(a.1, b.1, self.1);
         }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..8 {
+                self.0[i] = a.0[i].mul_add(b.0[i], self.0[i]);
+            }
+        }
     }
 }
 
@@ -645,6 +763,10 @@ impl Add for f64x8 {
         unsafe {
             Self(lasx_xvfadd_d(self.0, rhs.0), lasx_xvfadd_d(self.1, rhs.1))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i] + rhs.0[i]))
+        }
     }
 }
 
@@ -668,6 +790,12 @@ impl AddAssign for f64x8 {
             self.0 = lasx_xvfadd_d(self.0, rhs.0);
             self.1 = lasx_xvfadd_d(self.1, rhs.1);
         }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..8 {
+                self.0[i] += rhs.0[i];
+            }
+        }
     }
 }
 
@@ -691,6 +819,10 @@ impl Mul for f64x8 {
         unsafe {
             Self(lasx_xvfmul_d(self.0, rhs.0), lasx_xvfmul_d(self.1, rhs.1))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i] * rhs.0[i]))
+        }
     }
 }
 
@@ -714,6 +846,10 @@ impl Sub for f64x8 {
         unsafe {
             Self(lasx_xvfsub_d(self.0, rhs.0), lasx_xvfsub_d(self.1, rhs.1))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i] - rhs.0[i]))
+        }
     }
 }
 
@@ -737,6 +873,12 @@ impl SubAssign for f64x8 {
             self.0 = lasx_xvfsub_d(self.0, rhs.0);
             self.1 = lasx_xvfsub_d(self.1, rhs.1);
         }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..8 {
+                self.0[i] -= rhs.0[i];
+            }
+        }
     }
 }
 
