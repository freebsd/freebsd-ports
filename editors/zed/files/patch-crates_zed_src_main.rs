--- crates/zed/src/main.rs.orig	2025-11-27 19:12:04 UTC
+++ crates/zed/src/main.rs
@@ -8,6 +8,7 @@ use collections::HashMap;
 use client::{Client, ProxySettings, UserStore, parse_zed_link};
 use collab_ui::channel_view::ChannelView;
 use collections::HashMap;
+#[cfg(not(target_os = "freebsd"))]
 use crashes::InitCrashHandler;
 use db::kvp::{GLOBAL_KEY_VALUE_STORE, KEY_VALUE_STORE};
 use editor::Editor;
@@ -181,6 +182,7 @@ pub fn main() {
     }
 
     // `zed --crash-handler` Makes zed operate in minidump crash handler mode
+    #[cfg(not(target_os = "freebsd"))]
     if let Some(socket) = &args.crash_handler {
         crashes::crash_server(socket.as_path());
         return;
@@ -291,6 +293,7 @@ pub fn main() {
     let session_id = Uuid::new_v4().to_string();
     let session = app.background_executor().block(Session::new());
 
+    #[cfg(not(target_os = "freebsd"))]
     app.background_executor()
         .spawn(crashes::init(InitCrashHandler {
             session_id: session_id.clone(),
@@ -549,6 +552,7 @@ pub fn main() {
         auto_update::init(client.clone(), cx);
         dap_adapters::init(cx);
         auto_update_ui::init(cx);
+        #[cfg(not(target_os = "freebsd"))]
         reliability::init(client.clone(), cx);
         extension_host::init(
             extension_host_proxy.clone(),
