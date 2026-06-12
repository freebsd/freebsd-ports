--- crates/zed/src/main.rs.orig	2026-06-10 17:21:09 UTC
+++ crates/zed/src/main.rs
@@ -23,6 +23,7 @@ use collections::HashMap;
 use client::{Client, ProxySettings, RefreshLlmTokenListener, UserStore, parse_zed_link};
 use collab_ui::channel_view::ChannelView;
 use collections::HashMap;
+#[cfg(not(target_os = "freebsd"))]
 use crashes::InitCrashHandler;
 use db::kvp::{GlobalKeyValueStore, KeyValueStore};
 use editor::Editor;
@@ -79,7 +80,10 @@ use zed::{
     handle_keymap_file_changes, initialize_workspace, open_paths_with_positions,
 };
 
+#[cfg(not(target_os = "freebsd"))]
 use crate::zed::{CrashHandler, OpenRequestKind, eager_load_active_theme_and_icon_theme};
+#[cfg(target_os = "freebsd")]
+use crate::zed::{OpenRequestKind, eager_load_active_theme_and_icon_theme};
 
 #[cfg(feature = "mimalloc")]
 #[global_allocator]
@@ -215,6 +219,7 @@ fn main() {
     }
 
     // `zed --crash-handler` Makes zed operate in minidump crash handler mode
+    #[cfg(not(target_os = "freebsd"))]
     if let Some(socket) = &args.crash_handler {
         crashes::crash_server(socket.as_path(), paths::logs_dir().clone());
         return;
@@ -384,6 +389,7 @@ fn main() {
     ) || *release_channel::RELEASE_CHANNEL
         != ReleaseChannel::Dev;
 
+    #[cfg(not(target_os = "freebsd"))]
     let crash_handler = if should_install_crash_handler {
         Some(
             app.background_executor().spawn(crashes::init(
@@ -606,6 +612,7 @@ fn main() {
             let telemetry = telemetry.clone();
             move |_, evt: &client::user::Event, cx| match evt {
                 client::user::Event::PrivateUserInfoUpdated => {
+                    #[cfg(not(target_os = "freebsd"))]
                     if let Some(crash_client) = cx.try_global::<CrashHandler>() {
                         crashes::set_user_info(
                             &crash_client.0,
@@ -655,6 +662,7 @@ fn main() {
         auto_update::init(client.clone(), cx);
         dap_adapters::init(cx);
         auto_update_ui::init(cx);
+        #[cfg(not(target_os = "freebsd"))]
         reliability::init(client.clone(), cx);
         extension_host::init(
             extension_host_proxy.clone(),
@@ -847,6 +855,7 @@ fn main() {
         let menus = app_menus(cx);
         cx.set_menus(menus);
 
+        #[cfg(not(target_os = "freebsd"))]
         if let Some(mut crash_handler) = crash_handler {
             let crash_handler2 = block_on(poll_once(&mut crash_handler));
             match crash_handler2 {
