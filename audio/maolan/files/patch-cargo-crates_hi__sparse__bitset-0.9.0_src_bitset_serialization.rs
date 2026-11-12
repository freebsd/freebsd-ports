--- cargo-crates/hi_sparse_bitset-0.9.0/src/bitset/serialization.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/hi_sparse_bitset-0.9.0/src/bitset/serialization.rs
@@ -1,6 +1,7 @@ use std::ops::{ControlFlow, Sub};
 use std::io::{Read, Write};
 use std::mem::MaybeUninit;
 use std::ops::{ControlFlow, Sub};
+#[cfg(target_endian = "little")]
 use std::slice;
 use crate::{BitBlock, BitSet, make_lvl0_u64_index_starts};
 use crate::bitset::{Level0Block, Level1Block, LevelDataBlock};
@@ -191,15 +192,10 @@ impl<Conf: Config> BitSet<Conf> {
             }
 
             #[cfg(target_endian = "big")]
-            chunked_read(r, data_blocks_len, |masks: &[Conf::DataBitBlock]| {
-                 for &mask in masks {
-                     let block: LevelDataBlock<Conf> = unsafe{Block::from_parts(
-                         mask, []
-                     )};
-
-                    unsafe{ blocks.spare_capacity_mut().get_unchecked_mut(blocks_len).write(block); }
-                    blocks_len +=1;
-                 }
+            r.foreach_read_mask(data_len, |&mask: &Conf::DataBitBlock| {
+                let block: LevelDataBlock<Conf> = unsafe{Block::from_parts(mask, [])};
+                unsafe{ blocks.spare_capacity_mut().get_unchecked_mut(blocks_len).write(block); }
+                blocks_len +=1;
             })?;
             unsafe{ blocks.set_len(blocks_len); }
 
