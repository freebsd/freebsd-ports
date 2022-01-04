From e1466728515296b9c8b84a38ab8aa58766c6f9c4 Mon Sep 17 00:00:00 2001
From: Fabio Valentini <decathorpe@gmail.com>
Date: Wed, 4 Aug 2021 13:30:53 +0200
Subject: [PATCH] gstreamer-audio: fix audio_format code for big-endian targets

---
 gstreamer-audio/src/audio_format.rs | 88 ++++++++++++++---------------
 1 file changed, 44 insertions(+), 44 deletions(-)

diff --git a/gstreamer-audio/src/audio_format.rs b/gstreamer-audio/src/audio_format.rs
index 99c891f5b..5212814f4 100644
--- ../gstreamer-rs-f00c57cd6f2a0912e04c10887cedbe95be7d5dea/gstreamer-audio/src/audio_format.rs
+++ ../gstreamer-rs-f00c57cd6f2a0912e04c10887cedbe95be7d5dea/gstreamer-audio/src/audio_format.rs
@@ -59,36 +59,36 @@ pub static AUDIO_FORMATS_ALL: Lazy<Box<[crate::AudioFormat]>> = Lazy::new(|| {
     #[cfg(target_endian = "big")]
     {
         Box::new([
-            ::AudioFormat::F64be,
-            ::AudioFormat::F64le,
-            ::AudioFormat::F32be,
-            ::AudioFormat::F32le,
-            ::AudioFormat::S32be,
-            ::AudioFormat::S32le,
-            ::AudioFormat::U32be,
-            ::AudioFormat::U32le,
-            ::AudioFormat::S2432be,
-            ::AudioFormat::S2432le,
-            ::AudioFormat::U2432be,
-            ::AudioFormat::U2432le,
-            ::AudioFormat::S24be,
-            ::AudioFormat::S24le,
-            ::AudioFormat::U24be,
-            ::AudioFormat::U24le,
-            ::AudioFormat::S20be,
-            ::AudioFormat::S20le,
-            ::AudioFormat::U20be,
-            ::AudioFormat::U20le,
-            ::AudioFormat::S18be,
-            ::AudioFormat::S18le,
-            ::AudioFormat::U18be,
-            ::AudioFormat::U18le,
-            ::AudioFormat::S16be,
-            ::AudioFormat::S16le,
-            ::AudioFormat::U16be,
-            ::AudioFormat::U16le,
-            ::AudioFormat::S8,
-            ::AudioFormat::U8,
+            crate::AudioFormat::F64be,
+            crate::AudioFormat::F64le,
+            crate::AudioFormat::F32be,
+            crate::AudioFormat::F32le,
+            crate::AudioFormat::S32be,
+            crate::AudioFormat::S32le,
+            crate::AudioFormat::U32be,
+            crate::AudioFormat::U32le,
+            crate::AudioFormat::S2432be,
+            crate::AudioFormat::S2432le,
+            crate::AudioFormat::U2432be,
+            crate::AudioFormat::U2432le,
+            crate::AudioFormat::S24be,
+            crate::AudioFormat::S24le,
+            crate::AudioFormat::U24be,
+            crate::AudioFormat::U24le,
+            crate::AudioFormat::S20be,
+            crate::AudioFormat::S20le,
+            crate::AudioFormat::U20be,
+            crate::AudioFormat::U20le,
+            crate::AudioFormat::S18be,
+            crate::AudioFormat::S18le,
+            crate::AudioFormat::U18be,
+            crate::AudioFormat::U18le,
+            crate::AudioFormat::S16be,
+            crate::AudioFormat::S16le,
+            crate::AudioFormat::U16be,
+            crate::AudioFormat::U16le,
+            crate::AudioFormat::S8,
+            crate::AudioFormat::U8,
         ])
     }
 });
@@ -170,33 +170,33 @@ pub const AUDIO_FORMAT_S8: crate::AudioFormat = crate::AudioFormat::S8;
 pub const AUDIO_FORMAT_U8: crate::AudioFormat = crate::AudioFormat::U8;
 
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_S16: ::AudioFormat = ::AudioFormat::S16be;
+pub const AUDIO_FORMAT_S16: crate::AudioFormat = crate::AudioFormat::S16be;
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_U16: ::AudioFormat = ::AudioFormat::U16be;
+pub const AUDIO_FORMAT_U16: crate::AudioFormat = crate::AudioFormat::U16be;
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_S2432: ::AudioFormat = ::AudioFormat::S2432be;
+pub const AUDIO_FORMAT_S2432: crate::AudioFormat = crate::AudioFormat::S2432be;
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_U2432: ::AudioFormat = ::AudioFormat::U2432be;
+pub const AUDIO_FORMAT_U2432: crate::AudioFormat = crate::AudioFormat::U2432be;
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_S32: ::AudioFormat = ::AudioFormat::S32be;
+pub const AUDIO_FORMAT_S32: crate::AudioFormat = crate::AudioFormat::S32be;
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_U32: ::AudioFormat = ::AudioFormat::U32be;
+pub const AUDIO_FORMAT_U32: crate::AudioFormat = crate::AudioFormat::U32be;
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_S24: ::AudioFormat = ::AudioFormat::S24be;
+pub const AUDIO_FORMAT_S24: crate::AudioFormat = crate::AudioFormat::S24be;
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_U24: ::AudioFormat = ::AudioFormat::U24be;
+pub const AUDIO_FORMAT_U24: crate::AudioFormat = crate::AudioFormat::U24be;
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_S20: ::AudioFormat = ::AudioFormat::S20be;
+pub const AUDIO_FORMAT_S20: crate::AudioFormat = crate::AudioFormat::S20be;
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_U20: ::AudioFormat = ::AudioFormat::U20be;
+pub const AUDIO_FORMAT_U20: crate::AudioFormat = crate::AudioFormat::U20be;
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_S18: ::AudioFormat = ::AudioFormat::S18be;
+pub const AUDIO_FORMAT_S18: crate::AudioFormat = crate::AudioFormat::S18be;
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_U18: ::AudioFormat = ::AudioFormat::U18be;
+pub const AUDIO_FORMAT_U18: crate::AudioFormat = crate::AudioFormat::U18be;
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_F32: ::AudioFormat = ::AudioFormat::F32be;
+pub const AUDIO_FORMAT_F32: crate::AudioFormat = crate::AudioFormat::F32be;
 #[cfg(target_endian = "big")]
-pub const AUDIO_FORMAT_F64: ::AudioFormat = ::AudioFormat::F64be;
+pub const AUDIO_FORMAT_F64: crate::AudioFormat = crate::AudioFormat::F64be;
 
 #[cfg(target_endian = "little")]
 pub const AUDIO_FORMAT_S16: crate::AudioFormat = crate::AudioFormat::S16le;
-- 
GitLab

