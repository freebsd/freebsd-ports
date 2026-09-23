-- Build on architectures without SIMD kernels (e.g. powerpc64le).
-- https://github.com/lance-format/lance/pull/9446

--- ../rust/lance-linalg/src/simd/f32.rs.orig	2026-08-30 19:56:29 UTC
+++ ../rust/lance-linalg/src/simd/f32.rs
@@ -35,6 +35,11 @@ pub struct f32x8(v8f32);
 #[derive(Clone, Copy)]
 pub struct f32x8(v8f32);
 
+#[allow(non_camel_case_types)]
+#[cfg(simd_fallback)]
+#[derive(Clone, Copy)]
+pub struct f32x8([f32; 8]);
+
 impl std::fmt::Debug for f32x8 {
     fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
         let mut arr = [0.0_f32; 8];
@@ -119,6 +124,10 @@ impl f32x8 {
             ];
             Self::load_unaligned(values.as_ptr())
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(indices.map(|i| slice[i as usize]))
+        }
     }
 }
 
@@ -177,6 +186,10 @@ impl SIMD<f32, 8> for f32x8 {
         unsafe {
             Self(transmute(lasx_xvreplgr2vr_w(transmute(val))))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self([val; 8])
+        }
     }
 
     fn zeros() -> Self {
@@ -192,6 +205,10 @@ impl SIMD<f32, 8> for f32x8 {
         {
             Self::splat(0.0)
         }
+        #[cfg(simd_fallback)]
+        {
+            Self::splat(0.0)
+        }
     }
 
     #[inline]
@@ -208,6 +225,10 @@ impl SIMD<f32, 8> for f32x8 {
         {
             Self(transmute(lasx_xvld::<0>(transmute(ptr))))
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { Self::load_unaligned(ptr) }
+        }
     }
 
     #[inline]
@@ -224,6 +245,10 @@ impl SIMD<f32, 8> for f32x8 {
         {
             Self(transmute(lasx_xvld::<0>(transmute(ptr))))
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { Self(std::ptr::read_unaligned(ptr as *const [f32; 8])) }
+        }
     }
 
     unsafe fn store(&self, ptr: *mut f32) {
@@ -239,6 +264,10 @@ impl SIMD<f32, 8> for f32x8 {
         unsafe {
             lasx_xvst::<0>(transmute(self.0), transmute(ptr));
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { self.store_unaligned(ptr) }
+        }
     }
 
     unsafe fn store_unaligned(&self, ptr: *mut f32) {
@@ -254,6 +283,10 @@ impl SIMD<f32, 8> for f32x8 {
         unsafe {
             lasx_xvst::<0>(transmute(self.0), transmute(ptr));
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { std::ptr::write_unaligned(ptr as *mut [f32; 8], self.0) }
+        }
     }
 
     #[inline]
@@ -282,6 +315,10 @@ impl SIMD<f32, 8> for f32x8 {
         {
             self.as_array().iter().sum()
         }
+        #[cfg(simd_fallback)]
+        {
+            self.0.iter().sum()
+        }
     }
 
     fn reduce_min(&self) -> f32 {
@@ -315,6 +352,10 @@ impl SIMD<f32, 8> for f32x8 {
             let m1 = lasx_xvpermi_w::<1>(transmute(m2), transmute(m2));
             let m2 = lasx_xvfmin_s(transmute(m1), transmute(m2));
             transmute(lasx_xvpickve2gr_w::<0>(transmute(m2)))
+        }
+        #[cfg(simd_fallback)]
+        {
+            self.0.iter().copied().fold(f32::INFINITY, f32::min)
         }
     }
 
@@ -334,6 +375,10 @@ impl SIMD<f32, 8> for f32x8 {
         unsafe {
             Self(lasx_xvfmin_s(self.0, rhs.0))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i].min(rhs.0[i])))
+        }
     }
 
     fn find(&self, val: f32) -> Option<i32> {
@@ -367,6 +412,12 @@ impl SIMD<f32, 8> for f32x8 {
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
@@ -386,6 +437,12 @@ impl FloatSimd<f32, 8> for f32x8 {
         unsafe {
             self.0 = lasx_xvfmadd_s(a.0, b.0, self.0);
         }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..8 {
+                self.0[i] = a.0[i].mul_add(b.0[i], self.0[i]);
+            }
+        }
     }
 }
 
@@ -409,6 +466,10 @@ impl Add for f32x8 {
         unsafe {
             Self(lasx_xvfadd_s(self.0, rhs.0))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i] + rhs.0[i]))
+        }
     }
 }
 
@@ -428,6 +489,12 @@ impl AddAssign for f32x8 {
         unsafe {
             self.0 = lasx_xvfadd_s(self.0, rhs.0);
         }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..8 {
+                self.0[i] += rhs.0[i];
+            }
+        }
     }
 }
 
@@ -451,6 +518,10 @@ impl Sub for f32x8 {
         unsafe {
             Self(lasx_xvfsub_s(self.0, rhs.0))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i] - rhs.0[i]))
+        }
     }
 }
 
@@ -470,6 +541,12 @@ impl SubAssign for f32x8 {
         unsafe {
             self.0 = lasx_xvfsub_s(self.0, rhs.0);
         }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..8 {
+                self.0[i] -= rhs.0[i];
+            }
+        }
     }
 }
 
@@ -492,6 +569,10 @@ impl Mul for f32x8 {
         #[cfg(target_arch = "loongarch64")]
         unsafe {
             Self(lasx_xvfmul_s(self.0, rhs.0))
+        }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i] * rhs.0[i]))
         }
     }
 }
@@ -521,6 +602,11 @@ pub struct f32x16(v8f32, v8f32);
 #[derive(Clone, Copy)]
 pub struct f32x16(v8f32, v8f32);
 
+#[allow(non_camel_case_types)]
+#[cfg(simd_fallback)]
+#[derive(Clone, Copy)]
+pub struct f32x16([f32; 16]);
+
 impl std::fmt::Debug for f32x16 {
     fn fmt(&self, f: &mut Formatter<'_>) -> std::fmt::Result {
         let mut arr = [0.0_f32; 16];
@@ -571,6 +657,10 @@ impl SIMD<f32, 16> for f32x16 {
                 transmute(lasx_xvreplgr2vr_w(transmute(val))),
             )
         }
+        #[cfg(simd_fallback)]
+        {
+            Self([val; 16])
+        }
     }
 
     #[inline]
@@ -587,6 +677,10 @@ impl SIMD<f32, 16> for f32x16 {
         {
             Self::splat(0.0)
         }
+        #[cfg(simd_fallback)]
+        {
+            Self::splat(0.0)
+        }
     }
 
     #[inline]
@@ -606,6 +700,10 @@ impl SIMD<f32, 16> for f32x16 {
                 transmute(lasx_xvld::<32>(transmute(ptr))),
             )
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { Self::load_unaligned(ptr) }
+        }
     }
 
     #[inline]
@@ -625,6 +723,10 @@ impl SIMD<f32, 16> for f32x16 {
                 transmute(lasx_xvld::<32>(transmute(ptr))),
             )
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { Self(std::ptr::read_unaligned(ptr as *const [f32; 16])) }
+        }
     }
 
     #[inline]
@@ -643,6 +745,10 @@ impl SIMD<f32, 16> for f32x16 {
             lasx_xvst::<0>(transmute(self.0), transmute(ptr));
             lasx_xvst::<32>(transmute(self.1), transmute(ptr));
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { self.store_unaligned(ptr) }
+        }
     }
 
     #[inline]
@@ -661,6 +767,10 @@ impl SIMD<f32, 16> for f32x16 {
             lasx_xvst::<0>(transmute(self.0), transmute(ptr));
             lasx_xvst::<32>(transmute(self.1), transmute(ptr));
         }
+        #[cfg(simd_fallback)]
+        {
+            unsafe { std::ptr::write_unaligned(ptr as *mut [f32; 16], self.0) }
+        }
     }
 
     #[inline]
@@ -691,6 +801,10 @@ impl SIMD<f32, 16> for f32x16 {
         {
             self.as_array().iter().sum()
         }
+        #[cfg(simd_fallback)]
+        {
+            self.0.iter().sum()
+        }
     }
 
     #[inline]
@@ -725,6 +839,10 @@ impl SIMD<f32, 16> for f32x16 {
             let m1 = lasx_xvfmin_s(transmute(m1), transmute(m2));
             transmute(lasx_xvpickve2gr_w::<0>(transmute(m1)))
         }
+        #[cfg(simd_fallback)]
+        {
+            self.0.iter().copied().fold(f32::INFINITY, f32::min)
+        }
     }
 
     #[inline]
@@ -746,6 +864,10 @@ impl SIMD<f32, 16> for f32x16 {
         unsafe {
             Self(lasx_xvfmin_s(self.0, rhs.0), lasx_xvfmin_s(self.1, rhs.1))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i].min(rhs.0[i])))
+        }
     }
 
     #[inline]
@@ -792,6 +914,10 @@ impl SIMD<f32, 16> for f32x16 {
             }
             None
         }
+        #[cfg(simd_fallback)]
+        {
+            self.0.iter().position(|&v| v == val).map(|i| i as i32)
+        }
     }
 }
 
@@ -815,6 +941,12 @@ impl FloatSimd<f32, 16> for f32x16 {
             self.0 = lasx_xvfmadd_s(a.0, b.0, self.0);
             self.1 = lasx_xvfmadd_s(a.1, b.1, self.1);
         }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..16 {
+                self.0[i] = a.0[i].mul_add(b.0[i], self.0[i]);
+            }
+        }
     }
 }
 
@@ -840,6 +972,10 @@ impl Add for f32x16 {
         unsafe {
             Self(lasx_xvfadd_s(self.0, rhs.0), lasx_xvfadd_s(self.1, rhs.1))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i] + rhs.0[i]))
+        }
     }
 }
 
@@ -862,6 +998,12 @@ impl AddAssign for f32x16 {
         unsafe {
             self.0 = lasx_xvfadd_s(self.0, rhs.0);
             self.1 = lasx_xvfadd_s(self.1, rhs.1);
+        }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..16 {
+                self.0[i] += rhs.0[i];
+            }
         }
     }
 }
@@ -888,6 +1030,10 @@ impl Mul for f32x16 {
         unsafe {
             Self(lasx_xvfmul_s(self.0, rhs.0), lasx_xvfmul_s(self.1, rhs.1))
         }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i] * rhs.0[i]))
+        }
     }
 }
 
@@ -912,6 +1058,10 @@ impl Sub for f32x16 {
         #[cfg(target_arch = "loongarch64")]
         unsafe {
             Self(lasx_xvfsub_s(self.0, rhs.0), lasx_xvfsub_s(self.1, rhs.1))
+        }
+        #[cfg(simd_fallback)]
+        {
+            Self(std::array::from_fn(|i| self.0[i] - rhs.0[i]))
         }
     }
 }
@@ -936,6 +1086,12 @@ impl SubAssign for f32x16 {
             self.0 = lasx_xvfsub_s(self.0, rhs.0);
             self.1 = lasx_xvfsub_s(self.1, rhs.1);
         }
+        #[cfg(simd_fallback)]
+        {
+            for i in 0..16 {
+                self.0[i] -= rhs.0[i];
+            }
+        }
     }
 }
 
