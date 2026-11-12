--- cargo-crates/hi_sparse_bitset-0.9.0/src/bit_block.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/hi_sparse_bitset-0.9.0/src/bit_block.rs
@@ -116,7 +116,7 @@ pub trait BitBlock
 
     #[inline]
     fn to_le(self) -> Self {
-        Self::from_le_bytes(self.to_le_bytes())
+        Self::from_ne_bytes(self.to_le_bytes())
     }
 
     #[inline]
@@ -240,7 +240,7 @@ impl BitBlock for wide::u64x2{
         #[cfg(target_endian = "little")]
         { self.to_ne_bytes() }
         #[cfg(target_endian = "big")]
-        { unimplemented!() }
+        { unsafe{ mem::transmute(self.to_array().map(u64::to_le)) } }
     }
 
     #[inline]
@@ -253,7 +253,7 @@ impl BitBlock for wide::u64x2{
         #[cfg(target_endian = "little")]
         { Self::from_ne_bytes(bytes) }
         #[cfg(target_endian = "big")]
-        { unimplemented!() }
+        { Self::new(unsafe{ mem::transmute::<_, [u64; 2]>(bytes) }.map(u64::from_le)) }
     }
 }
 
@@ -294,7 +294,7 @@ impl BitBlock for wide::u64x4{
         #[cfg(target_endian = "little")]
         { self.to_ne_bytes() }
         #[cfg(target_endian = "big")]
-        { unimplemented!() }
+        { unsafe{ mem::transmute(self.to_array().map(u64::to_le)) } }
     }
 
     #[inline]
@@ -307,7 +307,7 @@ impl BitBlock for wide::u64x4{
         #[cfg(target_endian = "little")]
         { Self::from_ne_bytes(bytes) }
         #[cfg(target_endian = "big")]
-        { unimplemented!() }
+        { Self::new(unsafe{ mem::transmute::<_, [u64; 4]>(bytes) }.map(u64::from_le)) }
     }
 }
 
@@ -350,7 +350,7 @@ impl BitBlock for wide::u64x8{
         #[cfg(target_endian = "little")]
         { self.to_ne_bytes() }
         #[cfg(target_endian = "big")]
-        { unimplemented!() }
+        { unsafe{ mem::transmute(self.to_array().map(u64::to_le)) } }
     }
 
     #[inline]
@@ -363,6 +363,6 @@ impl BitBlock for wide::u64x8{
         #[cfg(target_endian = "little")]
         { Self::from_ne_bytes(bytes) }
         #[cfg(target_endian = "big")]
-        { unimplemented!() }
+        { Self::new(unsafe{ mem::transmute::<_, [u64; 8]>(bytes) }.map(u64::from_le)) }
     }
 }
