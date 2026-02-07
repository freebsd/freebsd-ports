// See https://github.com/rizsotto/Bear/issues/648

--- bear/build.rs.orig	2026-01-17 07:09:18 UTC
+++ bear/build.rs
@@ -25,12 +25,12 @@
 
 /// Default wrapper executable path
 /// Package creators: modify this entire path to change wrapper location
-const DEFAULT_WRAPPER_PATH: &str = "/usr/local/libexec/bear";
+const DEFAULT_WRAPPER_PATH: &str = "/usr/local/lib/bear";
 
 /// Default preload library path
 /// Package creators: modify this entire path to change preload library location
 /// Note: $LIB will be expanded at runtime to the appropriate architecture subdirectory
-const DEFAULT_PRELOAD_PATH: &str = "/usr/local/libexec/bear/$LIB";
+const DEFAULT_PRELOAD_PATH: &str = "/usr/local/lib/bear";
 
 // =============================================================================
 // PLATFORM-SPECIFIC EXECUTABLE AND LIBRARY NAMES (DO NOT CHANGE THESE)
