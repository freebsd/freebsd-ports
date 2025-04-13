--- src/api/cover_loader.rs.orig	2025-02-05 10:44:30 UTC
+++ src/api/cover_loader.rs
@@ -22,7 +22,6 @@ use gdk::RGBA;
 use async_compat::CompatExt;
 use futures_util::StreamExt;
 use gdk::RGBA;
-use glycin::Loader;
 use gtk::gio::{Cancelled, File};
 use gtk::graphene::Rect;
 use gtk::prelude::TextureExt;
@@ -88,9 +87,7 @@ impl CoverRequest {
     async fn cover_bytes(&self) -> Result<(gdk::Texture, Vec<u8>)> {
         self.download_tmp_file().compat().await?;
 
-        let loader = Loader::new(self.tmp_file.clone());
-        let image = loader.load().await?;
-        let texture = image.next_frame().await?.texture();
+        let texture = Self::load_texture(&self.tmp_file).await?;
 
         let snapshot = gtk::Snapshot::new();
         snapshot_thumbnail(&snapshot, texture, self.size as f32);
@@ -106,6 +103,18 @@ impl CoverRequest {
 
         let png_bytes = texture.save_to_png_bytes().to_vec();
         Ok((texture, png_bytes))
+    }
+
+    #[cfg(target_os = "linux")]
+    async fn load_texture(file: &gio::File) -> Result<gdk::Texture> {
+        let loader = glycin::Loader::new(file.clone());
+        let image = loader.load().await?;
+        Ok(image.next_frame().await?.texture())
+    }
+
+    #[cfg(target_os = "freebsd")]
+    async fn load_texture(file: &gio::File) -> Result<gdk::Texture> {
+        Ok(gdk::Texture::from_file(file)?)
     }
 
     async fn download_tmp_file(&self) -> Result<()> {
