--- ../sudachi/src/plugin/loader.rs.orig	2024-07-20 17:27:30 UTC
+++ ../sudachi/src/plugin/loader.rs
@@ -52,7 +52,7 @@ struct PluginLoader<'a, 'b, T: PluginCategory + ?Sized
     plugins: Vec<<T as PluginCategory>::BoxType>,
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 fn make_system_specific_name(s: &str) -> String {
     format!("lib{}.so", s)
 }
