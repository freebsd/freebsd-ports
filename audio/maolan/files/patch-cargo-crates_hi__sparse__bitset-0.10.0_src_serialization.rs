--- cargo-crates/hi_sparse_bitset-0.10.0/src/serialization.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/hi_sparse_bitset-0.10.0/src/serialization.rs
@@ -160,7 +160,12 @@ impl<W: Write> Writer<W>{
         }
 
         #[cfg(target_endian = "big")]
-        unimplemented!("TODO: convert to chunks and write_all that chunks");
+        {
+            for &primitive in buf {
+                self.write_primitive(primitive)?;
+            }
+            Ok(())
+        }
     }
 
     #[inline]
@@ -180,7 +185,12 @@ impl<W: Write> Writer<W>{
         }
 
         #[cfg(target_endian = "big")]
-        unimplemented!("TODO: convert to chunks and write_all that chunks");
+        {
+            for mask in buf {
+                self.write_buf(mask.to_le_bytes().as_ref())?;
+            }
+            Ok(())
+        }
     }
 
     #[inline]
@@ -345,7 +355,13 @@ impl<R: Read> Reader<R>{
         }
 
         #[cfg(target_endian = "big")]
-        unimplemented!();
+        {
+            self.read_buf_le(primitives)?;
+            for primitive in primitives.iter_mut() {
+                *primitive = primitive.swap_bytes();
+            }
+            Ok(())
+        }
     }
 
     #[inline]
@@ -410,6 +426,7 @@ impl<R: Read> Reader<R>{
     pub fn foreach_read_mask<T, F>(&mut self, len: usize, mut f: F)
         -> std::io::Result<()>
     where
+        T: BitBlock,
         F: FnMut(&T)
     {
         self.foreach_read_item(len, |item: &T|{
@@ -417,7 +434,7 @@ impl<R: Read> Reader<R>{
             f(item);
 
             #[cfg(target_endian = "big")]
-            unimplemented!();
+            f(&T::from_le_bytes(item.to_ne_bytes()));
         })
     }
 
@@ -437,7 +454,13 @@ impl<R: Read> Reader<R>{
         }
 
         #[cfg(target_endian = "big")]
-        unimplemented!();
+        {
+            self.read_buf_le(masks)?;
+            for mask in masks.iter_mut() {
+                *mask = T::from_le_bytes(mask.to_ne_bytes());
+            }
+            Ok(())
+        }
     }
 
     #[inline]
