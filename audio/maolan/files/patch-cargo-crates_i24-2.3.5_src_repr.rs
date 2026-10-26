--- cargo-crates/i24-2.3.5/src/repr.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/i24-2.3.5/src/repr.rs
@@ -209,7 +209,7 @@ impl I24Repr {
     }
 
     #[inline]
-    const fn to_le_repr(self) -> Self {
+    const fn to_le_repr(self) -> LittleEndianI24Repr {
         #[cfg(target_endian = "little")]
         {
             self
@@ -225,7 +225,7 @@ impl I24Repr {
             // so after swapping the bytes it turns into
             // [data1, data2, data3, zero]
             // which is the proper layout for `LittleEndianI24Repr`
-            unsafe { std::mem::transmute::<u32, LittleEndianI24Repr>(val) }.data
+            unsafe { core::mem::transmute::<u32, LittleEndianI24Repr>(val) }
         }
     }
 
@@ -636,7 +636,7 @@ impl U24Repr {
     }
 
     #[inline]
-    const fn to_le_repr(self) -> Self {
+    const fn to_le_repr(self) -> LittleEndianU24Repr {
         #[cfg(target_endian = "little")]
         {
             self
