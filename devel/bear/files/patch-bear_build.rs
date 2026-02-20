// See https://github.com/rizsotto/Bear/issues/648


--- bear/build.rs.orig	2026-02-09 10:13:49 UTC
+++ bear/build.rs
@@ -29,13 +29,13 @@
 ///                   sequence ("C:\Users\..." breaks); use forward slashes
 ///                   ("C:/Users/..."), escaped backslashes ("C:\\Users\\..."),
 ///                   or a raw string literal (r"C:\Users\...")
-const DEFAULT_WRAPPER_PATH: &str = "/usr/local/libexec/bear";
+const DEFAULT_WRAPPER_PATH: &str = "/usr/local/lib/bear";
 
 /// Default preload library path
 /// Package creators: modify this entire path to change preload library location
 /// Note: $LIB will be expanded at runtime to the appropriate architecture subdirectory
 /// Note for Windows: preload isn't supported; feel free to ignore this path
-const DEFAULT_PRELOAD_PATH: &str = "/usr/local/libexec/bear/$LIB";
+const DEFAULT_PRELOAD_PATH: &str = "/usr/local/lib/bear";
 
 // =============================================================================
 // PLATFORM-SPECIFIC EXECUTABLE AND LIBRARY NAMES (DO NOT CHANGE THESE)
