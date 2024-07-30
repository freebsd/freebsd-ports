--- cargo-crates/serde_bser-0.4.0/src/ser/mod.rs.orig	2024-07-30 20:40:15 UTC
+++ cargo-crates/serde_bser-0.4.0/src/ser/mod.rs
@@ -133,7 +133,7 @@ where
         #[cfg(target_endian = "little")]
         self.scratch.put_i16_le(v);
         #[cfg(target_endian = "big")]
-        self.scratch.put_i16_be(v);
+        self.scratch.put_i16(v);
     }
 
     #[inline]
@@ -143,7 +143,7 @@ where
         #[cfg(target_endian = "little")]
         self.scratch.put_i32_le(v);
         #[cfg(target_endian = "big")]
-        self.scratch.put_i32_be(v);
+        self.scratch.put_i32(v);
     }
 
     #[inline]
@@ -153,7 +153,7 @@ where
         #[cfg(target_endian = "little")]
         self.scratch.put_i64_le(v);
         #[cfg(target_endian = "big")]
-        self.scratch.put_i64_be(v);
+        self.scratch.put_i64(v);
     }
 }
 
@@ -255,7 +255,7 @@ where
         #[cfg(target_endian = "little")]
         self.scratch.put_f64_le(v);
         #[cfg(target_endian = "big")]
-        self.scratch.put_f64_be(v);
+        self.scratch.put_f64(v);
         Ok(())
     }
 
