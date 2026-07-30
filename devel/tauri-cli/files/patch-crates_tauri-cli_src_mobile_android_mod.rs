-- Treat FreeBSD like Linux for Android command line tools and default paths.
--- crates/tauri-cli/src/mobile/android/mod.rs.orig	2026-07-01 13:31:26 UTC
+++ crates/tauri-cli/src/mobile/android/mod.rs
@@ -54,7 +54,7 @@ const CMDLINE_TOOLS_URL: &str =
 #[cfg(target_os = "macos")]
 const CMDLINE_TOOLS_URL: &str =
   "https://dl.google.com/android/repository/commandlinetools-mac-13114758_latest.zip";
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 const CMDLINE_TOOLS_URL: &str =
   "https://dl.google.com/android/repository/commandlinetools-linux-13114758_latest.zip";
 #[cfg(windows)]
@@ -475,7 +475,7 @@ fn ensure_java() -> Result<()> {
     let default_java_home = "C:\\Program Files\\Android\\Android Studio\\jbr";
     #[cfg(target_os = "macos")]
     let default_java_home = "/Applications/Android Studio.app/Contents/jbr/Contents/Home";
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     let default_java_home = "/opt/android-studio/jbr";
 
     if Path::new(default_java_home).exists() {
@@ -505,7 +505,7 @@ fn ensure_sdk(non_interactive: bool) -> Result<()> {
 
     #[cfg(target_os = "macos")]
     let default_android_home = dirs::home_dir().unwrap().join("Library/Android/sdk");
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "freebsd"))]
     let default_android_home = dirs::home_dir().unwrap().join("Android/Sdk");
     #[cfg(windows)]
     let default_android_home = dirs::data_local_dir().unwrap().join("Android/Sdk");
