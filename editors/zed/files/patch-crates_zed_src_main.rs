--- crates/zed/src/main.rs.orig	2026-03-04 15:41:56 UTC
+++ crates/zed/src/main.rs
@@ -13,6 +13,7 @@ use collections::HashMap;
 use client::{Client, ProxySettings, UserStore, parse_zed_link};
 use collab_ui::channel_view::ChannelView;
 use collections::HashMap;
+#[cfg(not(target_os = "freebsd"))]
 use crashes::InitCrashHandler;
 use db::kvp::{GLOBAL_KEY_VALUE_STORE, KEY_VALUE_STORE};
 use editor::Editor;
@@ -192,6 +193,7 @@ fn main() {
     }
 
     // `zed --crash-handler` Makes zed operate in minidump crash handler mode
+    #[cfg(not(target_os = "freebsd"))]
     if let Some(socket) = &args.crash_handler {
         crashes::crash_server(socket.as_path());
         return;
@@ -332,6 +334,7 @@ fn main() {
         .background_executor()
         .spawn(Session::new(session_id.clone()));
 
+    #[cfg(not(target_os = "freebsd"))]
     crashes::init(
         InitCrashHandler {
             session_id,
@@ -606,6 +609,7 @@ fn main() {
         auto_update::init(client.clone(), cx);
         dap_adapters::init(cx);
         auto_update_ui::init(cx);
+        #[cfg(not(target_os = "freebsd"))]
         reliability::init(client.clone(), cx);
         extension_host::init(
             extension_host_proxy.clone(),
