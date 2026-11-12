--- cargo-crates/hi_sparse_bitset-0.10.0/src/direct_bitset.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/hi_sparse_bitset-0.10.0/src/direct_bitset.rs
@@ -267,29 +267,11 @@ impl<Conf: Config, Data: DirectDataSource, const ALIGN
 
         #[cfg(target_endian = "big")]
         {
-            let mut bytes: MaybeUninit<Mask::BytesArray> = MaybeUninit::uninit();
-            if ALIGNED{
-                // cast to mask
-                copy_nonoverlapping(
-                    ptr,
-                    bytes.as_mut_ptr().cast(),
-                    size_of::<Mask>()
-                );
-            } else {
-                // cast to bytes
-                copy_nonoverlapping(
-                    ptr.cast::<u8>(),
-                    bytes.as_mut_ptr().cast::<u8>(),
-                    size_of::<Mask>()
-                );
-            }
-            Mask::from_le_bytes(bytes.assume_init())
+            let bytes = ptr.cast::<Mask::BytesArray>().read_unaligned();
+            Mask::from_le_bytes(bytes)
         }
     }
 
-    // TODO: For big endian, we need to take into account swapped sub-masks
-    //       inside mask to correct index.
-    #[cfg(target_endian = "little")]
     #[inline(always)]
     unsafe fn lvl_get_item<LvlMask:BitBlock>(
         offsets: *const impl Primitive,
