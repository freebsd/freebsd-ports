--- node-clipboard-rs/src/lib.rs.orig	2026-03-04 05:28:38 UTC
+++ node-clipboard-rs/src/lib.rs
@@ -12,7 +12,7 @@ use std::thread;
 use std::sync::OnceLock;
 use std::thread;
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 mod wayland;
 
 pub(crate) fn is_debug_logging_enabled() -> bool {
@@ -39,13 +39,13 @@ macro_rules! listener_log {
   }};
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 fn is_wayland_environment() -> bool {
   wayland::is_wayland_environment()
 }
 
 /// 非 Linux 平台的 Wayland 环境检测（总是返回 false）
-#[cfg(not(target_os = "linux"))]
+#[cfg(not(any(target_os = "linux", target_os = "freebsd")))]
 fn is_wayland_environment() -> bool {
   false
 }
@@ -55,12 +55,12 @@ pub fn is_wayland_clipboard_available() -> bool {
 /// 返回 true 表示当前环境支持 Wayland 剪贴板监听
 #[napi]
 pub fn is_wayland_clipboard_available() -> bool {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   {
     wayland::is_wayland_clipboard_available()
   }
 
-  #[cfg(not(target_os = "linux"))]
+  #[cfg(not(any(target_os = "linux", target_os = "freebsd")))]
   {
     false
   }
@@ -174,7 +174,7 @@ impl ClipboardManager {
   /// 获取剪贴板中的纯文本内容
   #[napi]
   pub fn get_text(&self) -> Result<String> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return wayland::get_text()
         .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get text: {e}")));
@@ -189,7 +189,7 @@ impl ClipboardManager {
   /// 设置剪贴板中的纯文本内容
   #[napi]
   pub fn set_text(&self, text: String) -> Result<()> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return wayland::set_text(text)
         .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to set text: {e}")));
@@ -204,7 +204,7 @@ impl ClipboardManager {
   /// 获取剪贴板中的 HTML 内容
   #[napi]
   pub fn get_html(&self) -> Result<String> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return wayland::get_html()
         .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get HTML: {e}")));
@@ -219,7 +219,7 @@ impl ClipboardManager {
   /// 设置剪贴板中的 HTML 内容
   #[napi]
   pub fn set_html(&self, html: String) -> Result<()> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return wayland::set_html(html)
         .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to set HTML: {e}")));
@@ -234,7 +234,7 @@ impl ClipboardManager {
   /// 获取剪贴板中的富文本内容
   #[napi]
   pub fn get_rich_text(&self) -> Result<String> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return wayland::get_rich_text().map_err(|e| {
         Error::new(
@@ -256,7 +256,7 @@ impl ClipboardManager {
   /// 设置剪贴板中的富文本内容
   #[napi]
   pub fn set_rich_text(&self, text: String) -> Result<()> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return wayland::set_rich_text(text).map_err(|e| {
         Error::new(
@@ -278,7 +278,7 @@ impl ClipboardManager {
   /// 获取剪贴板中的图片数据（以 base64 编码返回）
   #[napi]
   pub fn get_image_base64(&self) -> Result<String> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       let image_data = wayland::get_image_raw()
         .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get image: {e}")))?;
@@ -298,7 +298,7 @@ impl ClipboardManager {
   /// 获取剪贴板中的图片详细信息（包含宽度、高度、大小和原始数据）
   #[napi]
   pub fn get_image_data(&self) -> Result<ImageData> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       let image_data = wayland::get_image_raw()
         .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get image: {e}")))?;
@@ -334,7 +334,7 @@ impl ClipboardManager {
       )
     })?;
 
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       let png_bytes = image_to_png_bytes(&rust_image, "Failed to set image")?;
       return wayland::set_image_raw(png_bytes)
@@ -357,7 +357,7 @@ impl ClipboardManager {
       )
     })?;
 
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       let png_bytes = image_to_png_bytes(&rust_image, "Failed to set image")?;
       return wayland::set_image_raw(png_bytes)
@@ -373,7 +373,7 @@ impl ClipboardManager {
   /// 获取剪贴板中的图片原始数据（Buffer）
   #[napi]
   pub fn get_image_raw(&self) -> Result<Buffer> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       let image_data = wayland::get_image_raw()
         .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get image: {e}")))?;
@@ -393,7 +393,7 @@ impl ClipboardManager {
   /// 获取剪贴板中的文件列表
   #[napi]
   pub fn get_files(&self) -> Result<Vec<String>> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return wayland::get_files()
         .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get files: {e}")));
@@ -408,7 +408,7 @@ impl ClipboardManager {
   /// 设置剪贴板中的文件列表
   #[napi]
   pub fn set_files(&self, files: Vec<String>) -> Result<()> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return wayland::set_files(files)
         .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to set files: {e}")));
@@ -423,7 +423,7 @@ impl ClipboardManager {
   /// 设置剪贴板中的自定义格式数据
   #[napi]
   pub fn set_buffer(&self, format: String, buffer: Buffer) -> Result<()> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return wayland::set_buffer(format, buffer.to_vec())
         .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to set buffer: {e}")));
@@ -438,7 +438,7 @@ impl ClipboardManager {
   /// 获取剪贴板中的自定义格式数据
   #[napi]
   pub fn get_buffer(&self, format: String) -> Result<Buffer> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       let data = wayland::get_buffer(format)
         .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get buffer: {e}")))?;
@@ -455,7 +455,7 @@ impl ClipboardManager {
   /// 设置剪贴板中的复合内容（可同时设置多种格式）
   #[napi]
   pub fn set_contents(&self, contents: ClipboardData) -> Result<()> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return wayland::set_contents(contents).map_err(|e| {
         Error::new(
@@ -522,7 +522,7 @@ impl ClipboardManager {
       }
     };
 
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return wayland::has_format(normalized_format).map_err(|e| {
         Error::new(
@@ -548,7 +548,7 @@ impl ClipboardManager {
   /// 获取剪贴板中所有可用的格式
   #[napi]
   pub fn get_available_formats(&self) -> Result<Vec<String>> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return wayland::get_available_formats().map_err(|e| {
         Error::new(
@@ -570,7 +570,7 @@ impl ClipboardManager {
   /// 清空剪贴板
   #[napi]
   pub fn clear(&self) -> Result<()> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return wayland::clear().map_err(|e| {
         Error::new(
@@ -592,7 +592,7 @@ impl ClipboardManager {
   /// 异步获取剪贴板文本内容
   #[napi]
   pub async fn get_text_async(&self) -> Result<String> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return tokio::task::spawn_blocking(move || {
         wayland::get_text()
@@ -621,7 +621,7 @@ impl ClipboardManager {
   /// 异步设置剪贴板文本内容
   #[napi]
   pub async fn set_text_async(&self, text: String) -> Result<()> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return tokio::task::spawn_blocking(move || {
         wayland::set_text(text)
@@ -650,7 +650,7 @@ impl ClipboardManager {
   /// 异步获取剪贴板图片数据（以 base64 编码返回）
   #[napi]
   pub async fn get_image_base64_async(&self) -> Result<String> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return tokio::task::spawn_blocking(move || {
         let image_data = wayland::get_image_raw()
@@ -683,7 +683,7 @@ impl ClipboardManager {
   /// 异步获取剪贴板图片详细信息（包含宽度、高度、大小和原始数据）
   #[napi]
   pub async fn get_image_data_async(&self) -> Result<ImageData> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     if is_wayland_environment() {
       return tokio::task::spawn_blocking(move || {
         let image_data = wayland::get_image_raw()
@@ -725,7 +725,7 @@ pub fn get_clipboard_text() -> Result<String> {
 /// 快速获取剪贴板文本内容
 #[napi]
 pub fn get_clipboard_text() -> Result<String> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     return wayland::get_text()
       .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get text: {e}")));
@@ -746,7 +746,7 @@ pub fn set_clipboard_text(text: String) -> Result<()> 
 /// 快速设置剪贴板文本内容
 #[napi]
 pub fn set_clipboard_text(text: String) -> Result<()> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     return wayland::set_text(text)
       .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to set text: {e}")));
@@ -767,7 +767,7 @@ pub fn get_clipboard_html() -> Result<String> {
 /// 快速获取剪贴板 HTML 内容
 #[napi]
 pub fn get_clipboard_html() -> Result<String> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     return wayland::get_html()
       .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get HTML: {e}")));
@@ -788,7 +788,7 @@ pub fn set_clipboard_html(html: String) -> Result<()> 
 /// 快速设置剪贴板 HTML 内容
 #[napi]
 pub fn set_clipboard_html(html: String) -> Result<()> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     return wayland::set_html(html)
       .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to set HTML: {e}")));
@@ -809,7 +809,7 @@ pub fn get_clipboard_image() -> Result<String> {
 /// 快速获取剪贴板图片（base64 编码）
 #[napi]
 pub fn get_clipboard_image() -> Result<String> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     let image_data = wayland::get_image_raw()
       .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get image: {e}")))?;
@@ -835,7 +835,7 @@ pub fn get_clipboard_image_data() -> Result<ImageData>
 /// 快速获取剪贴板图片详细信息（包含宽度、高度、大小和原始数据）
 #[napi]
 pub fn get_clipboard_image_data() -> Result<ImageData> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     let image_data = wayland::get_image_raw()
       .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get image: {e}")))?;
@@ -877,7 +877,7 @@ pub fn set_clipboard_image(base64_data: String) -> Res
     )
   })?;
 
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     let png_bytes = image_to_png_bytes(&rust_image, "Failed to set image")?;
     return wayland::set_image_raw(png_bytes)
@@ -906,7 +906,7 @@ pub fn set_clipboard_image_raw(image_data: Buffer) -> 
     )
   })?;
 
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     let png_bytes = image_to_png_bytes(&rust_image, "Failed to set image")?;
     return wayland::set_image_raw(png_bytes)
@@ -928,7 +928,7 @@ pub fn get_clipboard_image_raw() -> Result<Buffer> {
 /// 快速获取剪贴板图片原始数据（Buffer）
 #[napi]
 pub fn get_clipboard_image_raw() -> Result<Buffer> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     let image_data = wayland::get_image_raw()
       .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get image: {e}")))?;
@@ -954,7 +954,7 @@ pub fn set_clipboard_buffer(format: String, buffer: Bu
 /// 快速设置剪贴板自定义格式数据
 #[napi]
 pub fn set_clipboard_buffer(format: String, buffer: Buffer) -> Result<()> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     return wayland::set_buffer(format, buffer.to_vec())
       .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to set buffer: {e}")));
@@ -975,7 +975,7 @@ pub fn get_clipboard_buffer(format: String) -> Result<
 /// 快速获取剪贴板自定义格式数据
 #[napi]
 pub fn get_clipboard_buffer(format: String) -> Result<Buffer> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     let data = wayland::get_buffer(format)
       .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get buffer: {e}")))?;
@@ -998,7 +998,7 @@ pub fn set_clipboard_files(files: Vec<String>) -> Resu
 /// 快速设置剪贴板文件列表
 #[napi]
 pub fn set_clipboard_files(files: Vec<String>) -> Result<()> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     return wayland::set_files(files)
       .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to set files: {e}")));
@@ -1019,7 +1019,7 @@ pub fn get_clipboard_files() -> Result<Vec<String>> {
 /// 快速获取剪贴板文件列表
 #[napi]
 pub fn get_clipboard_files() -> Result<Vec<String>> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     return wayland::get_files()
       .map_err(|e| Error::new(Status::GenericFailure, format!("Failed to get files: {e}")));
@@ -1040,7 +1040,7 @@ pub fn set_clipboard_contents(contents: ClipboardData)
 /// 快速设置剪贴板复合内容（可同时设置多种格式）
 #[napi]
 pub fn set_clipboard_contents(contents: ClipboardData) -> Result<()> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     return wayland::set_contents(contents).map_err(|e| {
       Error::new(
@@ -1099,7 +1099,7 @@ pub fn get_full_clipboard_data() -> Result<ClipboardDa
 /// 快速获取完整的剪贴板数据
 #[napi]
 pub fn get_full_clipboard_data() -> Result<ClipboardData> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     return wayland::get_full_clipboard_data().map_err(|e| {
       Error::new(
@@ -1122,7 +1122,7 @@ pub fn clear_clipboard() -> Result<()> {
 /// 快速清空剪贴板
 #[napi]
 pub fn clear_clipboard() -> Result<()> {
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   if is_wayland_environment() {
     return wayland::clear().map_err(|e| {
       Error::new(
@@ -1219,7 +1219,7 @@ enum ListenerType {
   /// 使用 clipboard_rs 监听器（X11/通用）
   ClipboardRs(clipboard_rs::WatcherShutdown),
   /// 使用 Wayland 专用监听器（仅 Linux）
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   Wayland(std::sync::mpsc::Sender<()>),
 }
 
@@ -1300,7 +1300,7 @@ impl ClipboardListener {
   }
 
   /// 使用 Wayland 专用监听器监听剪贴板变化
-  #[cfg(target_os = "linux")]
+  #[cfg(any(target_os = "linux", target_os = "freebsd"))]
   fn watch_wayland(
     &mut self,
     tsfn: ThreadsafeFunction<ClipboardData, (), ClipboardData, napi::Status, false>,
@@ -1316,7 +1316,7 @@ impl ClipboardListener {
   }
 
   /// 非 Linux 平台的 Wayland 监听器（空实现）
-  #[cfg(not(target_os = "linux"))]
+  #[cfg(not(any(target_os = "linux", target_os = "freebsd")))]
   fn watch_wayland(
     &mut self,
     _tsfn: ThreadsafeFunction<ClipboardData, (), ClipboardData, napi::Status, false>,
@@ -1429,7 +1429,7 @@ impl ClipboardListener {
           listener_log!("stop called for generic listener");
           shutdown.stop();
         }
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "linux", target_os = "freebsd"))]
         ListenerType::Wayland(stop_tx) => {
           listener_log!("stop called for wayland listener");
           if let Err(e) = stop_tx.send(()) {
