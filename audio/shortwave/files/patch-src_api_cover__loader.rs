--- src/api/cover_loader.rs.orig	2025-12-24 14:16:03 UTC
+++ src/api/cover_loader.rs
@@ -22,7 +22,6 @@ use glib::clone;
 use futures_util::StreamExt;
 use gdk::RGBA;
 use glib::clone;
-use glycin::Loader;
 use gtk::graphene::Rect;
 use gtk::prelude::TextureExt;
 use gtk::prelude::*;
@@ -67,10 +66,7 @@ impl CoverRequest {
         let data = cacache::read(&*path::CACHE, key).await?;
 
         let bytes = glib::Bytes::from_owned(data);
-        let loader = Loader::for_bytes(&bytes);
-        let image = loader.load_future().await?;
-        let frame = image.next_frame_future().await?;
-        let texture = glycin_gtk4::frame_get_texture(&frame);
+        let texture = Self::texture_from_bytes(&bytes).await?;
 
         Ok(texture)
     }
@@ -80,10 +76,7 @@ impl CoverRequest {
         let body_bytes = response.bytes().await?.to_vec();
 
         let bytes = glib::Bytes::from_owned(body_bytes);
-        let loader = Loader::for_bytes(&bytes);
-        let image = loader.load_future().await?;
-        let frame = image.next_frame_future().await?;
-        let texture = glycin_gtk4::frame_get_texture(&frame);
+        let texture = Self::texture_from_bytes(&bytes).await?;
 
         let snapshot = gtk::Snapshot::new();
         snapshot_thumbnail(&snapshot, texture, self.size as f32);
@@ -116,6 +109,19 @@ impl CoverRequest {
 
         let png_bytes = texture.save_to_png_bytes().to_vec();
         Ok((texture, png_bytes))
+    }
+
+    #[cfg(target_os = "linux")]
+    async fn texture_from_bytes(bytes: &glib::Bytes) -> Result<gdk::Texture> {
+        let loader = glycin::Loader::for_bytes(bytes);
+        let image = loader.load_future().await?;
+        let frame = image.next_frame_future().await?;
+        Ok(glycin_gtk4::frame_get_texture(&frame))
+    }
+
+    #[cfg(not(target_os = "linux"))]
+    async fn texture_from_bytes(bytes: &glib::Bytes) -> Result<gdk::Texture> {
+        Ok(gdk::Texture::from_bytes(bytes)?)
     }
 }
 
