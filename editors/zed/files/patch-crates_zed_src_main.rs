--- crates/zed/src/main.rs.orig	2026-09-04 14:25:12 UTC
+++ crates/zed/src/main.rs
@@ -21,6 +21,7 @@ use collections::HashMap;
 use client::{Client, ProxySettings, RefreshLlmTokenListener, UserStore, parse_zed_link};
 use collab_ui::channel_view::ChannelView;
 use collections::HashMap;
+#[cfg(not(target_os = "freebsd"))]
 use crashes::InitCrashHandler;
 use db::kvp::{GlobalKeyValueStore, KeyValueStore};
 use editor::Editor;
@@ -77,7 +78,10 @@ use zed::{
     handle_keymap_file_changes, initialize_workspace, open_paths_with_positions,
 };
 
+#[cfg(not(target_os = "freebsd"))]
 use crate::zed::{CrashHandler, OpenRequestKind, eager_load_active_theme_and_icon_theme};
+#[cfg(target_os = "freebsd")]
+use crate::zed::{OpenRequestKind, eager_load_active_theme_and_icon_theme};
 
 #[cfg(feature = "mimalloc")]
 #[global_allocator]
@@ -219,6 +223,7 @@ fn main() {
     }
 
     // `zed --crash-handler` Makes zed operate in minidump crash handler mode
+    #[cfg(not(target_os = "freebsd"))]
     if let Some(socket) = &args.crash_handler {
         crashes::crash_server(socket.as_path(), paths::logs_dir().clone());
         return;
@@ -392,6 +397,7 @@ fn main() {
     let should_install_crash_handler =
         client::telemetry::should_install_crash_handler(*release_channel::RELEASE_CHANNEL);
 
+    #[cfg(not(target_os = "freebsd"))]
     let crash_handler = if should_install_crash_handler {
         Some(
             app.background_executor().spawn(crashes::init(
@@ -614,6 +620,7 @@ fn main() {
             let telemetry = telemetry.clone();
             move |_, evt: &client::user::Event, cx| match evt {
                 client::user::Event::PrivateUserInfoUpdated => {
+                    #[cfg(not(target_os = "freebsd"))]
                     if let Some(crash_client) = cx.try_global::<CrashHandler>() {
                         crashes::set_user_info(
                             &crash_client.0,
@@ -663,6 +670,7 @@ fn main() {
         auto_update::init(client.clone(), cx);
         dap_adapters::init(cx);
         auto_update_ui::init(cx);
+        #[cfg(not(target_os = "freebsd"))]
         reliability::init(client.clone(), app_state.workspace_store.clone(), cx);
         extension_host::init(
             extension_host_proxy.clone(),
@@ -732,7 +740,7 @@ fn main() {
         dev_container::init(cx);
 
         load_embedded_fonts(cx);
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "linux", target_os = "freebsd"))]
         prewarm_fonts(cx);
 
         editor::init(cx);
@@ -859,6 +867,7 @@ fn main() {
         let menus = app_menus(cx);
         cx.set_menus(menus);
 
+        #[cfg(not(target_os = "freebsd"))]
         if let Some(mut crash_handler) = crash_handler {
             let crash_handler2 = block_on(poll_once(&mut crash_handler));
             match crash_handler2 {
@@ -1857,7 +1866,7 @@ fn load_embedded_fonts(cx: &App) {
         .unwrap();
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 fn prewarm_fonts(cx: &mut App) {
     let theme_settings = theme::theme_settings(cx);
     let ui_font = theme_settings.ui_font(cx).clone();
