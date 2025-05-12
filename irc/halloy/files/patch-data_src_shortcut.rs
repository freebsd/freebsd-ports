--- data/src/shortcut.rs.orig	2025-05-06 21:46:52 UTC
+++ data/src/shortcut.rs
@@ -146,9 +146,7 @@ impl KeyBind {
     default!(toggle_topic, "t", COMMAND | ALT);
     #[cfg(target_os = "macos")]
     default!(toggle_fullscreen, "f", COMMAND | CTRL);
-    #[cfg(target_os = "linux")]
-    default!(toggle_fullscreen, F11);
-    #[cfg(target_os = "windows")]
+    #[cfg(not(target_os = "macos"))]
     default!(toggle_fullscreen, F11);
     default!(command_bar, "k", COMMAND);
     default!(reload_configuration, "r", COMMAND);
