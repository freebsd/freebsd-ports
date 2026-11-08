--- cargo-crates/sdl3-0.14.36/src/sdl3/audio.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/sdl3-0.14.36/src/sdl3/audio.rs
@@ -382,17 +382,17 @@ impl AudioFormat {
     /// Signed 16-bit samples, native endian
     #[inline]
     pub const fn s16_sys() -> AudioFormat {
-        AudioFormat::S16MSB
+        AudioFormat::S16BE
     }
     /// Signed 32-bit samples, native endian
     #[inline]
     pub const fn s32_sys() -> AudioFormat {
-        AudioFormat::S32MSB
+        AudioFormat::S32BE
     }
     /// 32-bit floating point samples, native endian
     #[inline]
     pub const fn f32_sys() -> AudioFormat {
-        AudioFormat::F32MSB
+        AudioFormat::F32BE
     }
 }
 
